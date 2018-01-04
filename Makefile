#Makefile variables
CC = g++
LD = $(CC)
CCFLAGS = -Wall -Wno-deprecated --std=c++11 -g -c
LDFLAGS = -Wall --std=c++11 -Wno-deprecated -g
OBJS = SimTest.o Sim.o Stoplight.o LightParser.o ProbabilityParser.o Lane.o 
#SIMDEPS = Lane.cpp LightParser.cpp ProbabilityParser.cpp Random.cpp Section.cpp Sim.cpp Stoplight.cpp Vehicle.cpp 
#############################################################################

# compile main from .o files
main: $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $@

clean: 
	rm main
	rm *.o

# compile o files #
SimTest.o: SimTest.cpp
	$(CC) $(CCFLAGS) $<
	
Sim.o: Sim.cpp Lane.cpp Stoplight.cpp
	$(CC) $(CCFLAGS) $<

Lane.o: Lane.cpp
	$(CC) $(CCFLAGS) $<

LightParser.o: LightParser.cpp
	$(CC) $(CCFLAGS) $<

ProbabilityParser.o: ProbabilityParser.cpp
	$(CC) $(CCFLAGS) $<

Stoplight.o: Stoplight.cpp
	$(CC) $(CCFLAGS) $<

