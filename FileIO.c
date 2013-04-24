#include<stdio.h>
#include<stdlib.h>

int main() {
	FILE *out;
	out = fopen("armor.txt","w");
	fprintf(out, "armor is cool");
	return 0;
}
