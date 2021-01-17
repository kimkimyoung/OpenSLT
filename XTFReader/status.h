/*--------------------------------------------------------------------
 *    Side scan mosaic:	status.h	 12/5/2020
 *This code is taken from MB-System (mb_status.h)
 *--------------------------------------------------------------------*/
/*
 * status.h defines version, status and error codes used
 * by side scan mosaic functions and programs
 *----------------------------------------------------------------------*/

#ifndef STATUS_H_
#define STATUS_H_


/* function status convention */
#define SUCCESS 1
#define FAILURE 0

/* function fatal error values */
#define ERROR_NO_ERROR 20
#define ERROR_MEMORY_FAIL 21
#define ERROR_OPEN_FAIL 2
#define ERROR_BAD_FORMAT 3
#define ERROR_EOF 4
#define ERROR_WRITE_FAIL 5
#define ERROR_NONE_IN_BOUNDS 6
#define ERROR_NONE_IN_TIME 7
#define ERROR_BAD_DESCRIPTOR 8
#define ERROR_BAD_USAGE 9
#define ERROR_NO_PINGS_BINNED 10
#define ERROR_BAD_KIND 11
#define ERROR_BAD_PARAMETER 12
#define ERROR_BAD_BUFFER_ID 13
#define ERROR_BAD_SYSTEM 14
#define ERROR_BAD_DATA 15
#define ERROR_MISSING_DATA 16
#define ERROR_BAD_TIME 17

/* function nonfatal error values */
#define ERROR_TIME_GAP -1
#define ERROR_OUT_BOUNDS -2
#define ERROR_OUT_TIME -3
#define ERROR_SPEED_TOO_SMALL -4
#define ERROR_COMMENT -5
#define ERROR_SUBBOTTOM -6
#define ERROR_WATER_COLUMN -7
#define ERROR_OTHER -8
#define ERROR_UNINTELLIGIBLE -9
#define ERROR_IGNORE -10
#define ERROR_NO_DATA_REQUESTED -11
#define ERROR_BUFFER_FULL -12
#define ERROR_NO_DATA_LOADED -13
#define ERROR_BUFFER_EMPTY -14
#define ERROR_NO_DATA_DUMPED -15
#define ERROR_NO_MORE_DATA -16
#define ERROR_DATA_NOT_INSERTED -17
#define ERROR_BAD_PROJECTION -18
#define ERROR_MISSING_PROJECTIONS -19
#define ERROR_MISSING_NAVATTITUDE -20
#define ERROR_NOT_ENOUGH_DATA -21
#define ERROR_FILE_NOT_FOUND -22
#define ERROR_FILE_LOCKED -23
#define ERROR_INIT_FAIL -24
#define ERROR_SIDESCAN_IGNORED -25

/*problem values */
#define PROBLEM_MAX 6
#define PROBLEM_NO_DATA 1
#define PROBLEM_ZERO_NAV 2
#define PROBLEM_TOO_FAST 3
#define PROBLEM_AVG_TOO_FAST 4
#define PROBLEM_TOO_DEEP 5
#define PROBLEM_BAD_DATAGRAM 6



#endif  /* STATUS_H_ */
