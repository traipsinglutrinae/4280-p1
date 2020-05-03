run: main.o token.o testScanner.o scanner.o
	g++ main.o token.o testScanner.o scanner.o -o scanner -std=c++11

main.o: main.cpp
	g++ -c main.cpp -std=c++11

token.o: token.cpp
	g++ -c token.cpp -std=c++11

testScanner.o: testScanner.cpp
	g++ -c testScanner.cpp -std=c++11

scanner.o: scanner.cpp
	g++ -c scanner.cpp -std=c++11

clean:
	rm -rf *.o scanner
