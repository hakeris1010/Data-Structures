CCP=g++
CC= gcc
LCC=ar

CPPFLAGS= -std=c++11 -c -Wall
CFLAGS= -std=c99 -c -Wall
LDFLAGS=
INCLUDE=-I/src -I/src/**/ -I/include
LINKER= -L/lib

SOURCES_LIB= src/TreeImpl/*.cpp src/Tools/*.cpp src/C-Interface/*.cpp
SOURCES_EXE= src/main.cpp
SOURCES_EXE_C= test/maintest.c

OBJECTS_LIB=$(SOURCES_LIB:.cpp=.o)
OBJECTS_EXE=$(SOURCES_EXE:.cpp=.o)
OBJECTS_EXE_C=$(SOURCES_EXE_C:.cpp=.o)

EXECUTABLE= AVLTreeTest
EXECUTABLE_C= AVLTreeTest_C
LIBRARY= AVLTreeTest

.o: .cpp
	$(CCP) $(INCLUDE) $(CPPFLAGS) $< -o $@

.o: .c
	$(CC) $(INCLUDE) $(CFLAGS) $< -o $@

all: exe_c exe_cpp lib 

lib: $(OBJECTS_LIB)
	$(LCC) rvs lib/lib$(EXECUTABLE).a $(OBJECTS_LIB)

exe_c: lib $(OBJECTS_EXE_C)
	$(CCP) $(LDFLAGS) $(LINKER) $(OBJECTS_EXE_C) -o $(EXECUTABLE_C) -l$(LIBRARY)


exe_c: lib $(OBJECTS_EXE)
	$(CCP) $(LDFLAGS) $(LINKER) $(OBJECTS_EXE) -o $(EXECUTABLE) -l$(LIBRARY)

clean_o:
	rm -f *.o *.o 

clean_exe_lib:
	rm -f *.exe *.a

clean: clean_o clean_exe_lib

fresh: clean all

fresh_lib: clean lib

fresh_exe_c: clean exe_c

fresh_exe: clean exe