
CXX_FLAGS = -Wall -O2 -I../../../testlib -D__TEST__

all: val.exe brute.exe segtree.exe

brute.exe: brute.cpp
	g++ $< -o $@ $(CXX_FLAGS)

segtree.exe: segtree.cpp
	g++ $< -o $@ $(CXX_FLAGS)

val.exe: val.cpp
	g++ $< -o $@ $(CXX_FLAGS)

val: all
	python val.py

clean:
	-rm *.exe