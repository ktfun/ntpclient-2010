#ifndef NTPCLIENT_H
#define NTPCLIENT_H

#include <time.h>

#ifdef __cplusplus
	extern "C" {
#endif

/* when present, debug is a true global */
#ifdef ENABLE_DEBUG
extern int debug;
#else
#define debug 0
#endif

/* global tuning parameter */
extern double min_delay;

/* prototype for function defined in phaselock.c */
int contemplate_data(unsigned int absolute, double skew, double errorbar, int freq);

/* user interface*/
/* ntpclient -i 15 -d -h 172.16.1.135 -t -s -l */
void* ntp_client_start(int cycle_time, int debug_on, char *hostname, int cross_check, int set_clock, int live);

void ntp_client_stop();

int is_client_live();

int get_result();

#ifdef __cplusplus
	}
#endif	

#endif
