# This is the Makefile of Building Simulation

CXX = g++

CXXFLAGS = -Wall -I. -std=c++11	

PROGRAM = building_sim

OBJS = function.o main.o 

$(PROGRAM): clean $(OBJS)
	$(CXX) $(OBJS) -o $(PROGRAM)

run: $(PROGRAM)							# Run with default arguments
	./$(PROGRAM) 10 10 10 10 10

clean: 
	rm -f $(PROGRAM) $(OBJS)