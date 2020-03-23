DOCKER=docker run -it -v "$$(pwd):/srv" -w=/srv nowox/latex:1.2

EXERCISES=$(wildcard series*.tex)
SOLUTIONS=$(wildcard solutions*.tex)

PDFS=$(EXERCISES:.tex=.pdf) $(SOLUTIONS:.tex=.pdf)

VPATH = build:assets

all: $(PDFS)

$(PDFS):%.pdf:%.tex | build
	$(DOCKER) latexmk -pdf -xelatex -jobname=build/$(@:.pdf=) $<

build: 
	mkdir -p $@

clean:
	$(DOCKER) latexmk -C

.PHONY: clean all
