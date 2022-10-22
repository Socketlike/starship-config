CC = clang
CC_FLAGS = -O2 -v
OUTPUT = detectlang

make:
	@echo "Checking for source file"
	@if [ ! -f "detectlang.c" ]; then echo "Source file does not exist."; exit 1; else echo "Source file exists"; fi;
	@${CC} ${CC_FLAGS} detectlang.c -o ${OUTPUT}