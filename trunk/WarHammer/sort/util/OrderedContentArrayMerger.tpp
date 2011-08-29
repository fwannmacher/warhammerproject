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
 * OrderedContentArrayMerger.tpp
 *
 *  Created on: Oct 31, 2010
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifdef __WarHammer_sort_util_ORDEREDCONTENTARRAYMERGER_HPP__

template<typename Content>
WarHammer::sort::util::OrderedContentArrayMerger<Content>::OrderedContentArrayMerger(void)
{
}

template<typename Content>
WarHammer::sort::util::OrderedContentArrayMerger<Content>::~OrderedContentArrayMerger(void)
{
}

template<typename Content>
void WarHammer::sort::util::OrderedContentArrayMerger<Content>::mergeOrderedContentArrays(Content* container, Content* swapContainer, std::pair<unsigned int, unsigned int>* firstContainerDelimiter, std::pair<unsigned int, unsigned int>* secondContainerDelimiter, unsigned int begin, unsigned int end, Comparator<Content>* comparator)
{
	unsigned int firstContainerIndex = firstContainerDelimiter->first,
				 secondContainerIndex = secondContainerDelimiter->first,
				 containerIndex = 0,
				 swapContanierIndex = 0;
	std::pair<unsigned int, unsigned int>* containerDelimiter = NULL;

	for(swapContanierIndex = begin; swapContanierIndex <= end; ++swapContanierIndex)
	{
		if(comparator->leftComparison(container[firstContainerIndex], container[secondContainerIndex]))
		{
			swapContainer[swapContanierIndex] = container[firstContainerIndex++];

			if(firstContainerIndex > firstContainerDelimiter->second)
			{
				containerIndex = secondContainerIndex;
				containerDelimiter = secondContainerDelimiter;
				break;
			}
		}
		else
		{
			swapContainer[swapContanierIndex] = container[secondContainerIndex++];

			if(secondContainerIndex > secondContainerDelimiter->second)
			{
				containerIndex = firstContainerIndex;
				containerDelimiter = firstContainerDelimiter;
				break;
			}
		}
	}

	for(unsigned int i = swapContanierIndex + 1, j = containerIndex; j <= containerDelimiter->second; ++i, ++j)
		swapContainer[i] = container[j];
}

#endif
