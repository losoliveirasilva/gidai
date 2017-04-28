all:
	g++ src/*.cpp -o gidai -Wall -Wextra -pedantic -std=c++11

test:
	g++ src/*.cpp -o gidai -Wall -Wextra -pedantic -std=c++11
	./gidai

clean:
	rm gidai
