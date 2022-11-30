SHELL = /bin/bash

CXX = clang++
CXXFLAGS = -O2 -std=c++17

DETECTLANG_SRC = ./src/detectlang.cpp ./src/config.h
DETECTDISTRO_SRC = ./src/detectdistro.cpp ./src/popen.h

all: detectlang detectdistro

detectlang: $(DETECTLANG_SRC)
	cd ./src && $(CXX) $(CXXFLAGS) detectlang.cpp -o ../detectlang
detectdistro: $(DETECTDISTRO_SRC)
	cd ./src && $(CXX) $(CXXFLAGS) detectdistro.cpp -o ../detectdistro
curved: detectlang detectdistro
	mkdir -p $(HOME)/.config/starship
	cp {detect{distro,lang},starship/curved/linux-*.toml} $(HOME)/.config/starship
powerline: detectlang detectdistro
	mkdir -p $(HOME)/.config/starship
	cp {detect{distro,lang},starship/powerline/linux-*.toml} $(HOME)/.config/starship
sharp: detectlang detectdistro
	mkdir -p $(HOME)/.config/starship
	cp {detect{distro,lang},starship/sharp/linux-*.toml} $(HOME)/.config/starship