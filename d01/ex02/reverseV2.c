/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:39:49 by bpace             #+#    #+#             */
/*   Updated: 2020/02/26 15:03:19 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//initializes the stack

struct s_stack *stackInit(void) {
	struct s_stack *ans; //return value

	ans = malloc(sizeof(struct s_stack)); //allocated memory for the stack
	ans->item = NULL; //initializes the current item to NULL
	return (ans); //return the stack
}

//removes the top item from the stack and returns it

void *pop(struct s_stack *stack) {
	struct s_item *ans; //return value

	ans = stack->item; //sets return value to top of the stack
	if (ans != NULL) //sets top of stack to next item
		stack->item = ans->next;
	return (ans); //return top of the stack
}

//add a word to the top of the stack

void push(struct s_stack *stack, char *word) {
	struct s_item *new; //node to store new word

	new = malloc(sizeof(struct s_item)); //allocates memory for new node
	new->word = word; //stores the word in node
	new->next = stack->item; //set next to equal the current top of stack
	stack->item = new; //sets top of stack to new node
}

//iteratively reverses a sentence using a stack

void printReverseV2(struct s_node *lst) {
	struct s_node *temp; //stores value to be freed
	struct s_stack *stack; //stores the stack
	struct s_item *item; //stores current node

	stack = stackInit(); //creates stack
	while (lst) { //pushes each lst item onto the stack
		push(stack, lst->word);
		temp = lst;
		lst = lst->next;
		free(temp);
	}
	item = pop(stack); //sets top of stack to current item
	while(item) { //prints out each word
		if (item->next == NULL) //prints last word
			printf("%s\n", item->word);
		else //prints current word to console
			printf("%s ", item->word);
		free(item); //frees node
		item = pop(stack); //sets node to the next item
	}
	free(stack); //frees the stack
}
