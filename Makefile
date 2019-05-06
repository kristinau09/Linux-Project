
 # Filename        Makefile
 # Date            05/04/2019
 #* Author          Kristina Upadhaya
 #* Email           kxu160730@utdallas.edu
 #* Course          CS 3377.502
 #* Version         1.0
 #* Copyright 2019, All Rights Reserved
 #* 
 #* Description : Makefile
  
 



CXX = g++
CXXFLAGS =
CPPFLAGS = -Wall -g -I/scratch/perkins/include/
LDFLAGS = -L/scratch/perkins/lib
LDLIBS = -lcdk -lncurses 
EXECFILE = p6

OBJS = cdkMatrix.o binReader.o
 

all: $(EXECFILE)

clean:
	rm -f $(OBJS) $(EXECFILE) *.P *~ \#*


$(EXECFILE): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)

