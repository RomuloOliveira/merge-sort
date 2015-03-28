GCC_OPTIONS=-ansi -Wall

all: build

clean:
	@find -name '*.o' -delete
	@find -name '*.out' -delete

build: clean
	@$(MAKE) -C mergesort
	@$(MAKE) -C utils
	@gcc -o mergesort.out main.c mergesort/*.o utils/*.o $(GCC_OPTIONS)

example: build
	./mergesort.out 2 6 5

test: clean
	@$(MAKE) -C mergesort build
	@$(MAKE) -C utils build
	@$(MAKE) -C tests build
	@./tests/test.out
