
CXX_FLAGS = -Wall -O2 -D__TEST__ -I../../../testlib

all: 40pts.exe 70pts.exe 100pts.exe

40pts.exe: 40pts.cpp
	g++ $< -o $@ $(CXX_FLAGS)

70pts.exe: 70pts.cpp
	g++ $< -o $@ $(CXX_FLAGS)

100pts.exe: 100pts.cpp
	g++ $< -o $@ $(CXX_FLAGS)

val.exe: val.cpp
	g++ $< -o $@ $(CXX_FLAGS)

val: val.exe 70pts.exe
	python val.py

clean:
	-rm *.exe