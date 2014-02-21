#include <stdio.h>

void a() {
	printf("hello");
}

void b() {
	printf("world");
}


int main() {

	// is there some thing I can do here such as:
	a=&b; // <- note this does note compile / work but captures the idea of my goal 

	// that will make the next line print "world"
	a();

	return 0;
}
