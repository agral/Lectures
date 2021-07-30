# Makefile rules for building DiplomaPrinter,
#     which is a toy program that generates a nice diploma as a PDF file.
# Created on: 08.07.2021
# Last modified: 08.07.2021
# Author: gralin.ski
# License: CC0

EXE_NAME_DEBUG=DiplomaPrinter
CXX=clang++
CXXFLAGS_BASE=-Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -D_REENTRANT -std=c++2a -O2
CXXFLAGS_CAIRO=$(shell pkg-config --cflags cairo)
CXXFLAGS=$(CXXFLAGS_BASE) $(CXXFLAGS_CAIRO)

LDFLAGS=
LDLIBS_BASE=
LDLIBS_CAIRO=$(shell pkg-config --libs cairo)
LDLIBS=$(LDLIBS_BASE) $(LDLIBS_CAIRO)

DIR_SRC=.
DIR_BIN=bin
DIR_OBJ=$(DIR_BIN)/obj

SOURCES_APP=$(shell find $(DIR_SRC) -name "*.cpp")
OBJECTS_APP=$(patsubst $(DIR_SRC)/%.cpp,$(DIR_OBJ)/%.o,$(SOURCES_APP))

.PHONY: all clean run

all: $(DIR_BIN)/$(EXE_NAME_DEBUG)

clean:
	@rm -fv $(OBJECTS_APP)
	@rm -fv $(DIR_BIN)/$(EXE_NAME_DEBUG)

run: $(DIR_BIN)/$(EXE_NAME_DEBUG)
	@$(DIR_BIN)/$(EXE_NAME_DEBUG)

# Creates an application's executable by linking all the app object files:
$(DIR_BIN)/$(EXE_NAME_DEBUG): $(OBJECTS_APP)
	@mkdir -p $(@D)
	$(CXX) $(LDFLAGS) -o $(DIR_BIN)/$(EXE_NAME_DEBUG) $(OBJECTS_APP) $(LDLIBS)

# Compiles a single file of application's source code to an object file:
$(DIR_OBJ)/%.o: $(DIR_SRC)/%.cpp
	@mkdir -p $(@D)
	$(CXX) -c -g $(CXXFLAGS) $< -o $@

print-%:
	@echo $* = ${$*}
