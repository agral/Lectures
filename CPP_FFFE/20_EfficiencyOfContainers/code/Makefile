CC=g++

.PHONY: all clean

all: test_storing

clean:
	@rm -fv test_storing

test_storing: storing.cpp
	$(CC) -std=c++14 -O0 -o test_storing storing.cpp
