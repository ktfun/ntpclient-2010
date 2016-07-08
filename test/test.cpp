#include <iostream>
#include <unistd.h>
#include "ntpclient.h"

using namespace std;

typedef struct S_NTP_CLIENT
{
	int cycle_time;
	int debug_on;
	char *hostname;
	int cross_check;
	int set_clock;
	int live;
} NTP_CLIENT;

void *ntp_client_thread(void * void_NTP_CLIENT)
{
	NTP_CLIENT *p_ntp_client = (NTP_CLIENT *)void_NTP_CLIENT;
	
	cout<<"ntp_client_thread --> start"<<endl;
	
	ntp_client_start(p_ntp_client->cycle_time, p_ntp_client->debug_on,
		p_ntp_client->hostname, p_ntp_client->cross_check,
		p_ntp_client->set_clock ,p_ntp_client->live);
		
	cout<<"ntp_client_thread --> end"<<endl;
	
	return (void*)0;
}

int main(int argc, char* argv[])
{
	if ( argc < 2 )
	{
		return 0;
	} 

	//void* ntp_client_start(int cycle_time, int debug_on, char *hostname, int cross_check, int set_clock, int live);
	/* ntpclient -i 15 -d -h 172.16.1.135 -t -s -l */
	cout<<"ntp_client_start --> start"<<endl;
	
	NTP_CLIENT ntp_client;
	ntp_client.cycle_time = 2;
	ntp_client.debug_on = 1;
	ntp_client.hostname = argv[1];
	ntp_client.cross_check = 0;
	ntp_client.set_clock = 1;
	ntp_client.live = 0;
	
	pthread_t ntp_client_tid = 0;
	if(pthread_create(&ntp_client_tid, NULL, ntp_client_thread, (void*)(&ntp_client)) != 0)
	{
		return -1;
	}
	
	cout<<"pthread_create done!\n"<<endl;
	int is_alive;
	
	usleep(1000);
	while(is_client_live())
	{
		usleep(10000);
	}
	
	cout<<"ntp_client_start --> end"<<endl;
	
	cout<<"result -> "<<get_result()<<endl;
	
	return 0;
}
