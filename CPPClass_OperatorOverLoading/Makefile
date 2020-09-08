pex3: main.o MySet.o
	g++ main.o MySet.o -o pex3

main.o: main.cpp MySet.h
	g++ -c main.cpp

MySet.o: MySet.cpp MySet.h
	g++ -c MySet.cpp

clean:
	rm *.o pex3
