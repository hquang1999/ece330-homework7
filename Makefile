go: main.o states.cpp
	g++ -o go main.o states.o

main.o: main.cpp
	g++ -c main.cpp

states.o: states.cpp
	g++ -c states.cpp

clean:
	-rm *.o go
