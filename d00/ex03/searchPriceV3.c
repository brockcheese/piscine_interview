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

size_t hash(char *input) {
	size_t	ans;

	ans = 0;
	for (unsigned long i = 0; i < strlen(input); i++) {
		ans = (256*ans + input[i]) % SIZE_MAX;
	}
	return ans;
}

struct s_dict *dictInit(int capacity) {
	struct s_dict	*table;
	int				i;

	table = malloc(sizeof(struct s_dict));
	table->capacity = capacity;
	table->items = malloc(sizeof(struct s_item*) * capacity);
	i = -1;
	while (++i < capacity)
		table->items[i] = NULL;
	return (table);
}

int	dictInsert(struct s_dict *dict, char *key, struct s_art *value) {
	struct s_item *item;
	struct s_item *temp;
	int				ans;

	item = malloc(sizeof(struct s_item));
	item->key = key;
	item->value = value;
	item->next = NULL;
	ans = hash(key) % dict->capacity;
	temp = dict->items[ans];
	if (temp == NULL)
		dict->items[ans] = item;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = item;
	}
	return ans;
}

struct s_art	*dictSearch(struct s_dict *dict, char *key) {
	struct s_item	*item;

	item = dict->items[hash(key) % dict->capacity];
	while (item != NULL) {
		if (strcmp(item->key, key) == 0)
			return item->value;
		item = item->next;
	}
	return (NULL);
}

int				searchPrice(struct s_dict *dict, char *name) {
	struct s_art	*value;

	value = dictSearch(dict, name);
	if (value == NULL)
		return -1;
	return (value->price);
}
