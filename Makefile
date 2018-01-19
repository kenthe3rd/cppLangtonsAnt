ants.exe: ant.o menu.o main.o
	g++ -std=c++11 ant.o menu.o main.o -o ants.exe

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

ant.o: ant.cpp ant.hpp
	g++ -std=c++11 -c ant.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c menu.cpp

clean:
	rm *.o ants.exe
