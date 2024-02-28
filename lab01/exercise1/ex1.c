#include <string.h>
#include "ex1.h"
#include <stdio.h>

/* Returns the number of times LETTER appears in STR.
There are two different ways to iterate through a string.
1st way hint: strlen() may be useful
2nd way hint: all strings end in a null terminator */
int num_occurrences(char *str, char letter) {
    /* TODO: implement num_occurances */

	int i = 0;                      // Variablw for for() loop
        int count = 0;			// To count the no on occurrences
	for(i=0;i<=strlen(str);i++)	// fOR lopp to run throught the length of string
	{
		if(letter == str[i])	// if the letter is found at this instant then 
		{			// this condition will be true and cout it
			count +=1;
		}
	}
			
    return count;			// return the count of that letter occurrences
}

/* Populates DNA_SEQ with the number of times each nucleotide appears.
Each sequence will end with a NULL terminator and will have up to 20 nucleotides.
All letters will be upper case. */
void compute_nucleotide_occurrences(DNA_sequence *dna_seq) {
    /* TODO: implement compute_nucleotide_occurances */
	dna_seq -> A_count =0;			// To NULL the values at start
	dna_seq -> C_count =0; 
	dna_seq -> G_count =0; 
	dna_seq -> T_count =0; 
	int i=0;				// Good practice to initialize before for loop
	for(i;i<=strlen(dna_seq -> sequence);i++) // for loop to run up to the length of string (sequence)	
	{					  // and count the number of letter occurance
		if('A' == dna_seq -> sequence[i])		
		{
			dna_seq -> A_count +=1;		
		}		
		if('C' == dna_seq -> sequence[i])		
		{			
			dna_seq -> C_count +=1;		
		}		
		if('G' == dna_seq -> sequence[i])		
		{			
			dna_seq -> G_count +=1;		
		}		
		if('T' == dna_seq -> sequence[i])		
		{			
			dna_seq -> T_count +=1; 		
		}	
	}	

       	return;
}
