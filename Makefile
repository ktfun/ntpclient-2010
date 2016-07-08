# A long time ago, far, far away, under Solaris, you needed to
#    CFLAGS += -xO2 -Xc
#    LDLIBS += -lnsl -lsocket
# To cross-compile
#    CC = arm-linux-gcc
# To check for lint
#    CFLAGS += -Wpointer-arith -Wcast-align -Wcast-qual -Wshadow -Wundef \
#     -Waggregate-return -Wnested-externs -Winline -Wwrite-strings -Wstrict-prototypes

# This is old-school networking code, making the traditional cast between
# struct sockaddr* and struct sockaddr_in*.  Thus a modern gcc needs:
#CFLAGS += -fno-strict-aliasing

#CFLAGS += -std=c89
#CFLAGS += -W -Wall
#CFLAGS += -O2
#CFLAGS += -DPRECISION_SIOCGSTAMP
#CFLAGS += -DENABLE_DEBUG
#CFLAGS += -DENABLE_REPLAY
# CFLAGS += -DUSE_OBSOLETE_GETTIMEOFDAY

CFLAGS += -fPIC

CC=$(CROSS_COMPILE)gcc 
AR=$(CROSS_COMPILE)ar 

LDFLAGS += -lrt

all: libntpclient.so libntpclient.a

libntpclient.so: ntpclient.o phaselock.o 
	$(CC) -shared -o libntpclient.so ntpclient.o phaselock.o 

libntpclient.a: ntpclient.o phaselock.o 
	$(AR) -rvs libntpclient.a ntpclient.o phaselock.o 
	
ntpclient.o phaselock.o : ntpclient.h

clean:
	rm -f ntpclient adjtimex *.o libntpclient.so libntpclient.a
