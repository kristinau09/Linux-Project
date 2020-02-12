
 # Filename        Makefile
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

