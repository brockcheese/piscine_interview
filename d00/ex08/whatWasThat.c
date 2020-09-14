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

char	*replace(char *word, int pos, char c) {
	char *newword = strdup(word);
	if (pos < 0 || pos >= (int) strlen(word))
		return(NULL);
	newword[pos] = c;
	return (newword);
}

char	*delete(char *word, int pos) {
	char *newword;
	int		i, j;
	int len = strlen(word);

	if (pos < 0 || pos >= len)
		return(NULL);
	newword = malloc(sizeof(char) * (len));
	i = -1;
	j = -1;
	while (word[++i]) {
		if (i != pos) {
			newword[++j] = word[i];
		}
	}
	newword[++j] = '\0';
	return (newword);
}

char	*add(char *word, int pos, char c) {
	char	*newword;
	int		i, j;
	int len = strlen(word);

	if (pos < 0 || pos > len)
		return(NULL);
	newword = malloc(sizeof(char) * (len + 2));
	i = -1;
	j = -1;
	while (word[++i]) {
		if (i == pos) {
			newword[++j] = c;
		}
		newword[++j] = word[i];
	}
	newword[++j] = '\0';
	return (newword);
}

int		getmnoo(char *word, char *dicword) {
	int ans, i, j, length;

	ans = 0;
	j = 0;
	i = 0;
	while(word[i]) {

		if (word[i] && dicword[j] && (word[i] == dicword[j] || word[i + 1] == dicword[j + 1])) {
			if (word[i] != dicword[j])
				ans++;
			j++;
		}
		else {
			while (word[i] && dicword[j] && (word[i + 1] == dicword[j])) {
				j++;
			}
		}
		i++;
	}
	while (dicword[j])
		j++;
	length = i - j;
	if (length < 0)
		length = -(length);
	ans += length;
	return (ans);
}

int		noorecursion(char *word, char *dicword, int left) {
	int j, lengthw, lengthdw;
	char *temp;

	if (!(strcmp(word, dicword)))
		return (1);
	if (left == 0)
		return (0);
	lengthw = strlen(word);
	lengthdw = strlen(dicword);
	j = 0;
	for(int i = 0; word[i]; i++) {
		if (word[i] && dicword[j] && (word[i] == dicword[j]))
			j++;
		else {
			if (word[i] && dicword[j] && word[i + 1] == dicword[j + 1]) {
				temp = replace(word, i, dicword[j]);
				if (noorecursion(temp, dicword, left - 1)) {
					free(temp);
					return (1);
				}
				free(temp);
			}
			if (word[i] && (word[i + 1] == dicword[j]) && lengthw > lengthdw) {
				temp = delete(word, i);
				if (noorecursion(temp, dicword, left - 1)) {
					free(temp);
					return (1);
				}
				free(temp);
			}
			if (word[i] && dicword[j] && (word[i] == dicword[j + 1]) && lengthw < lengthdw) {
				temp = add(word, i, dicword[j]);
				if (noorecursion(temp, dicword, left - 1)) {
					free(temp);
					return (1);
				}
				free(temp);
			}
			for(int k = 0; dicword[k]; k++) {
				temp = replace(word, i, dicword[k]);
				if (noorecursion(replace(word, i, dicword[k]), dicword, left - 1)) {
					free(temp);
					return (1);
				}
				free(temp);
				if (lengthw < lengthdw) {
					temp = add(word, i, dicword[k]);
					if (noorecursion(add(word, i, dicword[k]), dicword, left - 1)) {
						free(temp);
						return (1);
					}
					free(temp);
				}
			}
			if (lengthw > lengthdw && noorecursion(delete(word, i), dicword, left - 1))
				return (1);
		}
	}
	return (0);
}

int		getnoo(char *word, char *dicword, int noo) {
	int mnoo;

	mnoo = getmnoo(word, dicword);
	if (mnoo >= noo)
		return (DEPTH + 1);
	for(int i = mnoo; i < noo; i++) {
		if (noorecursion(word, dicword, i))
			return i;
	}
	return (DEPTH + 1);
}

char	*whatWasThat(char *word, char** dictionary) {
	int i, noo, mnooi, temp;

	if (!(dictionary[1]))
		return (dictionary[0]);
	i = -1;
	noo = DEPTH + 1;
	while(dictionary[++i]) {
		temp = getnoo(word, dictionary[i], noo);
		if (temp <= noo) {
			noo = temp;
			mnooi = i;
		}
	}
	if (noo == DEPTH + 1)
		return (NULL);
	return(dictionary[mnooi]);
}
