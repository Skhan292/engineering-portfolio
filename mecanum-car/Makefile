CXX = g++
CXXFLAGS = -std=c++17 -Wall
LIBS = -lpigpio -pthread
OBJS = main.o Motor.o Car.o
all: car
car: $(OBJS) 
	$(CXX) $(CXXFLAGS) -o car $(OBJS) $(LIBS)
main.o: main.cpp Car.h
Motor.o: Motor.cpp Motor.h
Car.o: Car.cpp Car.h
clean: 
	rm -f *.o car
