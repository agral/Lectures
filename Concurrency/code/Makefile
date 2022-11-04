.PHONY: all clean

all: run01 run01bonus run02 run02bonus

clean:
	@rm -fv run01
	@rm -fv run01bonus
	@rm -fv run02
	@rm -fv run02bonus

run01: 01.cpp
	g++ -std=c++20 -Wall -Wextra -Werror -pedantic -g -O3 01.cpp -o run01

run01bonus: 01_sidenote.cpp
	g++ -std=c++20 -Wall -Wextra -Werror -pedantic -g -O3 01_sidenote.cpp -o run01bonus

run02: 02.cpp
	g++ -std=c++20 -Wall -Wextra -Werror -pedantic -g -O3 02.cpp -o run02

run02bonus: 02_sidenote.cpp
	g++ -std=c++20 -Wall -Wextra -Werror -pedantic -g -O0 02_sidenote.cpp -o run02bonus
