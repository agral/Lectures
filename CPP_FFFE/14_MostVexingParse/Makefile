CXX=clang++
DIR_BUILD=build
DIR_SRC=code
CXXFLAGS+=-std=c++20 -O3

all: first second

clean:
	@rm -rfv $(DIR_BUILD)

first:
	$(CXX) $(CXXFLAGS) -g $(DIR_SRC)/first.cpp -o first.out

second:
	$(CXX) $(CXXFLAGS) -g $(DIR_SRC)/second.cpp -o second.out

.PHONY: all clean first second
