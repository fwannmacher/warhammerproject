/*
 *        M   M  M  MMM                     UUU
 *        M   M M M M M                     U    U   U
 *   WWWW M M M M M MMM                     U   UUU UUU WWWW
 *   WWWW MM MM MMM MM                      U    U   U  WWWW
 *   WW   M   M M M M M       HH HH         UUU           WW
 *   WW                       HH HH                       WW
 *   WW MM  MM   MM   HH      HH HH      HH MMMMMM MMMMMM WW
 *   WW MM  MM   MM   HH      HH HH      HH MMMMMM MMMMMM WW
 *   WW MM  MM MM  MM HHHH  HHHH HHHH  HHHH MM     MM  MM WW
 *   WW MM  MM MM  MM HHHH  HHHH HHHH  HHHH MM     MM  MM WW
 * WW   MMMMMM MM  MM HH  HH  HH HH  HH  HH MMMM   MMMMMM   WW
 * WW   MMMMMM MM  MM HH  HH  HH HH  HH  HH MMMM   MMMMMM   WW
 *   WW MM  MM MMMMMM HH      HH HH      HH MM     MMMM   WW
 *   WW MM  MM MMMMMM HH      HH HH      HH MM     MMMM   WW
 *   WW MM  MM MM  MM HH      HH HH      HH MMMMMM MM  MM WW
 *   WW MM  MM MM  MM HH      HH HH      HH MMMMMM MM  MM WW
 *   WW                       HH HH                       WW
 *   WW                       HH HH                       WW
 *   WWWW                     HH HH                     WWWW
 *   WWWW                     HH HH                     WWWW
 *                            HH HH
 *                            HH HH NNN NNN NNN NNN NNN NNN NNN
 *                            HH HH N N N N N N   N N   N    N
 *                            HH HH NNN NNN N N N N NN  N    N
 *                                  N   NN  N N N N N   N    N
 *                                N N   N N NNN NNN NNN NNN  N
 *
 * sort.cpp
 *
 *  Created on: Aug 08, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#include <iostream>
#include <vector>
#include "../WarHammer/sort/ParallelQuickSorter.hpp"
#include "../WarHammer/sort/util/Comparator.hpp"
#include "../WarHammer/thread/ThreadPool.hpp"

//A function that will be generate the unsorted content for the container
void generateUnsortedContent(std::vector<int>& container)
{
	srand(0);

	for(unsigned int i = 0; i < 20; ++i)
		container.push_back(rand() % 1000);
}

//Show up the content of the container
void showContent(std::vector<int>& container)
{
	for(unsigned int i = 0; i < container.size(); ++i)
		std::cout << container[i] << std::endl;
}

int main(int argc, char** argv)
{
	//Create a container that has the operator [] overload.
	std::vector<int> container;

	//Create a new sorter instance.
	WarHammer::sort::ParallelQuickSorter<std::vector<int>, int> sorter(26, 4);

	//Set the quantity of thread the WarHammer::thread::ThreadPool will handle.
	WarHammer::thread::ThreadPool::Instance()->setNumberOfThreads(2);

	//Populate the container with unsorted content.
	generateUnsortedContent(container);

	std::cout << "Unsorted content:" << std::endl;
	showContent(container);

	//Use the sorter passing the container and the index range you want sort with the wanted method {CRESCENT|DECRESCENT}.
	sorter.sort(&container, 0, container.size() - 1, WarHammer::sort::util::Comparator<int>::DECRESCENT);

	std::cout << "Sorted content:" << std::endl;
	showContent(container);

	return 0;
}
