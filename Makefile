buildall : gcc -g -O -c dico.c 
	  gcc -g -O -c arbre.c
	  gcc -g -O -c projet.c
	  gcc projet.o dico.o arbre.o -o projet
	  gcc -c projet.c