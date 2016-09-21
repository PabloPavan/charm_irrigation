# comentario -> para executar digite make 

all:
	 "utilize make mpi ou make c"
	
mpi:
	mpicc -o mpi mpi.c

c:
	g++ -o sequencial sequencial.cpp


clean:
	rm -rf *.out mpi sequencial

