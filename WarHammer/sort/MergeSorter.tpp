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
 * MergeSorter.tpp
 *
 *  Created on: Oct 5, 2010
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifdef __WarHammer_sort_MERGESORTER_HPP__

template<typename Container, typename Content>
WarHammer::sort::MergeSorter<Container, Content>::MergeSorter(void): WarHammer::sort::Sorter<MergeSorter<Container, Content>, Container, Content>()
{
}

template<typename Container, typename Content>
WarHammer::sort::MergeSorter<Container, Content>::~MergeSorter(void)
{
}

template<typename Container, typename Content>
void WarHammer::sort::MergeSorter<Container, Content>::_merge(Container* container, unsigned int begin, unsigned int end)
{
	if((end - begin) < 2)
			return;

	unsigned int middle = (begin + end) / 2;

	this->_merge(container, begin, middle);
	this->_merge(container, middle + 1, end);

	unsigned int leftIndex = begin, rightIndex = middle + 1, index = 0;
	Content* swapContainer = new Content[end - begin + 1];

	while((leftIndex <= middle) && (rightIndex <= end))
		if(this->_comparator->leftComparison((*container)[rightIndex], (*container)[leftIndex]))
			swapContainer[index++] = (*container)[rightIndex++];
		else
			swapContainer[index++] = (*container)[leftIndex++];

	while(leftIndex <= middle)
		swapContainer[index++] = (*container)[leftIndex++];

	while(rightIndex <= end)
		swapContainer[index++] = (*container)[rightIndex++];

	for(unsigned int i = begin; i <= end; ++i)
		(*container)[i] = swapContainer[i - begin];

	delete[] swapContainer;
}

template<typename Container, typename Content>
void WarHammer::sort::MergeSorter<Container, Content>::_sort(Container* container, unsigned int begin, unsigned int end)
{
	this->_merge(container, begin, end);
}

#endif
