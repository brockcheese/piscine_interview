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

int		getNOC(char **dictionary, int d) {
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	int noc = 0;
	char c, t;
	c = dictionary[0][d];
	if (c != '\0' && strchr(alphabet, c ) != NULL)
		noc++;
	for (long long i = 0; dictionary[i]; i++) {
		t = dictionary[i][d];
		if (t != c && t != '\0' && strchr(alphabet, t) != NULL) {
			noc++;
			c = t;
		}
	}
	return (noc);
}

void		createTrieHelper(int d, char **dictionary, struct s_node *curr) {
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	char **subdictionary;
	int noc, j;
	long long start, s, i;
	char c, t;

	if (!dictionary[0])
		return;
	noc = getNOC(dictionary, d);
	curr->child = malloc(sizeof(struct s_node*) * (noc + 1));
	curr->child[noc] = NULL;
	j = -1;
	c = dictionary[0][d];
	start = 0;
	if (c != '\0' && strchr(alphabet, c) != NULL) {
		curr->child[++j] = malloc(sizeof(struct s_node));
		curr->child[j]->c = c;
		curr->child[j]->isWord = (dictionary[0][d + 1] == '\0') ? 1 : 0;
	}
	for (i = 1; dictionary[i - 1]; i++) {
		if (dictionary[i])
			t = dictionary[i][d];
		if (t != c || !dictionary[i]) {
			//if (c != '\0' && strchr(alphabet, c) != NULL && j > -1) {
			if (j > -1) {
				subdictionary = malloc(sizeof(char*) * (i - start + 1));
				subdictionary[i - start] = NULL;
				s = -1;
				for (long long k = start; k < i; k++) {
					subdictionary[++s] = dictionary[k];
				}
				createTrieHelper(d + 1, subdictionary, curr->child[j]);
				free(subdictionary);
			}
			if (t != '\0' && strchr(alphabet, t) != NULL && dictionary[i]) {
				start = i;
				curr->child[++j] = malloc(sizeof(struct s_node));
				curr->child[j]->c = t;
				curr->child[j]->isWord = (dictionary[i][d + 1] == '\0') ? 1 : 0;
			}
			c = t;
		}
		if (t == '\0' && dictionary[i]) {
			curr->isWord = 1;
			start++;
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


struct s_trie *createTrie(char **dictionary) {
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	char **subdictionary;
	struct s_trie *ans;
	int noc, j;
	long long start, s;
	char c, t;

	ans = malloc(sizeof(struct s_trie));
	ans->node = malloc(sizeof(struct s_node));
	ans->node->c = '\0';
	ans->node->isWord = 0;
	if (!dictionary[0])
		return (ans);
	noc = getNOC(dictionary, 0);
	ans->node->child = malloc(sizeof(struct s_node*) * (noc + 1));
	ans->node->child[noc] = NULL;
	j = -1;
	c = dictionary[0][0];
	start = 0;
	if (c != '\0' && strchr(alphabet, c) != NULL) {
		ans->node->child[++j] = malloc(sizeof(struct s_node));
		ans->node->child[j]->c = c;
		ans->node->child[j]->isWord = (dictionary[0][1] == '\0') ? 1 : 0;
	}
	for (long long i = 0; dictionary[i]; i++) {
		t = dictionary[i][0];
		if (t != c) {
			if (j > -1) {
				subdictionary = malloc(sizeof(char*) * (i - start + 1));
				subdictionary[i - start] = NULL;
				s = -1;
				for (long long k = start; k < i; k++) {
					subdictionary[++s] = dictionary[k];
				}
				createTrieHelper(1, subdictionary, ans->node->child[j]);
				free(subdictionary);
			}
			if (t != '\0' && strchr(alphabet, t) != NULL) {
				start = i;
				ans->node->child[++j] = malloc(sizeof(struct s_node));
				ans->node->child[j]->c = t;
				ans->node->child[j]->isWord = (dictionary[i][1] == '\0') ? 1 : 0;
			}
			c = t;
		}
	}
	return (ans);
}

char *understandHelper(int num, char *word, struct s_node *curr) {
	char *temp;
	if (word[num] == '\0'){
		if (curr->isWord) {
			return (word);
		}
		else
			return (NULL);
	}
	for(int i = 0; curr->child && curr->child[i]; i++) {
		if (word[num] == curr->child[i]->c) {
			return(understandHelper(num + 1, word, curr->child[i]));
		}
		if (word[num] == '?') {
			word[num] = curr->child[i]->c;
			temp = understandHelper(num + 1, word, curr->child[i]);
			if (temp)
				return (temp);
			word[num] = '?';
		}
	}
	return (NULL);
}

char *understand(char *word, struct s_trie *trie) {
	char *ans;
	char *oldword;

	oldword = strdup(word);
	ans = understandHelper(0, oldword, trie->node);
	if (ans == NULL) {
		return (oldword);
	}
	return (ans);
}


