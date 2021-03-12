hwk5: main.o crew.o plane.o flight.o crews.o planes.o flights.o pilot.o copilot.o cabcrew.o
	g++ -std=c++11 -o hwk5 main.o crew.o plane.o flight.o crews.o planes.o flights.o pilot.o copilot.o cabcrew.o

main.o: main.cpp crew.h plane.h flight.h crews.h planes.h flights.h pilot.h copilot.h cabcrew.h
	g++ -std=c++11 -c main.cpp

crew.o: crew.cpp crew.h
	g++ -std=c++11 -c crew.cpp
	
pilot.o: pilot.cpp pilot.h
	g++ -std=c++11 -c pilot.cpp
	
copilot.o: copilot.cpp copilot.h
	g++ -std=c++11 -c copilot.cpp
	
cabcrew.o: cabcrew.cpp cabcrew.h
	g++ -std=c++11 -c cabcrew.cpp

plane.o: plane.cpp plane.h
	g++ -std=c++11 -c plane.cpp

flight.o: flight.cpp flight.h
	g++ -std=c++11 -c flight.cpp

crews.o: crews.cpp crews.h
	g++ -std=c++11 -c crews.cpp

planes.o: planes.cpp planes.h
	g++ -std=c++11 -c planes.cpp

flights.o: flights.cpp flights.h crews.h planes.h
	g++ -std=c++11 -c flights.cpp

clean: 
	rm *.o
	rm hwk5

run:
	./hwk5
