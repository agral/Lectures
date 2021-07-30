.PHONY: build clean

TEX_SOURCE=07_FunWithCairo.tex
PDF_FILENAME=$(patsubst %.tex,%.pdf,$(TEX_SOURCE))
DIR_BUILD=build

build: $(TEX_SOURCE)
	@mkdir -p "$(DIR_BUILD)"
	pdflatex -output-directory "$(DIR_BUILD)" "$(TEX_SOURCE)"
	@mv "$(DIR_BUILD)/$(PDF_FILENAME)" "./$(PDF_FILENAME)"

clean:
	@rm -rfv "$(DIR_BUILD)"
	@rm -v "$(PDF_FILENAME)"
