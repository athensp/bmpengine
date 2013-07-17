/*  main.c Client module to call functions from bmplib.a
 **
 ** Copyright (C) 2012 Athina Paphitou
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
 *  @file main.c
 *
 *  @brief The client that calls the library functions
 *
 *  @author Kyriakos Georgiou
 *  @author Athina Pafitou
 *
 *  @bug No known bugs
 */

/*Definitions' file inclusion*/
#include "def.h"

/** @brief The main "client" function of the library
 *  @param argc The number of arguments given by the user
 *  @param argv The arguments given by the user
 *  @return EXIT_SUCCESS if completed successfully or
 *          EXIT_FAILURE if not
 */
int main(int argc, char *argv[]) {

	// Index to go through the loops.
	int i = 0;

	printf(
			"\n######################################################################\n");
	printf(
			"# bmpengine  Copyright (C) 2012  Kyriakos Georgiou & Athina Paphitou #\n"
			"# This program comes with ABSOLUTELY NO WARRANTY.                    #\n"
			"# This is free software, and you are welcome to redistribute it      #\n"
			"# under certain conditions.                                          #\n");
	printf(
			"######################################################################\n");

	if (argc < 2) {
		printf("\nPlease type ./bmpengine --help to see the available options\n");
		return EXIT_SUCCESS;
	}

	/* Display a help menu if the user typed "--help" */
	if (strcmp(argv[1], "--help") == 0) {
		printf(
				"\n======================================================================\n");
		printf("HELP MENU\n");
		printf("---------\n");
		printf("- List of available options:\n");
		printf("1.To view a picture's metadata please type -list [image(s)]\n");
		printf(
				"2.To flip a picture horizontally please type -hflip [image(s)]\n");
		printf("3.To flip a picture verically please type -vflip [image(s)]\n");
		printf(
				"4.To rotate a picture 90 degrees left please type -left90 [image(s)]\n");
		printf(
				"5.To rotate a picture 90 degrees right please type -right90 [image(s)]\n");
		printf(
				"6.To turn a picture into grayscale please type -gray [image(s)]\n");
		printf(
				"-----------------------------------------------------------------\n");
		printf("- Please note that the correct way to use the program is:\n");
		printf("./bmpengine <option> <image1> <image2> etc.\n");
		printf(
				"- Warning: You have to input ONLY ONE option and AT LEAST ONE image.\n");
		printf("- e.g ./bmpengine -list image1.bmp image2.bmp\n");
		printf(
				"======================================================================\n");
		return EXIT_SUCCESS;
	}

	/* Checking to see if the user has given at least one option and
	 * one image.*/
	if (argc < 3) {
		printf(
				"**Error : Give one option and at least one image!**\n"
						"**Please type ./bmpengine --help to see the available options**\n");
		return EXIT_FAILURE;
	}

	/* The client calls each function according to the command
	 * given by the user.*/
	if (strcmp(argv[1], "-list") == 0) {
		for (i = 2; i < argc; i++) {
			list(argv[i]);
		}
		return EXIT_SUCCESS;
	}
	if (strcmp(argv[1], "-hflip") == 0) {
		for (i = 2; i < argc; i++) {
			hflip(argv[i]);
		}
		return EXIT_SUCCESS;
	}
	if (strcmp(argv[1], "-vflip") == 0) {
		for (i = 2; i < argc; i++) {
			vflip(argv[i]);
		}
		return EXIT_SUCCESS;
	}
	if (strcmp(argv[1], "-right90") == 0) {
		for (i = 2; i < argc; i++) {
			right90(argv[i]);
		}
		return EXIT_SUCCESS;
	}
	if (strcmp(argv[1], "-left90") == 0) {
		for (i = 2; i < argc; i++) {
			left90(argv[i]);
		}
		return EXIT_SUCCESS;
	}
	if (strcmp(argv[1], "-gray") == 0) {
		for (i = 2; i < argc; i++) {
			gray(argv[i]);
		}
		return EXIT_SUCCESS;
	}
	/* In case of an invalid command the options are displayed */
	else {
		printf("Error: Invalid command given.\n"
				"Please type ./bmpengine --help to see the available options.\n");
		;
	}

	return EXIT_FAILURE;
}
