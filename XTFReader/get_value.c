/*--------------------------------------------------------------------
 *    Side scan mosaic:	get_value.c	
 *This code has been taken from MB-System (mb_get_value.c mb_swap.h mb_swap.c)
 *--------------------------------------------------------------------*/
/*
 * mb_get_value.c includes the functions used to get int and double
 * values out of string buffers and the functions used to get
 * values into or out of binary buffers.
 *----------------------------------------------------------------------*/

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "get_value.h"

#ifndef SWAP_H_
#define SWAP_H_
#define swap_short(a) (((a & 0xff) << 8) | ((unsigned short)(a) >> 8))
#define swap_int(a) (((a) << 24) | (((a) << 8) & 0x00ff0000) | (((a) >> 8) & 0x0000ff00) | ((unsigned int)(a) >> 24))
#endif  /* SWAP_H_ */

/* maximum line length in characters */
#define GET_VALUE_MAXLINE 200

static char tmp[GET_VALUE_MAXLINE];

/*--------------------------------------------------------------------*/
/* function swap_check determines if the cpu is byteswapped */
int swap_check() {
	unsigned short testshort = 255;
	char *testchar;
	int byteswapped;
	testchar = (char *)&testshort;
	if (testchar[0] == 0)
		byteswapped = false;
	else
		byteswapped = true;

	return (byteswapped);
}

/*--------------------------------------------------------------------*/
/* function mb_swap_float swaps the bytes of an 4 byte float value */
int swap_float(float *a) {
	unsigned int *t;
	t = (unsigned int *)a;
	*t = swap_int(*t);

	return (SUCCESS);
}

/*--------------------------------------------------------------------*/
/* function mb_swap_double swaps the bytes of an 8 byte double value */
int swap_double(double *a) {
	unsigned char bc[8];
	unsigned char *ac;

	ac = (unsigned char *)a;
	bc[0] = ac[7];
	bc[1] = ac[6];
	bc[2] = ac[5];
	bc[3] = ac[4];
	bc[4] = ac[3];
	bc[5] = ac[2];
	bc[6] = ac[1];
	bc[7] = ac[0];
	ac[0] = bc[0];
	ac[1] = bc[1];
	ac[2] = bc[2];
	ac[3] = bc[3];
	ac[4] = bc[4];
	ac[5] = bc[5];
	ac[6] = bc[6];
	ac[7] = bc[7];

	return (SUCCESS);
}
/*--------------------------------------------------------------------*/
/* function swap_long swaps the bytes of an 8 byte long value */
int swap_long(long long *a) {
	unsigned char bc[8];
	unsigned char *ac;

	ac = (unsigned char *)a;
	bc[0] = ac[7];
	bc[1] = ac[6];
	bc[2] = ac[5];
	bc[3] = ac[4];
	bc[4] = ac[3];
	bc[5] = ac[2];
	bc[6] = ac[1];
	bc[7] = ac[0];
	ac[0] = bc[0];
	ac[1] = bc[1];
	ac[2] = bc[2];
	ac[3] = bc[3];
	ac[4] = bc[4];
	ac[5] = bc[5];
	ac[6] = bc[6];
	ac[7] = bc[7];

	return (SUCCESS);
}


/*--------------------------------------------------------------------*/
/*	function get_double reads a double value from a string.
 */
int get_double(double *value, char *str, int nchar) {
	memset(tmp, 0, GET_VALUE_MAXLINE);
	*value = 0.0;
	*value = atof(strncpy(tmp, str, nchar));
	return (0);
}
/*--------------------------------------------------------------------*/
/*	function get_int reads a int value from a string.
 */
int get_int(int *value, char *str, int nchar) {
	memset(tmp, 0, GET_VALUE_MAXLINE);
	*value = atoi(strncpy(tmp, str, nchar));
	return (0);
}
/*--------------------------------------------------------------------*/
/*	function get_binary_short copies a binary short from
 *	a buffer, swapping if necessary
 */
int get_binary_short(bool swapped, void *buffer, const void *ptr) {
	short *value = (short *)ptr;
	memcpy(value, buffer, sizeof(short));
#ifdef BYTESWAPPED
	if (!swapped)
		*value = swap_short(*((short *)value));
#else
	if (swapped)
		*value = swap_short(*value);
#endif
	return (0);
}
/*--------------------------------------------------------------------*/
/*	function get_binary_int copies a binary int from
 *	a buffer, swapping if necessary
 */
int get_binary_int(bool swapped, void *buffer, const void *ptr) {
	int *value = (int *)ptr;
	memcpy(value, buffer, sizeof(int));
#ifdef BYTESWAPPED
	if (!swapped)
		*value = swap_int(*value);
#else
	if (swapped)
		*value = swap_int(*value);
#endif
	return (0);
}
/*--------------------------------------------------------------------*/
/*	function get_binary_float copies a binary float from
 *	a buffer, swapping if necessary
 */
int get_binary_float(bool swapped, void *buffer, const void *ptr) {
	float *value = (float *)ptr;
	memcpy(value, buffer, sizeof(float));
#ifdef BYTESWAPPED
	if (!swapped)
		swap_float(value);
#else
	if (swapped)
		swap_float(value);
#endif
	return (0);
}
/*--------------------------------------------------------------------*/
/*	function mb_get_binary_double copies a binary double from
 *	a buffer, swapping if necessary
 */
int get_binary_double(bool swapped, void *buffer, const void *ptr) {
	double *value = (double *)ptr;
	memcpy(value, buffer, sizeof(double));
#ifdef BYTESWAPPED
	if (!swapped)
		swap_double(value);
#else
	if (swapped)
		swap_double(value);
#endif
	return (0);
}
/*--------------------------------------------------------------------*/
/*	function get_binary_long copies a binary long from
 *	a buffer, swapping if necessary
 */
int get_binary_long(bool swapped, void *buffer, const void *ptr) {
	long long *value = (long long *)ptr;
	memcpy(value, buffer, sizeof(long long));
#ifdef BYTESWAPPED
	if (!swapped)
		swap_long(value);
#else
	if (swapped)
		swap_long(value);
#endif
	return (0);
}
/*--------------------------------------------------------------------*/
/*	function put_binary_short copies a binary short to
 *	a buffer, swapping if necessary
 */
int put_binary_short(bool swapped, short value, void *buffer) {
#ifdef BYTESWAPPED
	if (!swapped)
		value = swap_short(value);
#else
	if (swapped)
		value = swap_short(value);
#endif
	memcpy(buffer, &value, sizeof(short));
	return (0);
}
/*--------------------------------------------------------------------*/
/*	function put_binary_int copies a binary int to
 *	a buffer, swapping if necessary
 */
int put_binary_int(bool swapped, int value, void *buffer) {
#ifdef BYTESWAPPED
	if (!swapped)
		value = swap_int(value);
#else
	if (swapped)
		value = swap_int(value);
#endif
	memcpy(buffer, &value, sizeof(int));
	return (0);
}
/*--------------------------------------------------------------------*/
/*	function mb_put_binary_float copies a binary float to
 *	a buffer, swapping if necessary
 */
int put_binary_float(bool swapped, float value, void *buffer) {
#ifdef BYTESWAPPED
	if (!swapped)
		swap_float(&value);
#else
	if (swapped)
		swap_float(&value);
#endif
	memcpy(buffer, &value, sizeof(float));
	return (0);
}
/*--------------------------------------------------------------------*/
/*	function mb_put_binary_double copies a binary double to
 *	a buffer, swapping if necessary
 */
int put_binary_double(bool swapped, double value, void *buffer) {
#ifdef BYTESWAPPED
	if (!swapped)
		swap_double(&value);
#else
	if (swapped)
		swap_double(&value);
#endif
	memcpy(buffer, &value, sizeof(double));
	return (0);
}
/*--------------------------------------------------------------------*/
/*	function mb_put_binary_long copies a binary long to
 *	a buffer, swapping if necessary
 */
int put_binary_long(bool swapped, long long value, void *buffer) {
#ifdef BYTESWAPPED
	if (!swapped)
		swap_long(&value);
#else
	if (swapped)
		swap_long(&value);
#endif
	memcpy(buffer, &value, sizeof(long long));
	return (0);
}
/*--------------------------------------------------------------------*/
/*	function get_bounds interprets longitude and
 *	latitude values in decimal degrees and degrees:minutes:seconds
 *	form. This code derives from code in GMT (gmt_init.c).
 */
int get_bounds(char *text, double *bounds) {
	char *result = strtok(text, "/");
	int i = 0;
	while (result && i < 4) {
		bounds[i] = ddmmss_to_degree(result);
		i++;
		result = strtok(NULL, "/");
	}
	int status = SUCCESS;
	if (i == 4)
		status = SUCCESS;
	else
		status = FAILURE;

	return (status);
}
/*--------------------------------------------------------------------*/
/*	function ddmmss_to_degree interprets longitude and
 *	latitude values in decimal degrees and degrees:minutes:seconds
 *	form. This code has been taken from GMT (gmt_init.c).
 */
double ddmmss_to_degree(const char *text) {
	int colons = 0;
	int i = 0;  /* Used after for. */
	for (; text[i]; i++)
		if (text[i] == ':')
			colons++;

	const int suffix = (int)text[i - 1]; /* Last character in string */
	double degfrac;

	if (colons == 2) {         /* dd:mm:ss format */
		double second;
		double degree;
		double minute;
		sscanf(text, "%lf:%lf:%lf", &degree, &minute, &second);
		degfrac = degree + copysign(minute / 60.0 + second / 3600.0, degree);
	}
	else if (colons == 1) { /* dd:mm format */
		double degree;
		double minute;
		sscanf(text, "%lf:%lf", &degree, &minute);
		degfrac = degree + copysign(minute / 60.0, degree);
	}
	else
		degfrac = atof(text);

	if (suffix == 'W' || suffix == 'w' || suffix == 'S' || suffix == 's')
		degfrac = -degfrac; /* Sign was given implicitly */

	return (degfrac);
}
/*--------------------------------------------------------------------*/
