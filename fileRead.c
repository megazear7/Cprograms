#include<stdio.h>
#include<stdlib.h>

int main() {
	FILE *in;
	in = fopen("armor.txt","r");

	char str[100];

	fgets(str, 99, in);

	printf("%s",str);
	
	return 0;
}
