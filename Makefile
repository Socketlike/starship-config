SHELL = /bin/bash

CC = clang
CXX = clang++

CCFLAGS = -O2
CXXFLAGS = -O2

DETECTLANG_SRC = ./src/detectlang.c ./src/config.h
DETECTDISTRO_SRC = ./src/detectdistro.cpp ./src/popen.h

all: detectlang detectdistro

detectlang: $(DETECTLANG_SRC)
	cd ./src && $(CC) $(CCFLAGS) detectlang.c -o ../detectlang
detectdistro: $(DETECTDISTRO_SRC)
	cd ./src && $(CXX) $(CXXFLAGS) detectdistro.cpp -o ../detectdistro