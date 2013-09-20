#include<stdio.h>
#include<stdlib.h>

int factorial(int n){
	if(n < 0){
		return -1;
	}
	int i;
	int result=0;
	for(i = 0; i < n; i++){
		result = result + i + 1;
	}
	if(result < 0){
		return -1;
	}
	return result;
}

int main() {
	printf("Input and integer N, and I will output 1+2+...+N, where a -1 is returned on overflow errors and when N < 0\n");
	int n;
	scanf("%d", &n);

	int result = factorial(n);

	printf("Result = %d\n", result);

	return 0;
}
