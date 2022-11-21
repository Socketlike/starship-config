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
configcheck:
	if [ "$(STARSHIP_CONFIG)" != "/home/$(USER)/.config/starship/minimal.toml" ]; then echo "export STARSHIP_CONFIG=\"$(HOME)/.config/starship/minimal.toml\"" >> $(HOME)/.bashrc; fi 
install: detectlang detectdistro minimal.toml configcheck
	mkdir -p $(HOME)/.config/starship
	cp {detect{distro,lang},minimal.toml} $(HOME)/.config/starship