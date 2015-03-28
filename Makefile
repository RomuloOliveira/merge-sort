GCC_OPTIONS=-ansi -Wall

all: build

clean:
	@find -name '*.o' -delete
	@find -name '*.out' -delete

build: clean
	@$(MAKE) -C mergesort
	@$(MAKE) -C utils
	@gcc -o main.out main.c mergesort/*.o $(GCC_OPTIONS)

test: clean
	@$(MAKE) -C mergesort build
	@$(MAKE) -C utils build
	@$(MAKE) -C tests build
	@./tests/test.out
