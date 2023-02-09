CC := gcc
SF := $(wildcard *.c)
OUTDIR := bin
NAME := function-calls

all: clean build 

build:
	$(CC) $(SF) -o $(OUTDIR)/$(NAME) -fno-stack-protector

clean: 
	mkdir -p $(OUTDIR)
	rm -f $(OUTDIR)/*
