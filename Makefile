CXX = g++
CFLAGS = -g -Wall -std=c++11
NOMAIN = calc_useful.o chore.o
MAINOBJ = queuemain.o
TESTOBJ = test.o
OBJS = $(MAINOBJ) $(NOMAIN)
TESTOBJS = $(TESTOBJ) $(NOMAIN)

a.out: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $@

$(MAINOBJ): queuemain.cc calc_useful.h chore.h
	$(CXX) $(CFLAGS) -c queuemain.cc -o $@

calc_useful.o: calc_useful.cc calc_useful.h
	$(CXX) $(CFLAGS) -c calc_useful.cc -o $@

chore.o: chore.cc chore.h
	$(CXX) $(CFLAGS) -c chore.cc -o $@


test: $(TESTOBJS)
	$(CXX) $(CFLAGS) $(TESTOBJS) -o $@

$(TESTOBJ): test.cc
	$(CXX) $(CFLAGS) -c test.cc -o $@


clean:
	rm -rf $(NOMAIN) $(MAINOBJ) $(TESTOBJ) a.out test