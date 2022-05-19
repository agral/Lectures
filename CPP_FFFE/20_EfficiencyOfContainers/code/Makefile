CC=g++
STANDARD=c++20

.PHONY: all clean

all: test_storing test_reading_random

clean:
	@rm -fv test_storing
	@rm -fv test_reading_random

test_storing: storing.cpp
	$(CC) -std=$(STANDARD) -O0 -o test_storing storing.cpp

test_reading_random: reading_random.cpp
	$(CC) -std=$(STANDARD) -O0 -o test_reading_random reading_random.cpp
