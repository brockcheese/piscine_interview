/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatWasThat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 23:36:00 by bpace             #+#    #+#             */
/*   Updated: 2020/02/26 02:36:06 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//replace a character in a string at a given position

char	*replace(char *word, int pos, char c) {
	char *newword = strdup(word); //create new word to return
	if (pos < 0 || pos >= (int) strlen(word)) //error checks
		return(NULL);
	newword[pos] = c; //sets the character at pos to c
	return (newword); //return new word
}

//delete a character in a string at a given position

char	*delete(char *word, int pos) {
	char *newword; //declare new word return value
	int		i, j; //incrementors
	int len = strlen(word); //length of the word stored in variable

	if (pos < 0 || pos >= len) //error check
		return(NULL);
	newword = malloc(sizeof(char) * (len)); //allocate memory for new word
	i = -1; //initialize the incrementors
	j = -1;
	while (word[++i]) { //copy every letter to new word except at pos
		if (i != pos) {
			newword[++j] = word[i];
		}
	}
	newword[++j] = '\0'; //null terminate the new word
	return (newword); //return new word
}

//add a character in a string at a given position

char	*add(char *word, int pos, char c) {
	char	*newword; //declare new word return values
	int		i, j; //incrementors
	int len = strlen(word);  //length of word stored in variable

	if (pos < 0 || pos > len) //error check
		return(NULL);
	newword = malloc(sizeof(char) * (len + 2)); //allocate mem for new word
	i = -1; //initialize incrementors
	j = -1;
	while (word[++i]) { //copy old word to new word
		if (i == pos) { //at pos copy c into new word
			newword[++j] = c;
		}
		newword[++j] = word[i];
	}
	newword[++j] = '\0'; //end new word in null terminator
	return (newword); //return the new word
}

//gets the minimum number of operations

int		getmnoo(char *word, char *dicword) {
	int ans, i, j, length;

	ans = 0;
	j = 0;
	i = 0;
	while(word[i]) {

		if (word[i] && dicword[j] && (word[i] == dicword[j] || word[i + 1] == dicword[j + 1])) {
			if (word[i] != dicword[j])
				ans++; //adds an operation if letters don't match
			j++;
		}
		else {
			while (word[i] && dicword[j] && (word[i + 1] == dicword[j])) {
				j++; //skips past repeating letters
			}
		}
		i++;
	}
	while (dicword[j])
		j++; //gets to end of word
	length = i - j; //calculates length between the two words
	if (length < 0)
		length = -(length); //finds absolute value of length
	ans += length; //adds length discrepency to number of operations
	return (ans); //returns the minimum number of operations
}

//finds the actual number of operations

int		noorecursion(char *word, char *dicword, int left) {
	int j, lengthw, lengthdw;
	char *temp;

	//if the words match return
	if (!(strcmp(word, dicword)))
		return (1);
	if (left == 0) //if there are no moves remaining return
		return (0);
	lengthw = strlen(word); //set length of both words
	lengthdw = strlen(dicword);
	j = 0;
	//main recursive loop
	for(int i = 0; word[i]; i++) {
		//if letters match continue
		if (word[i] && dicword[j] && (word[i] == dicword[j]))
			j++;
		else {
			//if the current letters don't match but the next do
			if (word[i] && dicword[j] && word[i + 1] == dicword[j + 1]) {
				//replace current letter with the other words
				temp = replace(word, i, dicword[j]);
				//if it works recursively return
				if (noorecursion(temp, dicword, left - 1)) {
					free(temp); //free allocated mem
					return (1);
				}
				free(temp); //free allocated mem
			}
			//if the next letter in the word matches the current dic word
			if (word[i] && (word[i + 1] == dicword[j]) && lengthw > lengthdw) {
				//deletes current letter
				temp = delete(word, i);
				//if it works recursively return
				if (noorecursion(temp, dicword, left - 1)) {
					free(temp); //free allocated mem
					return (1);
				}
				free(temp); //free allocated mem
			}
			//if the next letter in dic word matches the current letter
			if (word[i] && dicword[j] && (word[i] == dicword[j + 1]) && lengthw < lengthdw) {
				//adds current dictionary word letter to word
				temp = add(word, i, dicword[j]);
				//if it works recursively return
				if (noorecursion(temp, dicword, left - 1)) {
					free(temp); //free allocated mem
					return (1);
				}
				free(temp); //free allocated mem
			}
			//try replacing with each letter
			for(int k = 0; dicword[k]; k++) {
				//replace with current dictionary word letter
				temp = replace(word, i, dicword[k]);
				//if it works recursively return
				if (noorecursion(temp, dicword, left - 1)) {
					free(temp); //free allocated mem
					return (1);
				}
				free(temp); //free allocated mem
				//if the word is smaller than dic word
				if (lengthw < lengthdw) {
					//add current dicword letter to current word
					temp = add(word, i, dicword[k]);
					//if it works recursively return
					if (noorecursion(temp, dicword, left - 1)) {
						free(temp); //free allocated mem
						return (1);
					}
					free(temp); //free allocated mem
				}
			}
			//if deleting the current letter works recursively
			if (lengthw > lengthdw && noorecursion(delete(word, i), dicword, left - 1))
				return (1);
		}
	}
	return (0); //if nothing works return
}

//get the number of operations

int		getnoo(char *word, char *dicword, int noo) {
	int mnoo; //minimum number of operations

	mnoo = getmnoo(word, dicword); //gets minimum number of operations
	if (mnoo >= noo) //if minimum is greater than current number of operations return DEPTH
		return (DEPTH + 1);
	for(int i = mnoo; i < noo; i++) { //recursively test word to see num of ops
		if (noorecursion(word, dicword, i))
			return i; //return the number of operations it takes
	}
	return (DEPTH + 1); //return DEPTH if no word found
}

//syntax corrector like autocorrect

char	*whatWasThat(char *word, char** dictionary) {
	int i, noo, mnooi, temp;

	if (!(dictionary[1])) //if dictionary is one item return dictionary
		return (dictionary[0]);
	i = -1;
	noo = DEPTH + 1; //number of operations is set to DEPTH
	while(dictionary[++i]) { //find number of operations for each word
		temp = getnoo(word, dictionary[i], noo);
		//if num of ops less than current num of ops replace with temp
		if (temp <= noo) {
			noo = temp;
			mnooi = i; //set mnooi to index of current word
		}
	}
	if (noo == DEPTH + 1) //if impossible return NULL
		return (NULL);
	return(dictionary[mnooi]); //return word with minumum operations
}
