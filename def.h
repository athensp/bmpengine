/* def.h includes global definitions for bitmap editing
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

/** @file def.h
 * 	@brief All library definitions and functions are
 * 	contained here
 * 	This file contains all global definitions
 * 	and the prototypes of the library functions.
 * 	@author Kyriakos Georgiou
 * 	@author Athina Pafitou
 */

#ifndef DEF_H_
#define DEF_H_

// Defining public and private to use on functions
#define PUBLIC
#define PRIVATE static

/* Library Inclusion */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Defining byte , word and dword types */
typedef unsigned char byte;
typedef unsigned short int word;
typedef unsigned int dword;

/* File header definition */
typedef struct {
	byte bfType1, bfType2;
	dword bfSize;
	word bfReserved1;
	word bfReserved2;
	dword bfOffBits;
}__attribute__((packed)) BITMAPFILEHEADER;

/* Info header definition */
typedef struct {
	dword biSize;
	dword biWidth;
	dword biHeight;
	word biPlanes;
	word biBitCount;
	dword biCompression;
	dword biSizeImage;
	dword biXPelsPerMeter;
	dword biYPelsPerMeter;
	dword biClrUsed;
	dword biClrImportant;
}__attribute__((packed)) BITMAPINFOHEADER;

/* Pixel definition consisting of
 * 3 bytes representing red, green and blue colors of a pixel */
typedef struct {
	byte red;
	byte green;
	byte blue;
}__attribute__((packed)) PIXEL;

//********************************************************//
// 				LIBRARY FUNCTIONS BELOW					  //
//********************************************************//

/** @brief This function displays the headers of an image
 *
 * 	The function opens a bitmap image and displays the
 * 	contents of its FILE and INFO header.
 *
 * 	@param *filename The name of the image
 * 	@return EXIT_SUCCESS if the function was successful or EXIT_FAILURE if not
 */
PUBLIC int list(char *filename);

/** @brief This function flips the image horizontally
 *
 * 	The function opens a bitmap image and flips it
 * 	horizontally by changing the position of its pixels
 *
 * 	@param *filename The name of the image
 * 	@return EXIT_SUCCESS if the function was successful or EXIT_FAILURE if not
 */
PUBLIC int hflip(char *filename);

/** @brief This function flips the image vertically
 *
 * 	The function opens a bitmap image and flips the image
 * 	by swapping the pixels of each row of the image
 *
 * 	@param *filename The name of the image
 * 	@return EXIT_SUCCESS if the function was successful or EXIT_FAILURE if not
 *
 */
PUBLIC int vflip(char *filename);

/** @brief This function converts a colored image into grayscale
 *
 * 	The function opens a bitmap image and calculates the
 * 	luminance of each pixel. Then, it sets the red,green and blue
 * 	values of the pixel into the calculated luminance.
 *
 * 	@param *filename The name of the image
 * 	@return EXIT_SUCCESS if the function was successful or EXIT_FAILURE if not
 */
PUBLIC int gray(char *filename);

/** @brief This function rotates an image 90 degrees left
 *
 * 	The function opens a bitmap image and rotates it
 * 	90 degrees left by changing the position of its pixels.
 *
 * 	@param *filename The name of the image
 * 	@return EXIT_SUCCESS if the function was successful or EXIT_FAILURE if not
 */
PUBLIC int left90(char *filename);

/** @brief This function rotates an image 90 degrees right
 *
 * 	The function opens a bitmap image and rotates it 90
 * 	degrees right by changing the position of its pixels.
 *
 * 	@param *filename The name of the image
 * 	@return EXIT_SUCCESS if the function was successful or EXIT_FAILURE if not
 */
PUBLIC int right90(char *filename);

#endif
