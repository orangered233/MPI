all: compare_bcast

compare_bcast: compare_bcast.c
	mpicc compare_bcast.c -o run

clean:
	rm -rf run

fire:
	mpirun -n 10 ./run 1000000 10