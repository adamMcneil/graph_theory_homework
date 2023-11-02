all:hw2

run:main.c
	make hw1
	./hw1

hw2:main.c
	gcc main.c -o  hw2 -lm

doc: main.tex
	pdflatex -shell-escape main.tex -o main.pdf

clean:
	rm hw2