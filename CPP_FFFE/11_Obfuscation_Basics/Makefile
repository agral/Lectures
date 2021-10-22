all: obfuscated numbers

obfuscated: obfuscated.c
	clang -std=c99 -Wall -Wextra -pedantic obfuscated.c -o out.exe

numbers: numbers.cpp
	clang++ -std=c++2a -Wall -Wextra -pedantic numbers.cpp -o numbers.exe


clean:
	@rm out.exe
	@rm numbers.exe
