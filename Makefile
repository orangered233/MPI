all: avg

avg: reduce_stddev.c
	mpicc reduce_stddev.c -o run

clean:
	rm -rf run

fire:
	mpirun -n 10 ./run 10000