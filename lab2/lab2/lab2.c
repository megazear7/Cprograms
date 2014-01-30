#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
TODO README
TODO FIX Program
something to do with the index'sof the winner is off and
of calculateing who is sad and who isn't
*/

/*
Using macros for debugging purposes
Turn on / off by setting DEBUG_ON to 1 or 0
Usage Example:
DEBUG "number %i is a good number\n",x END	
*/
#define DEBUG_ON 1
#define DEBUG if(DEBUG_ON){ printf("Debug on line %i: ",__LINE__); printf(
#define END ); printf("\n");}

int winner(int tally[], int length);

int main() {

	FILE *input_file = fopen("input_1","r");
	if (input_file == NULL) {
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	FILE *output_file = fopen("output_1","w");
	if (output_file == NULL) {
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	/*
	This array stores the vote results. This is not found until later
	and is derived from the people_choices array
	*/
	int tally[20];

	/*
	This is a multidemensional array that stores up to 20
	restaurants each with up to 50 characters in its name
	The position of the restraunt in this array is its "restraunt code"
	*/
	char options[20][50];

	/*
	This is a multidemensional array that stores up to
	100 names where each name is up to 25 characters long
	The position of the restraunt in this array is its "person code", and
	yes these should line up with the values in people_choices
	*/
	char people_names[100][25];	

	/*
	This is a multideminsional array that stores the information
	of up to 100 people. The first three components of each is 
	there restaurant choices, and the last one is there "negative" vote
	The position of the restraunt in this array is its "person code", and 
	yes these should line up with the values in people_names
	*/
	int people_choices[100][4];

	/*
	This is a multideminsional array that stores yes or no values that state
	whether the same vote that matches up with the position in people_choices
	has already been cast or not.
	for example if casted_votes[5][2] is equal to 0 then that means that the
	vote stored in people_choices[5][2] has yet to be counted
	*/
	int casted[100][3];

	// First we need to create the arrays above

	// Read in the first line so we know how many restaurants there are
	int number_of_options;
	fscanf(input_file, "%i", &number_of_options);
	fgetc(input_file);

	/*
	Create the options array, read in one line at a time from the 
	input file and store the names in the options array until you have
	read in number_of_options amount
	*/
	int i;
	for(i = 0; i < number_of_options; i++) {
		char ch;
		int j = 0;
		while ((ch = fgetc(input_file)) != '\n') {
			options[i][j] = ch;
			j++;
		}
	}

	// Read in the next lline so we know how many people there are
	int number_of_people;
	fscanf(input_file,"%i", &number_of_people);

	/*
	Create the people_names and people_choices array. Read in one line at
	a time and put one character at a time into the people_names array
	until you get to a space, at which point fill in the people_choices
	array, you in a integer store it in the people_choices array, read in
	a space, and discard it, etc...
	*/
	for(i = 0; i < number_of_people; i++) {
		char ch;
		int j = 0;
		while ((ch = fgetc(input_file)) != ' ') {
			people_names[i][j] = ch;
			j++;
		}

		int val = 0;

		fscanf(input_file,"%i", &val); 
		people_choices[i][0] = val;
		fgetc(input_file);

		fscanf(input_file,"%i", &val); 
		people_choices[i][1] = val;
		fgetc(input_file);

		fscanf(input_file,"%i", &val); 
		people_choices[i][2] = val;
		fgetc(input_file);

		fscanf(input_file,"%i", &val); 
		people_choices[i][3] = val;
		fgetc(input_file);
	}

	// After the arrays are created we need to tally the votes and find the winner

	for(i = 0; i < number_of_people; i++) {
		tally[people_choices[i][3]-1]--;
	}

	do {

		for(i = 0; i < number_of_people; i++) {
			
			if (casted[i][0] == 0) {
				tally[people_choices[i][0]-1]++;
				casted[i][0] = 1;

			} else if (casted[i][1] == 0) {
				tally[people_choices[i][1]-1]++;
				casted[i][1] = 1;

			} else if (casted[i][2] == 0) {
				tally[people_choices[i][2]-1]++;
				casted[i][2] = 1;

			}
		}

	} while(winner(tally, number_of_options) == 0);


	// find and the winner
	int total = 0;
	for(i = 0; i < 6; i++) {
		total = total + tally[i];
	}

	int winner;
	for(i = 0; i < number_of_options; i++) {
		if (tally[i] >= (total/2)) {
			winner = i;
		}
	}

	// print the winner
	fprintf(output_file,"%s\n", options[winner]);

	// Print the Happy people
	fprintf(output_file,"Happy:\n");
	int any = 0;
	for(i = 0; i < number_of_people; i++) {
		if ( (people_choices[i][0] == winner) || (people_choices[i][1] == winner) || (people_choices[i][2] == winner) ) {
			fprintf(output_file,"%s\n", people_names[i]);
			any = 1;
		}
	}
	if(any == 0) fprintf(output_file,"none\n");

	// Print the Sad people
	fprintf(output_file,"Sad:\n");
	any = 0;
	for(i = 0; i < number_of_people; i++) {
		if (people_choices[i][3] == winner) {
			fprintf(output_file,"%s\n", people_names[i]);
			any = 1;
		}
	}
	if(any == 0) fprintf(output_file,"none\n");

	fclose(input_file);
	fclose(output_file);

	return 0;
}

/*
Returns true if on of the entryies in tally is greater than all
the others combined, false otherwise
*/
int winner(int tally[], int length) {
	
	int i;
	int total = 0;
	for(i = 0; i < length; i++) {
		total = total + tally[i];
	}

	for(i = 0; i < length; i++) {
		if (tally[i] >= (total/2)) {
			return 1;
		}
	}

	return 0;
}































