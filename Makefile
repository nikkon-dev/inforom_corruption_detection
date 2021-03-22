all:
	docker run --rm -v ${PWD}:/opt -w /opt nvidia/cuda:11.2.2-devel-ubuntu20.04 gcc -I/usr/local/cuda/include -O2 /opt/main.c -lnvidia-ml -o /opt/inforom_corruption_test
