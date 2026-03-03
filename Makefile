FLAGS = -Wall -Wextra -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib -framework OpenGL -framework IOKit -framework Cocoa -lm -lpthread -ldl

.PHONY: build clean 

build: 
	gcc $(FLAGS) -o build/chip8 ./*.c 

clean:
	rm -rf build/
