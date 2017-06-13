#!/bin/bash

all:
	g++ src/*.cpp -o gidai -Wall -Wextra -pedantic -std=c++11 `mysql_config --cflags --libs`

test:
	g++ src/*.cpp -o gidai -Wall -Wextra -pedantic -std=c++11 `mysql_config --cflags --libs`
	./gidai

clean:
	rm gidai
