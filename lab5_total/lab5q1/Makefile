all: source.wc



%.wc: %.txt #any wc file : any text file with the same name as the wc file
	wc $< > $*.wc



clean:
	rm -f *.wc
