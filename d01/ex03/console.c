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

struct s_stack *stackInit(void) {
	struct s_stack *ans;

	ans = malloc(sizeof(struct s_stack));
	ans->item = NULL;
	return (ans);
}

int pop(struct s_stack *stack) {
	struct s_item *ans;
	int	idx;

	ans = stack->item;
	idx = -1;
	if (ans != NULL) {
		stack->item = ans->next;
		idx = ans->idx;
	}
	free(ans);
	return (idx);
}

void push(struct s_stack *stack, int idx) {
	struct s_item *new;

	new = malloc(sizeof(struct s_item));
	new->idx = idx;
	new->next = stack->item;
	stack->item = new;
}

char *console(void) {
	char *lineptr;
	char *temp;
	int i;
	int num;
	size_t max = 256;
	struct s_stack *stack;

	stack = stackInit();
	temp = malloc(sizeof(char) * max);
	lineptr = malloc(sizeof(char) * max);
	bzero(lineptr, max);
	i = 0;
	push(stack, i);
	printf("?: ");
	while((num = getline(&temp, &max, stdin)) > 0) {
		if (!(strcmp(temp, "UNDO\n"))) {
			i = pop(stack);
			for(int j = i; lineptr[j]; j++)
				lineptr[j] = '\0';
		}
		else if (!(strcmp(temp, "SEND\n"))) {
			while(pop(stack) != -1);
			free(stack);
			free(temp);
			return (lineptr);
		}
		else {
			strncpy(lineptr + i, temp, num - 1);
			push(stack, i);
			i += num - 1;
		}
		printf("%s\n\n?: ", lineptr);
	}
	return (NULL);
}
