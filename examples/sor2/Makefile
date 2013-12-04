PROGRAM = a.out

BCMLIB = ../../lib/libbcm.a
UTIL = ../util

vpath %.cpp $(UTIL)/src

OBJS = main.o Solver.o Timing.o
UTIL_OBJS = ConfigFile.o ConfigBase.o BCMOctree.o

include ../../Makefile.inc

CFLAGS = -I../../include -I$(UTIL)/include $(SILO_INC) $(OPTIONS)

LDFLAGS = 
LIBS = $(BCMLIB) $(SILO_LIB) 

PROGRAM: $(OBJS) $(UTIL_OBJS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $(PROGRAM) $(OBJS) $(UTIL_OBJS) $(LIBS)

.cpp.o:
	$(CXX) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf *.o $(PROGRAM) depend.inc

depend: $(OBJS:.o=.cpp) $(UTIL_OBJS:.o=.cpp)
	@ rm -rf depend.inc
	@ for i in $^; do\
		$(CXX) $(CFLAGS) -MM $$i >> depend.inc;\
	done

-include depend.inc