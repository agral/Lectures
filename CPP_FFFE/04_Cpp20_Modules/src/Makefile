PROGRAM_NAME=a.out

.PHONY: all clean

all: ${PROGRAM_NAME}

clean:
	rm helloworld.pcm
	rm a.out

${PROGRAM_NAME}: helloworld.pcm helloworld.cpp main.cpp
	clang++ -std=c++2a -fprebuilt-module-path=. main.cpp helloworld.cpp

helloworld.pcm: helloworld.cpp
	clang++ -std=c++2a -fimplicit-modules -fimplicit-module-maps -c helloworld.cpp -Xclang -emit-module-interface -o helloworld.pcm
