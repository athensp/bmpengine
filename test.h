/*  test.h including functions to assist testing definitions
 ** Copyright (C) 2012 Kyriakos Georgiou
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/** @file test.h
 * 	@brief It contains functions to assist the program's drivers
 * 	It contains functions to create a new image based on user input
 * 	@author Kyriakos Georgiou
 * 	@bug No known bugs
 *
 */

#ifndef TEST_H_
#define TEST_H_

/*Definition's file inclusion*/
#include "def.h"
#include <math.h> //rand()
#define EXPECTED 1
#define UNEXPECTED 0

/** @brief This function creates a new image File header
 *  This function creates a new file header for an image
 *  based on bytes t1,t2 which represent the image's type
 *  @param t1 Image type 1
 *  @param t2 Image type 2
 *  @param ret A pointer to the file header to return to the calling function
 *  @return EXIT_SUCCESS if successful or EXIT_FAILURE if not
 */
PUBLIC int makeFileH(byte t1, byte t2, BITMAPFILEHEADER *ret);

/** @brief This function creates a new image Info header
 *  This function creates a new info header for an image
 *  based on user input
 *  @param w Image's width
 *  @param h Image's height
 *  @param bitc Image's BitCount
 *  @param comp If the image is compressed or not
 *  @param ret A pointer to the info header to return to the calling image
 *  @return EXIT_SUCCESS if successful or EXIT_FAILURE if not
 */
PUBLIC int makeInfoH(dword w, dword h, word bitc, dword comp,
		BITMAPINFOHEADER *ret);

/** @brief This function creates a new image
 *  This function creates a new image based on info and file headers
 *  based on user input
 *  @param bmf Image's file header
 *  @param bmi Image's info header
 *  @param fn The output file name
 *  @return EXIT_SUCCESS if successful or EXIT_FAILURE if not
 */
PUBLIC int makeImage(char *fn, BITMAPFILEHEADER bmf, BITMAPINFOHEADER bmi);

#endif
