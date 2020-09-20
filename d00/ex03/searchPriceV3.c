/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 01:38:02 by bpace             #+#    #+#             */
/*   Updated: 2020/02/24 15:00:03 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//creates a hash product from the input

size_t hash(char *input) {
	size_t	ans; //return value

	ans = 0; //initialize return value
	for (unsigned long i = 0; i < strlen(input); i++) {
		ans = (256*ans + input[i]) % SIZE_MAX; //creates hash value
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

int	dictInsert(struct s_dict *dict, char *key, struct s_art *value) {
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

struct s_art	*dictSearch(struct s_dict *dict, char *key) {
	struct s_item	*item; //return value stored here
	
	//finds the items at the hashed value
	item = dict->items[hash(key) % dict->capacity];
	while (item != NULL) { //searches every item at the hashed key
		if (strcmp(item->key, key) == 0)
			return item->value; //if names match return item 
		item = item->next; //else check the next item at the hashed key
	}
	return (NULL); //if nothing is found return NULL
}

//searches the price of a work of art using a hash table 

int				searchPrice(struct s_dict *dict, char *name) {
	struct s_art	*value; //return value stored here

	value = dictSearch(dict, name); //searches the dictonary for the item
	if (value == NULL) //error check
		return -1;
	return (value->price); //returns price
}
