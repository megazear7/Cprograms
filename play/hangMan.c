#include<stdio.h>
#include<stdlib.h>

/*
Algorithm:

Randomly determine a word for them to try to guess

Display a hang man tree with no one hanging

Ask for a guess one at a time until the either guess the word or hangman is filled in

If they guess correct fill in a blank

If they guess worng add to the hang man representation

Print the hangman representation at the end of each loop

When the loop ends tell them if they won or lost

*/
int main() {
	printf("This is hang man, I have a word in mind and you have to guess letters and I will fill in the blanks\n");
	printf("If you guess wrong though, I will add to my hangman drawing\n");
	int n;
	scanf("%d", &n);

	int result = factorial(n);

	printf("Result = %d\n", result);

	return 0;
}
