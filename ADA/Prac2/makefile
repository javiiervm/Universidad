OPTS = -O3 -std=c++0x -march=native -flto

qs-vs-hs: qs-vs-hs.cc
	g++ ${OPTS} -o qs-vs-hs qs-vs-hs.cc 

qs-vs-hs.Msteps: qs-vs-hs
	./qs-vs-hs > qs-vs-hs.Msteps

graphs: qs-vs-hs.Msteps qs-vs-hs.gpi
	gnuplot qs-vs-hs.gpi

all:	qs-vs-hs qs-vs-hs.Msteps graphs

tar: qs-vs-hs.cc qs-vs-hs.gpi makefile
	tar cvfz 51299727K.tar.gz qs-vs-hs.cc qs-vs-hs.gpi makefile

clean: 
	rm -f qs-vs-hs qs-vs-hs.Msteps fit.log *.png *~
