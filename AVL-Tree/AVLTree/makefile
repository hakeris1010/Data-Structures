CCP=g++
CC= gcc
LCC=ar

CPPFLAGS= -std=c++11 -c -Wall
CFLAGS= -std=c99 -c -Wall
LDFLAGS=
INCLUDE=-I"src/" -I"include/"
LINKER= -L"lib/"

OBJECTS_LIB= src/TreeImpl/treetools.o src/TreeImpl/treenode.o src/TreeImpl/avltree.o src/Tools/logger.o src/C-Interface/c_avltree.o
OBJECTS_EXE= src/main.o
OBJECTS_EXE_C= test/c_main.o

EXECUTABLE= AVLTreeTest
EXECUTABLE_C= AVLTreeTest_C
LIBRARY= libAVLTreeTest.a
LIBRARY_SIMNAME= $(EXECUTABLE)

%.o: %.cpp
	$(CCP) $(INCLUDE) $(CPPFLAGS) $< -o $@

%.o: %.c
	$(CC) $(INCLUDE) $(CFLAGS) $< -o $@

all: exe_c exe_cpp lib 

exe_c: $(EXECUTABLE_C)
exe_cpp: $(EXECUTABLE)
lib: $(LIBRARY)

$(LIBRARY): $(OBJECTS_LIB)
	$(LCC) rvs lib/$(LIBRARY) $(OBJECTS_LIB)

$(EXECUTABLE_C): $(LIBRARY) $(OBJECTS_EXE_C)
	$(CCP) $(LDFLAGS) $(LINKER) $(OBJECTS_EXE_C) -o $(EXECUTABLE_C) -l$(LIBRARY_SIMNAME)


$(EXECUTABLE): $(LIBRARY) $(OBJECTS_EXE)
	$(CCP) $(LDFLAGS) $(LINKER) $(OBJECTS_EXE) -o $(EXECUTABLE) -l$(LIBRARY_SIMNAME)

clean: clean_o clean_exe_lib

clean_o:
	rm -f *.o */*.o */*/*.o

clean_exe_lib:
	rm -f *.exe *.a */*.exe */*.a

fresh: clean all

fresh_lib: clean lib
fresh_exe_c: clean exe_c
fresh_exe: clean exe