/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   understand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:57:41 by bpace             #+#    #+#             */
/*   Updated: 2020/03/03 01:57:34 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//finds the number of unique characters in a given position d 

int		getNOC(char **dictionary, int d) {
	//stores all valid letters
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	int noc = 0; //initializes return value to 0
	char c, t;
	//initializes check variable to dth letter in first word
	c = dictionary[0][d];
	if (c != '\0' && strchr(alphabet, c ) != NULL)
		noc++; //if check is a valid character increment return value
	//for every word in dictionary compare dth letter
	for (long long i = 0; dictionary[i]; i++) {
		t = dictionary[i][d]; //set letter to compare
		//if new letter is different from previous increment the count
		if (t != c && t != '\0' && strchr(alphabet, t) != NULL) {
			noc++;
			c = t; //set new character to compare
		}
	}
	return (noc); //return number of unique characters
}

//helper function for recursion

void		createTrieHelper(int d, char **dictionary, struct s_node *curr) {
	//stores all valid letters
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	char **subdictionary; //stores subdictionary for children nodes
	int noc, j;
	long long start, s, i;
	char c, t;

	if (!dictionary[0]) //error checking
		return;
	//gets number of unique characters in dictionary at current letter index
	noc = getNOC(dictionary, d);
	//allocate memory for children nodes
	curr->child = malloc(sizeof(struct s_node*) * (noc + 1));
	curr->child[noc] = NULL; //null terminate children node array
	j = -1; //initialize index
	c = dictionary[0][d]; //initialize character to check at current letter index
	start = 0; //initialize start of subdictionary
	//if character is valid initialize child node
	if (c != '\0' && strchr(alphabet, c) != NULL) {
		curr->child[++j] = malloc(sizeof(struct s_node));
		curr->child[j]->c = c;
		curr->child[j]->isWord = (dictionary[0][d + 1] == '\0') ? 1 : 0;
	}
	for (i = 1; dictionary[i - 1]; i++) {
		if (dictionary[i]) //set character to compare to current words character
			t = dictionary[i][d];
		if (t != c || !dictionary[i]) { //if character differs from current character
			//if (c != '\0' && strchr(alphabet, c) != NULL && j > -1) {
			if (j > -1) {
				//allocate memory for subdictionary
				subdictionary = malloc(sizeof(char*) * (i - start + 1));
				//null terminate subdictionary
				subdictionary[i - start] = NULL;
				s = -1; //initialize subdictionary index
				//copy every word from current dictionary into subdictionary
				for (long long k = start; k < i; k++) {
					subdictionary[++s] = dictionary[k];
				}
				//recurse in
				createTrieHelper(d + 1, subdictionary, curr->child[j]);
				free(subdictionary); //free subdictionary
			}
			//if character is valid initialize child node
			if (t != '\0' && strchr(alphabet, t) != NULL && dictionary[i]) {
				start = i; //change start of subdirectory index to current index
				curr->child[++j] = malloc(sizeof(struct s_node));
				curr->child[j]->c = t;
				curr->child[j]->isWord = (dictionary[i][d + 1] == '\0') ? 1 : 0;
			}
			c = t; //set character to compare to current character
		}
		//if next character is null set current node to isWord
		if (t == '\0' && dictionary[i]) {
			curr->isWord = 1;
			start++; //move starting index for subdirectory
		}
	}
	//if (c != '\0' && strchr(alphabet, c) != NULL && j > -1) {
	//			subdictionary = malloc(sizeof(char*) * (i - start + 1));
	//			subdictionary[i - start] = NULL;
	//			s = -1;
	//			for (long long k = start; k < i; k++) {
	//				subdictionary[++s] = dictionary[k];
	//			}
	//			createTrieHelper(d + 1, subdictionary, curr->child[j]);
	//			free(subdictionary);
	//}
}

//creates an n-ary prefix tree given a dictionary

struct s_trie *createTrie(char **dictionary) {
	//stores all valid letters
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	char **subdictionary; //stores subdictionary for children nodes
	struct s_trie *ans; //tree to be returned
	int noc, j;
	long long start, s;
	char c, t;

	ans = malloc(sizeof(struct s_trie)); //allocates memory for prefix tree
	//allocates memory for root node
	ans->node = malloc(sizeof(struct s_node));
	ans->node->c = '\0'; //root node contains no letter so is set to NULL
	ans->node->isWord = 0; //root node is not a word
	if (!dictionary[0]) //error checking
		return (ans);
	//gets number of unique characters in dictionary at index 0
	noc = getNOC(dictionary, 0);
	//allocate memory for children nodes
	ans->node->child = malloc(sizeof(struct s_node*) * (noc + 1));
	ans->node->child[noc] = NULL; //null terminate children node array
	j = -1; //initialize index
	//initializes character to compare to first letter of first word
	c = dictionary[0][0]; 
	start = 0; //stores the first index of the subdirectory
	//if c is a valid character initialize child node
	if (c != '\0' && strchr(alphabet, c) != NULL) {
		ans->node->child[++j] = malloc(sizeof(struct s_node));
		ans->node->child[j]->c = c;
		ans->node->child[j]->isWord = (dictionary[0][1] == '\0') ? 1 : 0;
	}
	for (long long i = 0; dictionary[i]; i++) {
		t = dictionary[i][0]; //set character to compare to first letter of word
		if (t != c) { //if character differs from current character
			if (j > -1) {
				//allocate memory for subdictionary
				subdictionary = malloc(sizeof(char*) * (i - start + 1));
				//null terminate subdictionary
				subdictionary[i - start] = NULL;
				s = -1; //initialize subdictionary index
				//copy every word from original dictionary to the subdictionary
				for (long long k = start; k < i; k++) {
					subdictionary[++s] = dictionary[k];
				}
				//recurses into helper function
				createTrieHelper(1, subdictionary, ans->node->child[j]);
				free(subdictionary); //free memory from subdictionary
			}
			//if t is a valid character initialize child node
			if (t != '\0' && strchr(alphabet, t) != NULL) {
				start = i; //set start to beginning of new subdirectory index
				ans->node->child[++j] = malloc(sizeof(struct s_node));
				ans->node->child[j]->c = t;
				ans->node->child[j]->isWord = (dictionary[i][1] == '\0') ? 1 : 0;
			}
			c = t; //set character to compare to current character
		}
	}
	return (ans); //returns completed prefix tree
}

//helper function to recursively fill in letters to the sentence

char *understandHelper(int num, char *word, struct s_node *curr) {
	char *temp; //stores word to complete
	if (word[num] == '\0'){ //if at the end of the word
		if (curr->isWord) { //if current word is valid word return word
			return (word);
		}
		else //if current word is invalid return NULL
			return (NULL);
	}
	//for every child node
	for(int i = 0; curr->child && curr->child[i]; i++) {
		//if current letter matches child node letter recurse in
		if (word[num] == curr->child[i]->c) {
			return(understandHelper(num + 1, word, curr->child[i]));
		}
		//if current letter is ? try replacing with child node letter
		if (word[num] == '?') {
			word[num] = curr->child[i]->c;
			//recurse in
			temp = understandHelper(num + 1, word, curr->child[i]);
			if (temp) //return finished word
				return (temp);
			word[num] = '?'; //if word not found reset char to ?
		}
	}
	return (NULL); //if no word found return NULL
}

//uses n-ary prefix tree to fill in the missing letters of a word 

char *understand(char *word, struct s_trie *trie) {
	char *ans; //stores new sentence 
	char *oldword; //stores original sentence

	oldword = strdup(word); //duplicates sentence in case of error
	//initializes return value to the filled in sentence
	ans = understandHelper(0, oldword, trie->node);
	if (ans == NULL) { //if word not found return old word
		return (oldword);
	}
	return (ans); //return completed word
}
