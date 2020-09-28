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

//clones a linked list with nodes pointing to any random node

struct s_node *cloneGameBoard(struct s_node *node) {
	struct s_node *curr; //points to current node
	struct s_node *temp; //points to copied node structure
	struct s_node *ans; //return value

	if (!node) //error checking
		return (NULL);
	curr = node; //pointer to original node
	while (curr) { //inserts copies of each node after original node
		temp = malloc(sizeof(struct s_node));
		temp->value = curr->value;
		temp->next = curr->next;
		temp->random = NULL;
		curr->next = temp;
		curr = curr->next->next;
	}
	curr = node; //resets current node to original node
	//sets copied nodes random pointer to corresponding copied node
	while (curr) {
		//set copied nodes random pointer to corresponded copied node
		if (curr->random)
			curr->next->random = curr->random->next;
		curr = curr->next->next;
	}
	curr = node; //resets current node to original node
	temp = node->next; //sets start of copied structure to first node
	ans = temp; //sets return value to start of copied structure
	while (curr) { //separates copied structure from original structure
		curr->next = curr->next->next;
		temp->next = (temp->next) ? temp->next->next : NULL;
		curr = curr->next;
		temp = temp->next;
	}
	return (ans); //return copied structure
}
