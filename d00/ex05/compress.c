/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 01:38:02 by bpace             #+#    #+#             */
/*   Updated: 2020/02/25 19:50:27 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//creates a hash product from the input

size_t hash(char *input) {
	size_t	ans; //return value

	ans = 0; //initialize return value
	for (unsigned long i = 0; i < strlen(input); i++) {
		ans = (ans + input[i]); //creates hash value
	}
	return ans; //returns hash value
}

//initializes the hash table given the capacity of the array

struct s_dict *dictInit(int capacity) {
	struct s_dict	*table;
	int				i;

	table = malloc(sizeof(struct s_dict)); //creates hash table
	table->capacity = capacity; //initializes capacity
	//allocates memory for items in hash table
	table->items = malloc(sizeof(struct s_item*) * capacity);
	i = -1;
	while (++i < capacity) //initializes hash table to NULL
		table->items[i] = NULL;
	return (table); //returns hash table
}

//inserts an item in the hash table given its key and value

int	dictInsert(struct s_dict *dict, char *key, int value) {
	struct s_item *item; //creates item to insert
	struct s_item *temp;
	int				ans; //stores the return value

	item = malloc(sizeof(struct s_item)); //allocates memory for item
	item->key = key; //initializes item with provided values
	item->value = value;
	item->next = NULL;
	ans = hash(key) % dict->capacity; //creates the hash value of the item
	temp = dict->items[ans]; //stores the current hashed item
	if (temp == NULL) //if nothing is stored at hash insert item
		dict->items[ans] = item;
	else
	{
		while (temp->next != NULL) //gets to the end of items at hash
			temp = temp->next;
		temp->next = item; //insert item
	}
	return ans; //return the hash value
}

//finds an element in the hash table given the key

int dictSearch(struct s_dict *dict, char *key) {
	struct s_item	*item; //return value stored here

	//finds the items at the hashed value
	item = dict->items[hash(key) % dict->capacity];
	while (item != NULL) { //searches every item at the hashed key
		if (strcmp(item->key, key) == 0)
			return item->value; //if names match return item
		item = item->next; //else check the next item at the hashed key
	}
	return (-1); //if nothing is found return error
}

//finds the longest word in a dictionary

int		getmaxlen(struct s_dict *dict, char **header) {
	int maxlen; //return value
	int tempmax;
	struct s_item *temp;

	maxlen = 3; //sets minimum length of a word to 3
	for (int i = 0; i < dict->capacity; i++) { //for each item in dict
		temp = dict->items[i]; //checks each word in dict
		while(temp != NULL) { 
			tempmax = strlen(temp->key); //potential longest word
			if (tempmax > maxlen)
				maxlen = tempmax; //set return value to new val
			//adds word to header
			header[temp->value - 1] = temp->key;
			temp = temp->next;
		}
	}
	return(maxlen); //returns the maximum length
}

//returns the starting hash for the rolling hash

int		gettesthash(int maxlen, int i, char *book) {
	int		testhash; //return value

	testhash = 0; //initializes return value
	for (int j = 0; j < maxlen; j++) {
		testhash += (int) book[i + j]; //very basic hashing algorithm
	}
	return testhash; //return value
}

//compares the needle to the word in the haystack

int		hashcompare(char *book, int i, char *str) {
	int		j; //index

	j = -1; //initialize the index
	while(str[++j] && str[j] == book[i + j]) //compares letter by letter
		;
	if (!str[j]) //if they are the same return 0
		return 0;
	return -1;
}

//Compresses a book using a dictionary of most used words

char	*compress(char *book, struct s_dict *dict) {
	char			*header[256]; //header containing frequent words
	char			*newbook;
	char			*newbookOfficial;
	int				maxlen;
	int				hashlen;
	int				newbooki;
	int				check;
	int				booklen;
	int				i;
	int				h;
	struct s_item	*temp;
	int				testhash;

	i = -1;
	while(++i < 256) //initialize header
		header[i] = NULL;
	maxlen = getmaxlen(dict, header); //gets length of longest word in dict
	newbook = malloc(strlen(book) + 1); //creates new book to copy into
	newbooki = 0; //index for the new book
	booklen = strlen(book); //stores the length of the original book
	testhash = gettesthash(maxlen, 0, book); //get starting hash value
	hashlen = maxlen; //var that stores length of current hash value
	//checks for hash value at each hash length
	for(i = 0; i < booklen - 3; i++) {
		check = 0; //initializes a check if hash is found in book
		for (int j = maxlen - 1; j > 2; j--) {
			if (testhash >= 0) //sets temp to value in hash table
				temp = dict->items[testhash % dict->capacity];
			else
				temp = NULL;
			while (temp != NULL) {
				//compares hash and replaces with @ symbol
				if (hashcompare(book, i, temp->key) == 0) {
					newbook[newbooki++] = '@';
					newbook[newbooki++] = temp->value;
					check = 1; //sets check to checked
					i += j; //increments index by subindex
					temp = NULL; //resets temp value
				}
				else //checks next item in hash
					temp = temp->next;
			}
			if (check == 1) //escapes inner for loop if hash found
				break;
			testhash -= book[i + j]; //subs last letter from hash
			hashlen--; //decreases length of hash by one
		}
		if (i < booklen - 3) {
			if (check == 1) { //if matching hash found reset hash
				testhash = gettesthash(maxlen, i + 1, book);
			}
			else { //continues copying letters to new book
				newbook[newbooki++] = book[i];
					//h = 1;
					//for(int j = 0; j < hashlen - 1; j++) {
					//	h = (h * 256) % SIZE_MAX;
					//}
				//removes first letter from hash
				testhash -= book[i];
				//adds last letter until len = maxlen
				for(int k = hashlen; k <= maxlen; k++) {
					testhash += book[i + k];
				}
			}
			hashlen = maxlen; //resets hash to longest word
		}
	}
	while(book[i]) { //fills new book with remaining characters from book
		newbook[newbooki++] = book[i++];
	}
	newbook[newbooki] = '\0'; //null character at the end
	i = -1; //resets index
	booklen = 1; //resets booklen to calculate the new book
	while(header[++i]) //adds the header to length for appending later
		booklen += strlen(header[i]) + 1;
	//allocates memory for the actual compressed book
	newbookOfficial = malloc(sizeof(char) * (newbooki + 1 + booklen));
	newbookOfficial[0] = '<';
	i = -1; //resets index
	h = 0; //index for the compressed book
	while(header[++i]) { //appends information from the header to book
		for(int j = 0; header[i][j]; j++)
			newbookOfficial[++h] = header[i][j];
		newbookOfficial[++h] = ',';
	}
	newbookOfficial[h++] = '>';
	newbooki = 0; //initializes index of newbook
	while(newbook[newbooki]) //appends new book data into compressed book
		newbookOfficial[h++] = newbook[newbooki++];
	newbookOfficial[h] = '\0'; //null terminator
	free(newbook); //frees previously allocated memory
	return newbookOfficial; //returns compressed book
}
