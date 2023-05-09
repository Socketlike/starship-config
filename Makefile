SHELL = /bin/bash

CXX = clang++
CXXFLAGS = -O2 -std=c++17

all: build detectlang detectdistro

build/detectlang: src/detectlang.cpp src/config.hpp
	if [[ ! -d "./build" ]]; then if [[ -e "./build" ]]; then rm ./build; fi; mkdir -p ./build; fi
	$(CXX) $(CXXFLAGS) src/detectlang.cpp -o $@
build/detectdistro: src/detectdistro.cpp
	if [[ ! -d "./build" ]]; then if [[ -e "./build" ]]; then rm ./build; fi; mkdir -p ./build; fi
	$(CXX) $(CXXFLAGS) src/detectdistro.cpp -o $@
curved: build/detectlang build/detectdistro
	cp ./starship/*.toml ./build
	sed -i 's/{!CHAR_DIVIDER!}//g' ./build/*.toml
	sed -i 's/{!CHAR_DIVIDER_ALT!}//g' ./build/*.toml
	mkdir -p $(HOME)/.config/starship
	cp ./build/{detect{distro,lang},*.toml} $(HOME)/.config/starship
	@echo -e "\nDone. Don't forget to edit your shell's rc script and set the STARSHIP_CONFIG variable to\n\n$(HOME)/.config/starship/fast.toml\n\nor\n\n$(HOME)/.config/starship/std.toml."
powerline: build/detectlang build/detectdistro
	cp ./starship/*.toml ./build
	sed -i 's/{!CHAR_DIVIDER!}//g' ./build/*.toml
	sed -i 's/{!CHAR_DIVIDER_ALT!}//g' ./build/*.toml
	mkdir -p $(HOME)/.config/starship
	cp ./build/{detect{distro,lang},*.toml} $(HOME)/.config/starship
	@echo -e "\nDone. Don't forget to edit your shell's rc script and set the STARSHIP_CONFIG variable to\n\n$(HOME)/.config/starship/fast.toml\n\nor\n\n$(HOME)/.config/starship/std.toml."
sharp: build/detectlang build/detectdistro
	cp ./starship/*.toml ./build
	sed -i 's/{!CHAR_DIVIDER!}//g' ./build/*.toml
	sed -i 's/{!CHAR_DIVIDER_ALT!}//g' ./build/*.toml
	mkdir -p $(HOME)/.config/starship
	cp ./build/{detect{distro,lang},*.toml} $(HOME)/.config/starship
	@echo -e "\nDone. Don't forget to edit your shell's rc script and set the STARSHIP_CONFIG variable to\n\n$(HOME)/.config/starship/fast.toml\n\nor\n\n$(HOME)/.config/starship/std.toml."