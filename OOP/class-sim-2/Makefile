# This is the Makefile of Building Simulation

CXX = g++

CXXFLAGS = -Wall -I. -std=c++11	

PROGRAM = class_sim

OBJS = class2.o main2.o 

$(PROGRAM): clean $(OBJS)
	$(CXX) $(OBJS) -o $(PROGRAM)

run: $(PROGRAM)							# Run with default arguments
	./$(PROGRAM) 10 10 10 10 10

clean: 
	rm -f $(PROGRAM) $(OBJS)