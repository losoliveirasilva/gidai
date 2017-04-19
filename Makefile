all:
	g++ *.cpp -o agenda -Wall -Wextra -pedantic -std=c++11

clean:
	rm agenda
