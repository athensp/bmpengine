/*  test.c includes functions to assist testing for bmplib.a.
 **
 ** It is used by the drivers of each .c file that are used by bmplib.a.
 **
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

/** 
 *  @file test.c
 *
 * 	@brief It contains the functions to make a new image
 *
 * 	@author Kyriakos Georgiou
 * 
 * 	@bug No known bugs
 */

/* Definition's file inclusion */
#include "test.h"

PUBLIC int makeFileH(byte t1, byte t2, BITMAPFILEHEADER *ret) {

	/* Setting the image's file header values into the ones given
	 * by the user */
	ret->bfType1 = t1;
	ret->bfType2 = t2;
	ret->bfSize = 0;
	ret->bfReserved1 = 0;
	ret->bfReserved2 = 0;
	ret->bfOffBits = 54;

	return EXIT_SUCCESS;
}

PUBLIC int makeInfoH(dword w, dword h, word bitc, dword comp,
		BITMAPINFOHEADER *ret) {

	/* Setting the image's info header values into the ones given by the user */
	ret->biSize = 40;
	ret->biWidth = w;
	ret->biHeight = h;
	ret->biPlanes = 0;
	ret->biBitCount = bitc;
	ret->biCompression = comp;
	ret->biSizeImage = 0;
	ret->biXPelsPerMeter = 0;
	ret->biYPelsPerMeter = 0;
	ret->biClrUsed = 0;
	ret->biClrImportant = 0;

	return EXIT_SUCCESS;
}

PUBLIC int makeImage(char *fn, BITMAPFILEHEADER bmf, BITMAPINFOHEADER bmi) {

	// Pointer to the output image file
	FILE *fp_img = NULL;

	// An integer to represent padding bytes and indices to
	// move through the image's rows and columns
	int padding, i, j;

	// A 2d array to represent the image.
	PIXEL **test_img;

	// A null byte to represent padding.
	byte p = '\0';

	/* Opening the output file */
	if ((fp_img = fopen(fn, "wb")) == NULL ) {
		printf("**Error: Unable to open file %s**\n", fn);
		return EXIT_FAILURE;
	}

	/* Calculating padding */
	padding = 4 - ((bmi.biWidth * sizeof(PIXEL)) % 4);

	/* Setting the image's size */
	bmf.bfSize = (sizeof(bmi) + sizeof(bmf)
			+ (sizeof(PIXEL) * bmi.biHeight * bmi.biWidth));
	if (padding < 4) {
		bmf.bfSize += (bmi.biHeight * padding);
	}
	/* Writing the image's headers with a validation check */
	if ((fwrite(&bmf, sizeof(BITMAPFILEHEADER), 1, fp_img)) < 1) {
		printf("**Error: Data omissions while writing in file %s**\n", fn);
		fclose(fp_img);
		return EXIT_FAILURE;
	}
	if ((fwrite(&bmi, sizeof(BITMAPINFOHEADER), 1, fp_img)) < 1) {
		printf("**Error: Data omissions while writing in file %s**\n", fn);
		fclose(fp_img);
		return EXIT_FAILURE;
	}
	/* Allocating space for the image array */
	if ((test_img = (PIXEL **) malloc(sizeof(PIXEL*) * bmi.biHeight)) == NULL ) {
		printf("**Error: Memory allocation error**\n");
		return EXIT_FAILURE;
	}
	for (i = 0; i < bmi.biHeight; i++) {
		/* Allocating memory for each row of the image */
		if ((test_img[i] = (PIXEL *) malloc(sizeof(PIXEL) * bmi.biWidth))
				== NULL ) {
			printf("**Error: Memory allocation error**\n");
			return EXIT_FAILURE;
		}
		
		/* Setting random values into the image's pixels
		 * by giving red , green , and blue bytes a random value
		 * between 0-255.*/
		for (j = 0; j < bmi.biWidth; j++) {
			test_img[i][j].red = rand() & 255;
			test_img[i][j].green = rand() & 255;
			test_img[i][j].blue = rand() & 255;
		}
		
		/* Writing each image row with a validation check */
		fwrite(test_img[i], sizeof(PIXEL), bmi.biWidth, fp_img);
		
		/* Placing padding into the new image */
		if (padding < 4) {
			if ((fwrite(&p, sizeof(byte), padding, fp_img)) < padding) {
				;
				printf("**Error: Data omissions while creating image %s**\n",
						fn);
				fclose(fp_img);
				return EXIT_FAILURE;
			}
		}

	}

	/* Closing the output file */
	fclose(fp_img);
	
	/* Free memory previously allocated */
	for (i = 0; i < bmi.biHeight; i++) {
		free(test_img[i]);
	}

	free(test_img);

	return EXIT_SUCCESS;
}
