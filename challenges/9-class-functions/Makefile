CC := g++
SF := $(wildcard *.cpp)
OUTDIR := bin
NAME := class-functions

all: clean build 

build:
	$(CC) $(SF) -o $(OUTDIR)/$(NAME) -fno-stack-protector

clean: 
	mkdir -p $(OUTDIR)
	rm -f $(OUTDIR)/*
