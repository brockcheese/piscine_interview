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

struct s_stack *stackInit(void) {
	struct s_stack *ans;

	ans = malloc(sizeof(struct s_stack));
	ans->item = NULL;
	return (ans);
}

void *pop(struct s_stack *stack) {
	struct s_item *ans;

	ans = stack->item;
	if (ans != NULL)
		stack->item = ans->next;
	return (ans);
}

void push(struct s_stack *stack, char *word) {
	struct s_item *new;

	new = malloc(sizeof(struct s_item));
	new->word = word;
	new->next = stack->item;
	stack->item = new;
}

void printReverseV2(struct s_node *lst) {
	struct s_node *temp;
	struct s_stack *stack;
	struct s_item *item;

	stack = stackInit();
	while (lst) {
		push(stack, lst->word);
		temp = lst;
		lst = lst->next;
		free(temp);
	}
	item = pop(stack);
	while(item) {
		if (item->next == NULL)
			printf("%s\n", item->word);
		else
			printf("%s ", item->word);
		free(item);
		item = pop(stack);
	}
	free(stack);
}
