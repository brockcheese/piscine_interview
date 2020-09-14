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

size_t hash(char *input) {
	size_t	ans;

	ans = 0;
	for (unsigned long i = 0; i < strlen(input); i++) {
		ans = (ans + input[i]);
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

int	dictInsert(struct s_dict *dict, char *key, int value) {
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

int dictSearch(struct s_dict *dict, char *key) {
	struct s_item	*item;

	item = dict->items[hash(key) % dict->capacity];
	while (item != NULL) {
		if (strcmp(item->key, key) == 0)
			return item->value;
		item = item->next;
	}
	return (-1);
}

int		getmaxlen(struct s_dict *dict, char **header) {
	int maxlen;
	int tempmax;
	struct s_item *temp;

	maxlen = 3;
	for (int i = 0; i < dict->capacity; i++) {
		temp = dict->items[i];
		while(temp != NULL) {
			tempmax = strlen(temp->key);
			if (tempmax > maxlen)
				maxlen = tempmax;
			header[temp->value - 1] = temp->key;
			temp = temp->next;
		}
	}
	return(maxlen);
}

int		gettesthash(int maxlen, int i, char *book) {
	int		testhash;

	testhash = 0;
	for (int j = 0; j < maxlen; j++) {
		testhash += (int) book[i + j];
	}
	return testhash;
}

int		hashcompare(char *book, int i, char *str) {
	int		j;

	j = -1;
	while(str[++j] && str[j] == book[i + j])
		;
	if (!str[j])
		return 0;
	return -1;
}

char	*compress(char *book, struct s_dict *dict) {
	char			*header[256];
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
	while(++i < 256)
		header[i] = NULL;
	maxlen = getmaxlen(dict, header);
	newbook = malloc(strlen(book) + 1);
	newbooki = 0;
	booklen = strlen(book);
	testhash = gettesthash(maxlen, 0, book);
	hashlen = maxlen;
	for(i = 0; i < booklen - 3; i++) {
		check = 0;
		for (int j = maxlen - 1; j > 2; j--) {
			if (testhash >= 0)
				temp = dict->items[testhash % dict->capacity];
			else
				temp = NULL;
			while (temp != NULL) {
				if (hashcompare(book, i, temp->key) == 0) {
					newbook[newbooki++] = '@';
					newbook[newbooki++] = temp->value;
					check = 1;
					i += j;
					temp = NULL;
				}
				else
					temp = temp->next;
			}
			if (check == 1)
				break;
			testhash -= book[i + j];
			hashlen--;
		}
		if (i < booklen - 3) {
			if (check == 1) {
				testhash = gettesthash(maxlen, i + 1, book);
			}
			else {
				newbook[newbooki++] = book[i];
					//h = 1;
					//for(int j = 0; j < hashlen - 1; j++) {
					//	h = (h * 256) % SIZE_MAX;
					//}
				testhash -= book[i];
				for(int k = hashlen; k <= maxlen; k++) {
					testhash += book[i + k];
				}
			}
			hashlen = maxlen;
		}
	}
	while(book[i]) {
		newbook[newbooki++] = book[i++];
	}
	newbook[newbooki] = '\0';
	i = -1;
	booklen = 1;
	while(header[++i])
		booklen += strlen(header[i]) + 1;
	newbookOfficial = malloc(sizeof(char) * (newbooki + 1 + booklen));
	newbookOfficial[0] = '<';
	i = -1;
	h = 0;
	while(header[++i]) {
		for(int j = 0; header[i][j]; j++)
			newbookOfficial[++h] = header[i][j];
		newbookOfficial[++h] = ',';
	}
	newbookOfficial[h++] = '>';
	newbooki = 0;
	while(newbook[newbooki])
		newbookOfficial[h++] = newbook[newbooki++];
	newbookOfficial[h] = '\0';
	free(newbook);
	return newbookOfficial;
}
