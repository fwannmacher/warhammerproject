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
 * Loader.hpp
 *
 *  Created on: Apr 25, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_markuplanguage_LOADER_HPP__
#define __WarHammer_markuplanguage_LOADER_HPP__

#include "IBuilder.hpp"
#include "Container.hpp"
#include "../io/File.hpp"

namespace WarHammer
{
	namespace markuplanguage
	{

		class Loader
		{
		private:
			static const char __ASCII_SPACE,
							  __ASCII_TABULATION,
							  __ASCII_RETURN;
		private:
			unsigned int _currentFileContentIndex;
			WarHammer::util::String _fileContent;
			IBuilder* _builder;
		private:
			void _closeNode(void);
			WarHammer::util::String _loadNode(void);
			void _loadTextNode(WarHammer::util::String parentNodeName);
			void _loadAttribute(void);
			void _loadSpecificNode(void);
			void _loadSpecialNode(void);
			void _loadCDATA(void);
			void _loadDOCTYPE(void);
			void _passComment(void);
		public:
			Loader(IBuilder* builder);
			virtual ~Loader(void);
			WarHammer::util::SmartPointer<Container> load(WarHammer::io::File& xmlFile);
			WarHammer::util::SmartPointer<Container> load(WarHammer::util::String xml);
		};

	}
}

#endif
