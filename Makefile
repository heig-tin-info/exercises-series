DOCKER=docker run -it -v "$$(pwd):/srv" -w=/srv nowox/latex:1.2

EXERCISES=$(wildcard series*.tex)
SOLUTIONS=$(wildcard solutions*.tex)

PDFS=$(EXERCISES:.tex=.pdf) $(SOLUTIONS:.tex=.pdf)

VPATH = dist:assets

all: $(PDFS)

$(PDFS):%.pdf:%.tex | dist
	$(DOCKER) latexmk -pdf -xelatex -jobname=dist/$(@:.pdf=) $<

dist: 
	mkdir -p dist

clean:
	$(DOCKER) latexmk -C

.PHONY: clean all
