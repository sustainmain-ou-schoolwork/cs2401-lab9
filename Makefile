CXX = g++
CFLAGS = -g -Wall -std=c++11
NOMAIN = calc_useful.o
MAINOBJ = stackmain.o
TESTOBJ = test.o
OBJS = $(MAINOBJ) $(NOMAIN)
TESTOBJS = $(TESTOBJ) $(NOMAIN)

a.out: $(OBJS) node.h
	$(CXX) $(CFLAGS) $(OBJS) -o $@

$(MAINOBJ): stackmain.cc calc_useful.h
	$(CXX) $(CFLAGS) -c stackmain.cc -o $@

calc_useful.o: calc_useful.cc calc_useful.h
	$(CXX) $(CFLAGS) -c calc_useful.cc -o $@


test: $(TESTOBJS)
	$(CXX) $(CFLAGS) $(TESTOBJS) -o $@

$(TESTOBJ): test.cc
	$(CXX) $(CFLAGS) -c test.cc -o $@


clean:
	rm -rf $(NOMAIN) $(MAINOBJ) $(TESTOBJ) a.out test