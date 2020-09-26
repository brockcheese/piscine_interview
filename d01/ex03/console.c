/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:30:32 by bpace             #+#    #+#             */
/*   Updated: 2020/03/03 07:26:25 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//initializes the stack

struct s_stack *stackInit(void) {
	struct s_stack *ans; //declares stack

	ans = malloc(sizeof(struct s_stack)); //allocates memory for stack
	ans->item = NULL; //initializes top of stack to NULL
	return (ans); //return empty stack
}

//removes the top item from the stack and return it

int pop(struct s_stack *stack) {
	struct s_item *ans; //node to store top of stack
	int	idx; //index

	ans = stack->item; //sets return value to the top of the stack
	idx = -1; //initializes index
	if (ans != NULL) { //resets top of stack to next node
		stack->item = ans->next;
		idx = ans->idx;
	}
	free(ans); //free top of stack
	return (idx); //returns index where last chunk was added
}

//adds a word to the top of the stack

void push(struct s_stack *stack, int idx) {
	struct s_item *new; //node to store new index

	new = malloc(sizeof(struct s_item)); //allocates memory for new node
	new->idx = idx; //store idx in node
	new->next = stack->item; //sets next node to top of stack
	stack->item = new; //resets top of stack to new node
}

//program that can store and append messages

char *console(void) {
	char *lineptr; //printed message
	char *temp; //temporary message
	int i; //index
	int num; //length of appended line
	size_t max = 256; //integer storing the maximum length of the message
	struct s_stack *stack; //new stack

	stack = stackInit(); //initialize stack
	temp = malloc(sizeof(char) * max); //allocates memory for messages
	lineptr = malloc(sizeof(char) * max);
	bzero(lineptr, max); //initializes printed message
	i = 0; //sets index to 0
	push(stack, i); //push index onto stack
	printf("?: "); //print prompt
	//adds each chunk of text to the printed message
	while((num = getline(&temp, &max, stdin)) > 0) {
		//undoes the last chunk of text appended to the message
		if (!(strcmp(temp, "UNDO\n"))) {
			i = pop(stack);
			for(int j = i; lineptr[j]; j++)
				lineptr[j] = '\0';
		}
		//returns completed message and frees the stack
		else if (!(strcmp(temp, "SEND\n"))) {
			while(pop(stack) != -1);
			free(stack);
			free(temp);
			return (lineptr);
		}
		//appends chunk of text to printed value
		else {
			strncpy(lineptr + i, temp, num - 1);
			push(stack, i);
			i += num - 1;
		}
		printf("%s\n\n?: ", lineptr); //prints current message
	}
	return (NULL); //ends program
}
