all: avg

avg: avg.c
	mpicc avg.c -o run

clean:
	rm -rf run

fire:
	mpirun -n 10 ./run 10000