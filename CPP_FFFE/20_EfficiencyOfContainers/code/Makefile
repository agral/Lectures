CC=g++
STANDARD=c++20

.PHONY: all clean

all: test_storing test_reading_random test_reading_sequential test_vector_or_hashset

clean:
	@rm -fv test_storing
	@rm -fv test_reading_random
	@rm -fv test_reading_sequential
	@rm -fv test_vector_or_hashset

test_storing: storing.cpp
	$(CC) -std=$(STANDARD) -O0 -o test_storing storing.cpp

test_reading_random: reading_random.cpp
	$(CC) -std=$(STANDARD) -O0 -o test_reading_random reading_random.cpp

test_reading_sequential: reading_sequential.cpp
	$(CC) -std=$(STANDARD) -O0 -o test_reading_sequential reading_sequential.cpp

test_vector_or_hashset: vector_or_hashset.cpp
	$(CC) -std=$(STANDARD) -O0 -o test_vector_or_hashset vector_or_hashset.cpp
