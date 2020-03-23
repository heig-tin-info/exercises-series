DOCKER=docker run -it -v "$$(pwd):/srv" -w=/srv nowox/latex:1.2

EXERCISES=$(wildcard series*.tex)
SOLUTIONS=$(wildcard solutions*.tex)

PDFS=$(EXERCISES:.tex=.pdf) $(SOLUTIONS:.tex=.pdf)

all: $(PDFS)

$(PDFS):%.pdf:%.tex
	$(DOCKER) latexmk -pdf -xelatex $<

clean:
	$(DOCKER) latexmk -C

.PHONY: clean all
