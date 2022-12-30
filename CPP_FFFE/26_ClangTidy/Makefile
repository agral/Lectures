.PHONY: build clean

TEX_SOURCE=26.tex
PDF_GENERATED_FILENAME=$(patsubst %.tex,%.pdf,$(TEX_SOURCE))
PDF_WANTED_FILENAME=slides.pdf
DIR_BUILD=build

build: $(TEX_SOURCE)
	@mkdir -p "$(DIR_BUILD)"
	pdflatex -output-directory "$(DIR_BUILD)" "$(TEX_SOURCE)"
	# run it again in case advanced graphics features / bibtex are used:
	pdflatex -output-directory "$(DIR_BUILD)" "$(TEX_SOURCE)"
	@mv "$(DIR_BUILD)/$(PDF_GENERATED_FILENAME)" "./$(PDF_WANTED_FILENAME)"

clean:
	@rm -rfv "$(DIR_BUILD)"
	@rm -v "$(PDF_WANTED_FILENAME)"
