run: test.o funkcijos.o
	g++ -o run.exe test.o funkcijos.o -static-libgcc -static-libstdc++

funkcijos.o: funkcijos.cpp struct.h
	g++ -c funkcijos.cpp

test.o: test.cpp struct.h
	g++ -c test.cpp

clean: 
	del *.o