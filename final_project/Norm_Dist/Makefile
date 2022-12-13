all: norm_example erfinv_test

norm_example: norm_example.c
	gcc -o norm_example norm_example.c -lm

erfinv_test: erfinv_test.c
	gcc -o erfinv_test erfinv_test.c -lm

make dist:
	./norm_example
	python ./plot.py

clean:
	rm -f norm_example norm_dist.txt