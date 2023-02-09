CC := gcc
SF := $(wildcard *.c)
OUTDIR := bin
NAME := references

all: clean build 

build:
	$(CC) $(SF) -lm -o $(OUTDIR)/$(NAME) -fno-stack-protector

clean: 
	mkdir -p $(OUTDIR)
	rm -f $(OUTDIR)/*
