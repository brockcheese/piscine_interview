/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 02:53:24 by bpace             #+#    #+#             */
/*   Updated: 2020/02/26 03:05:19 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*precious(int *text, int size) {
	int i;
	struct s_node *temp;
	struct s_node *curr;
	char *ans;

	i = -1;
	temp = NULL;
	ans = malloc(sizeof(char) * size + 1);
	ans[size] = '\0';
	while(CS[++i]) {
		curr = malloc(sizeof(struct s_node));
		curr->c = CS[i];
		curr->prev = temp;
		curr->next = NULL;
		if (temp != NULL)
			temp->next = curr;
		temp = curr;
	}
	while(curr->prev) {
		curr = curr->prev;
	}
	curr->prev = temp;
	temp->next = curr;
	i = -1;
	while(++i < size) {
		if (text[i] > 0) {
			while (text[i]-- != 0)
				curr = curr->next;
		}
		else if (text[i] < 0) {
			while (text[i]++ != 0)
				curr = curr->prev;
		}
		ans[i] = curr->c;
	}
	return (ans);
}
