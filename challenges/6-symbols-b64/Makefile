CC := g++
SF := $(wildcard *.cpp)
OUTDIR := bin
NAME := symbols-b64

all: clean build 

build:
	$(CC) $(SF) -o $(OUTDIR)/$(NAME) -fno-stack-protector

clean: 
	mkdir -p $(OUTDIR)
	rm -f $(OUTDIR)/*
