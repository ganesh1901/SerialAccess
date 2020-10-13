###############  Example Makefile and example application  ######################################
#Build Revision : 
#Build Date : 
#Change Log : 
#Build By   : Ganesh 
#Revised By :
############################################################################################################################

EXE = bin/SerialScan
SRCS = src/SerialAccess.cpp
OBJ =  obj/SerialAccess.o
LOCAL_INCLUDES = includes/
LOCAL_LIBS =  libs/ -lSerialDevice

INCLUDES = -I$(LOCAL_INCLUDES) 
CC = gcc
CXX = g++ 
STRIP = strip
CFLAGS = $(include_dirs) -g -Wall -D_GCC=1 -O2 -std=c++11
LIBS= 

$(EXE):	$(SRCS)
	$(CXX) $(CFLAGS) $(SRCS) $(INCLUDES) -L $(LOCAL_LIBS) $(LIBS) -o $(EXE) -DDEBUG 
	$(STRIP) $(EXE)

.PHONY : clean
clean :
	rm -f  $(EXE) obj/*.o
