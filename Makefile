go: main.o states.o viterbi.o
	g++ -o go main.o states.o viterbi.o

main.o: main.cpp
	g++ -c main.cpp

states.o: states.cpp
	g++ -c states.cpp

viterbi.o: viterbi.cpp
	g++ -c viterbi.cpp

clean:
	-rm *.o go
