
CC := g++
CFLAGS := -fPIC -g -c -Wall
FOPEN := -fopenmp

# Get the list of cpp files
CPP_SRC_FILES := $(wildcard *.cpp)
CPP_SRC_FILES := $(filter-out SetSeed.cpp, $(CPP_SRC_FILES))
DOT_O_FILES := $(patsubst %.cpp,%.o,$(CPP_SRC_FILES))


all: PathToBoundsAndSeed.hpp SetSeed genz libVineCPP.so.1.0

PathToBoundsAndSeed.hpp:
	echo "#define PathBounds \"`pwd`/bounds.txt\" \n#define PathSeed \"`pwd`/Seed.dat\"\n"  >> PathToBoundsAndSeed.hpp

SetSeed: SetSeed.cpp
	${CC} SetSeed.cpp -o SetSeed

genz: mvtdstpack.o

mvtdstpack.o: mvtdstpack.f
	gfortran ${CFLAGS} mvtdstpack.f

mvtdstpack.f:
	wget http://www.math.wsu.edu/faculty/genz/software/fort77/mvtdstpack.f

%.o: %.cpp
	${CC} ${CFLAGS} $< ${FOPEN}

libVineCPP.so.1.0: ${DOT_O_FILES} mvtdstpack.o
	${CC} -shared -Wl,-soname,libVineCPP.so.1 -o $@ mvtdstpack.o ${DOT_O_FILES}

clean:
	rm *.o && rm libVineCPP.so.1.0 && rm SetSeed && rm PathToBoundsAndSeed.hpp
