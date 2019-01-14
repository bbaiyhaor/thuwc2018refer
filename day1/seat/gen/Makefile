
CXX_FLAGS = -Wall -I../../../testlib

all: random.exe

random.exe: random.cpp
	g++ $< -o $@ $(CXX_FLAGS)

run: random.exe
	make -C ../cy
	python run.py

clean:
	-rm *.exe