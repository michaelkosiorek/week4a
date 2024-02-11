CXX       = g++
CXXFLAGS  = -Wall -g

test_stack: stack_1.o stack_unit_tests.o
	$(CXX) $(CXXFLAGS) -o $@ $^

test_queue: queue_1.o queue_unit_tests.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o test_stack test_queue

.PHONY: all clean