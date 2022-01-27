EXERCISES=$(wildcard series*.tex)

PDFS=$(EXERCISES:.tex=.pdf) 
SOLUTIONS=$(EXERCISES:.tex=-solution.pdf)

VPATH = build:assets

all: $(PDFS) $(SOLUTIONS)

$(PDFS):%.pdf:%.tex FORCE | build
	latexmk -jobname=build/$(@:.pdf=) "$<"

$(SOLUTIONS):%-solution.pdf:%.tex FORCE | build

	latexmk -jobname=build/$(@:.pdf=) -pdflatex='xelatex %O "\PassOptionsToClass{answers}{exam}\input{%S}"' $<

build: 
	mkdir -p $@

clean:
	latexmk -C
	$(RM) -rf build

FORCE:

.PHONY: clean all
