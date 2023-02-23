SHELL = /bin/bash

CXX = clang++
CXXFLAGS = -O2 -std=c++17

DETECTLANG_SRC = ./src/detectlang.cpp ./src/config.h
DETECTDISTRO_SRC = ./src/detectdistro.cpp ./src/popen.h

all: builddir detectlang detectdistro

builddir:
	mkdir -p ./build
detectlang: builddir $(DETECTLANG_SRC)
	$(CXX) $(CXXFLAGS) src/detectlang.cpp -o build/detectlang
detectdistro: builddir $(DETECTDISTRO_SRC)
	$(CXX) $(CXXFLAGS) src/detectdistro.cpp -o build/detectdistro
curved: detectlang detectdistro
	cp ./starship/*.toml ./build
	sed -i 's/{!CHAR_DIVIDER!}//g' ./build/*.toml
	mkdir -p $(HOME)/.config/starship
	cp ./build/{detect{distro,lang},*.toml} $(HOME)/.config/starship
	@echo -e "\nDone. Don't forget to edit your shell's rc script and set the STARSHIP_CONFIG variable to\n\n$(HOME)/.config/starship/fast.toml\n\nor\n\n$(HOME)/.config/starship/std.toml."
powerline: detectlang detectdistro
	cp ./starship/*.toml ./build
	sed -i 's/{!CHAR_DIVIDER!}//g' ./build/*.toml
	mkdir -p $(HOME)/.config/starship
	cp ./build/{detect{distro,lang},*.toml} $(HOME)/.config/starship
	@echo -e "\nDone. Don't forget to edit your shell's rc script and set the STARSHIP_CONFIG variable to\n\n$(HOME)/.config/starship/fast.toml\n\nor\n\n$(HOME)/.config/starship/std.toml."
sharp: detectlang detectdistro
	cp ./starship/*.toml ./build
	sed -i 's/{!CHAR_DIVIDER!}//g' ./build/*.toml
	mkdir -p $(HOME)/.config/starship
	cp ./build/{detect{distro,lang},*.toml} $(HOME)/.config/starship
	@echo -e "\nDone. Don't forget to edit your shell's rc script and set the STARSHIP_CONFIG variable to\n\n$(HOME)/.config/starship/fast.toml\n\nor\n\n$(HOME)/.config/starship/std.toml."
