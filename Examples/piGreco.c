#include<stdio.h>
#include<math.h>

int main(int argc, char **argv) {
	double accum = 0;
	int n = 1000000000;
	
	for(int i = 0; i < n; i++) {
		accum += (pow(-1, i)/(2*i+1));
	}
	printf("%g\n", accum*4);
	return 0;
}
