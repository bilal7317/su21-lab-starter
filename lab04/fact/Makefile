all: build run clean

.PHONY: all

build:
	@riscv64-unknown-elf-gcc -march=rv32g -mabi=ilp32 -nostdlib -nostartfiles -T link.ld test.S -o test.out

run:
	@spike -d --log-commits --isa=rv32g $(which pk) test.out

clean:
	@-rm *.log
	@-rm *.out
	@clear

