-include common
CHARMC= ampicxx $(OPTS)

all: pgm

pgm: mpi.o
	$(CHARMC) -o pgm mpi.o -balancer RandCentLB

mpi.o: mpi.c
	$(CHARMC) -c mpi.c

#
#
# clean up .o, .mod, .exe and EMACS backup files
#

mpi: 
	mpicc mpi.c -o m

runmpi:
	mpirun -np 4 m
clean:
	rm -f *.o *.mod pgm *~ conv-host charmrun test.o pgm.exe pgm.pdb pgm.ilk

test: pgm
	$(call run, ./pgm +p1 +vp1 )
	$(call run, ./pgm +p1 +vp2 )
	$(call run, ./pgm +p1 +vp4 )
	$(call run, ./pgm +p2 +vp2 )
	$(call run, ./pgm +p2 +vp4 )
	$(call run, ./pgm +p2 +vp1 )

bgtest: pgm
	$(call run, ./pgm +p1 +vp1 +x1 +y1 +z1 )
	$(call run, ./pgm +p1 +vp2 +x1 +y1 +z1 )
	$(call run, ./pgm +p1 +vp4 +x1 +y1 +z1 )
	$(call run, ./pgm +p2 +vp2 +x2 +y1 +z1 )
	$(call run, ./pgm +p2 +vp4 +x2 +y1 +z1 )
	$(call run, ./pgm +p2 +vp1 +x2 +y1 +z1 )
