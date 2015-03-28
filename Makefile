GCC_OPTIONS=-ansi -Wall

all: build

clean:
	@find -name '*.o' -delete
	@find -name '*.out' -delete

build: clean
	@$(MAKE) -C mergesort
	@gcc -o main.out main.c mergesort/*.o $(GCC_OPTIONS)

test: clean
	@$(MAKE) -C mergesort
	@$(MAKE) -C tests
