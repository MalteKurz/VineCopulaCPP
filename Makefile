
# Get the current directory and setting a compiler option for echo
ifeq ($(OS),Windows_NT)
	currentdir = pwd -W
	ECHO = echo -e
	SharedLibName = libVineCopulaCPP.dll
	OperatingSystem = Windows
else
	currentdir = pwd
	ECHO = echo
	SharedLibName = libVineCopulaCPP.so.1.0
	OperatingSystem = Linux
endif

# Directories
prefix = /usr
exec_prefix = $(prefix)

# Include and library directories
includedir = $(prefix)/include
libdir = $(exec_prefix)/lib
oldincludedir = $(includedir)

# Get directories for dependend software
# Boost libraries
boostdir = $(libdir)
boostincludedir = $(boostdir)/include
boostlibdir = $(boostdir)/lib

# NLopt
nloptdir = $(prefix)
nloptincludedir = $(nloptdir)/include
nloptlibdir = $(nloptdir)/lib

INCLUDE_DIRS := -I$(boostincludedir) -I$(nloptlibdir)
LIB_DIRS := -L$(nloptlibdir)


CC = g++
CFLAGS = -fPIC -g -c -Wall
FOPEN = -fopenmp

# Get the list of cpp files
CPP_SRC_FILES := $(wildcard *.cpp)
CPP_SRC_FILES := $(CPP_SRC_FILES)
DOT_O_FILES := $(patsubst %.cpp,%.o,$(CPP_SRC_FILES))


all: genz $(SharedLibName)

genz: mvtdstpack.o

mvtdstpack.o: mvtdstpack.f
	gfortran ${CFLAGS} mvtdstpack.f

mvtdstpack.f:
	wget http://www.math.wsu.edu/faculty/genz/software/fort77/mvtdstpack.f

%.o: %.cpp
	${CC} ${INCLUDE_DIRS} ${CFLAGS} $< ${FOPEN}

libVineCopulaCPP.so.1.0: ${DOT_O_FILES} mvtdstpack.o
	${CC} ${INCLUDE_DIRS} -shared -Wl,-soname,libVineCopulaCPP.so.1 -o $@ mvtdstpack.o ${DOT_O_FILES}

libVineCopulaCPP.dll: ${DOT_O_FILES} mvtdstpack.o
	${CC} ${INCLUDE_DIRS} ${LIB_DIRS} -shared -o $@ mvtdstpack.o ${DOT_O_FILES} -Wl,--out-implib,libVineCopulaCPP.dll.a ${FOPEN} -lnlopt -lgfortran

install: $(OperatingSystem)Install
	cp VineCopulaCPP_header.hpp $(includedir)/
	cp VineCopulaCPP_helper.hpp $(includedir)/
	cp VineCopulaCPP_PC.hpp $(includedir)/

LinuxInstall:
	cp libVineCopulaCPP.so.1.0 $(libdir)/
	ln -sf $(libdir)/libVineCopulaCPP.so.1.0 $(libdir)/libVineCopulaCPP.so.1
	ln -sf $(libdir)/libVineCopulaCPP.so.1.0 $(libdir)/libVineCopulaCPP.so

WindowsInstall:
	cp libVineCopulaCPP.dll $(libdir)/

clean: $(OperatingSystem)Clean
	rm *.o

LinuxClean:
	rm libVineCopulaCPP.so.1.0

WindowsClean:
	rm SetSeed.exe
	rm libVineCopulaCPP.dll.a
	rm libVineCopulaCPP.dll

uninstall: $(OperatingSystem)Uninstall
	rm $(includedir)/VineCopulaCPP_header.hpp
	rm $(includedir)/VineCopulaCPP_helper.hpp
	rm $(includedir)/VineCopulaCPP_PC.hpp

LinuxUninstall:
	rm $(libdir)/libVineCopulaCPP.so.1.0
	rm $(libdir)/libVineCopulaCPP.so.1
	rm $(libdir)/libVineCopulaCPP.so

WindowsUninstall:
	rm $(libdir)/libVineCopulaCPP.dll

