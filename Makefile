all:
	gcc *.h *.c -o saida

clean:
	rm -Rf *.gch

clear:
	rm -Rf a.out *.gch
