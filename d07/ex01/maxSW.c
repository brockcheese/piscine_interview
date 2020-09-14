/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxSW.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 02:27:32 by bpace             #+#    #+#             */
/*   Updated: 2020/03/06 04:00:40 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_deque *dequeInit(void) {
	struct s_deque *ans;

	ans = malloc(sizeof(struct s_deque));
	ans->first = NULL;
	ans->last = NULL;
	return (ans);
}

void	pushFront(struct s_deque *deque, int value) {
	struct s_dequeNode *ans;

	ans = malloc(sizeof(struct s_dequeNode));
	ans->value = value;
	ans->prev = NULL;
	ans->next = deque->first;
	if (deque->first)
		deque->first->prev = ans;
	else
		deque->last = ans;
	deque->first = ans;
}

void	pushBack(struct s_deque *deque, int value) {
	struct s_dequeNode *ans;

	ans = malloc(sizeof(struct s_dequeNode));
	ans->value = value;
	ans->prev = deque->last;
	ans->next = NULL;
	if (deque->last)
		deque->last->next = ans;
	else
		deque->first = ans;
	deque->last = ans;
}

int		popFront(struct s_deque *deque) {
	int ans;
	struct s_dequeNode *temp;

	if (!deque->first)
		return (INT_MIN);
	ans = deque->first->value;
	temp = deque->first;
	deque->first = deque->first->next;
	free (temp);
	if (deque->first)
		deque->first->prev = NULL;
	return (ans);
}

int		popBack(struct s_deque *deque) {
	int ans;
	struct s_dequeNode *temp;

	if (!deque->last)
		return (INT_MIN);
	ans = deque->last->value;
	temp = deque->last;
	deque->last = deque->last->prev;
	free (temp);
	if (deque->last)
		deque->last->next = NULL;
	return (ans);
}

struct s_max *maxSlidingWindow(int *arr, int n, int k) {
	struct s_max *ans;
	struct s_deque *deque;
	int i, j;

	ans = malloc(sizeof(struct s_max));
	ans->length = n - (k - 1);
	ans->max = malloc(sizeof(int) * ans->length);
	deque = dequeInit();
	j = -1;
	for (i = 0; i < k; i++) {
		while (deque->last && arr[i] >= arr[deque->last->value])
			popBack(deque);
		pushBack(deque, i);
	}
	for (; i < n; i++) {
		ans->max[++j] = arr[deque->first->value];
		while(deque->first && deque->first->value <= i - k)
			popFront(deque);
		while(deque->last && arr[i] >= arr[deque->last->value])
			popBack(deque);
		pushBack(deque, i);
	}
	ans->max[++j] = arr[deque->first->value];
	while(deque->first)
		popFront(deque);
	free(deque);
	return (ans);
}
