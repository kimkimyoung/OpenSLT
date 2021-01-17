/*--------------------------------------------------------------------
 *    Side scan mosaic:	get_value.h	 12/5/2020
 *This code has been taken from MB-System (mb_swap.h mb_swap.c)
 *--------------------------------------------------------------------*/
/*
 * mb_get_value.h includes definitions of the functions used to get int and double
 * values out of string buffers and the functions used to get
 * values into or out of binary buffers.
 *----------------------------------------------------------------------*/
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "status.h"
#include "config.h"

#ifndef SWAP_H_
#define SWAP_H_
#define swap_short(a) (((a & 0xff) << 8) | ((unsigned short)(a) >> 8))
#define swap_int(a) (((a) << 24) | (((a) << 8) & 0x00ff0000) | (((a) >> 8) & 0x0000ff00) | ((unsigned int)(a) >> 24))
#endif  /* SWAP_H_ */

/* maximum line length in characters */
#define GET_VALUE_MAXLINE 200


/*--------------------------------------------------------------------*/
/* function swap_check determines if the cpu is byteswapped */
int swap_check();

/*--------------------------------------------------------------------*/
/* function mb_swap_float swaps the bytes of an 4 byte float value */
int swap_float(float *a);

/*--------------------------------------------------------------------*/
/* function mb_swap_double swaps the bytes of an 8 byte double value */
int swap_double(double *a);
/*--------------------------------------------------------------------*/
/* function swap_long swaps the bytes of an 8 byte long value */
int swap_long(long long *a);

/*--------------------------------------------------------------------*/
/*	function get_double reads a double value from a string.
 */
int get_double(double *value, char *str, int nchar);
/*--------------------------------------------------------------------*/
/*	function get_int reads a int value from a string.
 */
int get_int(int *value, char *str, int nchar);

/*--------------------------------------------------------------------*/
/*	function get_binary_short copies a binary short from
 *	a buffer, swapping if necessary
 */
int get_binary_short(bool swapped, void *buffer, const void *ptr);
/*--------------------------------------------------------------------*/
/*	function get_binary_int copies a binary int from
 *	a buffer, swapping if necessary
 */
int get_binary_int(bool swapped, void *buffer, const void *ptr);
/*--------------------------------------------------------------------*/
/*	function get_binary_float copies a binary float from
 *	a buffer, swapping if necessary
 */
int get_binary_float(bool swapped, void *buffer, const void *ptr);
/*--------------------------------------------------------------------*/
/*	function mb_get_binary_double copies a binary double from
 *	a buffer, swapping if necessary
 */
int get_binary_double(bool swapped, void *buffer, const void *ptr);
/*--------------------------------------------------------------------*/
/*	function get_binary_long copies a binary long from
 *	a buffer, swapping if necessary
 */
int get_binary_long(bool swapped, void *buffer, const void *ptr);

/*--------------------------------------------------------------------*/
/*	function put_binary_short copies a binary short to
 *	a buffer, swapping if necessary
 */
int put_binary_short(bool swapped, short value, void *buffer);

/*--------------------------------------------------------------------*/
/*	function put_binary_int copies a binary int to
 *	a buffer, swapping if necessary
 */
int put_binary_int(bool swapped, int value, void *buffer);

/*--------------------------------------------------------------------*/
/*	function mb_put_binary_float copies a binary float to
 *	a buffer, swapping if necessary
 */
int put_binary_float(bool swapped, float value, void *buffer);

/*--------------------------------------------------------------------*/
/*	function mb_put_binary_double copies a binary double to
 *	a buffer, swapping if necessary
 */
int put_binary_double(bool swapped, double value, void *buffer);

/*--------------------------------------------------------------------*/
/*	function mb_put_binary_long copies a binary long to
 *	a buffer, swapping if necessary
 */
int put_binary_long(bool swapped, long long value, void *buffer);

/*--------------------------------------------------------------------*/
/*	function get_bounds interprets longitude and
 *	latitude values in decimal degrees and degrees:minutes:seconds
 *	form. This code derives from code in GMT (gmt_init.c).
 */
int get_bounds(char *text, double *bounds);

/*--------------------------------------------------------------------*/
/*	function ddmmss_to_degree interprets longitude and
 *	latitude values in decimal degrees and degrees:minutes:seconds
 *	form. This code has been taken from GMT (gmt_init.c).
 */
double ddmmss_to_degree(const char *text);
/*--------------------------------------------------------------------*/


