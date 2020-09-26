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

//uses a circular doubly linked list to translate a code

char	*precious(int *text, int size) {
	int i; //index
	struct s_node *temp; //temporary node storage
	struct s_node *curr; //current node in linked list
	char *ans; //the returned value

	i = -1; //initialize index
	temp = NULL; //initialize temp node storage
	ans = malloc(sizeof(char) * size + 1); //allocates mem for return val
	ans[size] = '\0'; //null terminates return value
	while(CS[++i]) { //create node for each item
		curr = malloc(sizeof(struct s_node));
		curr->c = CS[i];
		curr->prev = temp;
		curr->next = NULL;
		if (temp != NULL)
			temp->next = curr;
		temp = curr;
	}
	while(curr->prev) { //resets linked list at the beginning
		curr = curr->prev;
	}
	curr->prev = temp; //links the end of the list to the beginning
	temp->next = curr; //links the beginning of the list to the end
	i = -1; //reset the index
	while(++i < size) { //for each integer passed
		if (text[i] > 0) { //moves forward in the list
			while (text[i]-- != 0)
				curr = curr->next;
		}
		else if (text[i] < 0) { //moves backward in the list
			while (text[i]++ != 0)
				curr = curr->prev;
		}
		ans[i] = curr->c; //sets the letter to the stored value
	}
	return (ans); //returns the string
}
