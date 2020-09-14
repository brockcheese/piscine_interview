/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyGameBoard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:34:16 by bpace             #+#    #+#             */
/*   Updated: 2020/02/26 20:58:06 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_node *cloneGameBoard(struct s_node *node) {
	struct s_node *curr;
	struct s_node *temp;
	struct s_node *ans;

	if (!node)
		return (NULL);
	curr = node;
	while (curr) {
		temp = malloc(sizeof(struct s_node));
		temp->value = curr->value;
		temp->next = curr->next;
		temp->random = NULL;
		curr->next = temp;
		curr = curr->next->next;
	}
	curr = node;
	while (curr) {
		if (curr->random)
			curr->next->random = curr->random->next;
		curr = curr->next->next;
	}
	curr = node;
	temp = node->next;
	ans = temp;
	while (curr) {
		curr->next = curr->next->next;
		temp->next = (temp->next) ? temp->next->next : NULL;
		curr = curr->next;
		temp = temp->next;
	}
	return (ans);
}
