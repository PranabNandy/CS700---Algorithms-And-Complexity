


.PHONY: all pp me

all: pp me


pp: mergesort.cpp
	g++ mergesort.cpp
	
me: a.out
	valgrind --leak-check=full --show-leak-kinds=all /usr/bin/time -v ./a.out $&> complexity_analyze.txt
	valgrind --leak-check=full --show-leak-kinds=all /usr/bin/time -v ./a.out 2>> complexity_analyze.txt
	
	
clean:
	@echo "Cleaning up..."
	rm a.out output.txt input.txt complexity_analyze.txt
