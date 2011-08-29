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
 * FileException.cpp
 *
 *  Created on: Aug 02, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#include "FileException.hpp"
#include "../../exception/util/ExceptionIdentificationGenerator.hpp"

const unsigned int WarHammer::io::exception::FileException::OPEN_ERROR = WarHammer::exception::util::ExceptionIdentificationGenerator::Instance()->generateIdentification();
const unsigned int WarHammer::io::exception::FileException::READ_ERROR = WarHammer::exception::util::ExceptionIdentificationGenerator::Instance()->generateIdentification();
const unsigned int WarHammer::io::exception::FileException::INVALID_NAME = WarHammer::exception::util::ExceptionIdentificationGenerator::Instance()->generateIdentification();
const unsigned int WarHammer::io::exception::FileException::CLOSE_ERROR = WarHammer::exception::util::ExceptionIdentificationGenerator::Instance()->generateIdentification();
const unsigned int WarHammer::io::exception::FileException::CLOSED = WarHammer::exception::util::ExceptionIdentificationGenerator::Instance()->generateIdentification();
const unsigned int WarHammer::io::exception::FileException::FLUSH_ERROR = WarHammer::exception::util::ExceptionIdentificationGenerator::Instance()->generateIdentification();
const unsigned int WarHammer::io::exception::FileException::WRITE_ERROR = WarHammer::exception::util::ExceptionIdentificationGenerator::Instance()->generateIdentification();
const unsigned int WarHammer::io::exception::FileException::READ_MODE_ERROR = WarHammer::exception::util::ExceptionIdentificationGenerator::Instance()->generateIdentification();
const unsigned int WarHammer::io::exception::FileException::WRITE_MODE_ERROR = WarHammer::exception::util::ExceptionIdentificationGenerator::Instance()->generateIdentification();
const unsigned int WarHammer::io::exception::FileException::END_OF_FILE = WarHammer::exception::util::ExceptionIdentificationGenerator::Instance()->generateIdentification();
