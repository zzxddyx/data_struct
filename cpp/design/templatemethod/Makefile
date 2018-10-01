######################################
#
#######################################
#source file
SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))

#target you can change test to what you want
#TARGET  := host_send 
TARGET  := exe

#compile and lib parameter
CC      := gcc
CXX     := g++

#LIBS    := -lusb-1.0 -luvc -lopencv_highgui -lreadline -lopencv_imgcodecs -lopencv_imgproc -lc -lopencv_calib3d  -lopencv_core
#LIBS    := -lusb-1.0 -luvc
LDFLAGS := -L/usr/libx86_64-linux-gnu/  -L/usr/lib/x86_64-linux-gnu -L/usr/local/lib -L.
DEFINES := -fpic -Wl,-rpath=.
INCLUDE := -I. -I./include -I/usr/include/libusb-1.0 -I/usr/local/include
CFLAGS  := -g -Wall -O3 $(DEFINES) $(INCLUDE)
CXXFLAGS:= $(CFLAGS)


#i think you should do anything here
.PHONY : everything objs clean veryclean rebuild

everything : $(TARGET)

all : $(TARGET)

objs : $(OBJS)

rebuild: veryclean everything


clean :
	    rm -rf *.o
		#rm $(TARGET)

veryclean : clean
	    rm -rf $(TARGET)

$(TARGET) : $(OBJS)
	    $(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS) #$(LIBS)
