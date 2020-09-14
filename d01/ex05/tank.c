/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:35:20 by bpace             #+#    #+#             */
/*   Updated: 2020/02/26 19:40:25 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_tank *initTank(void) {
	struct s_tank *ans;

	ans = malloc(sizeof(struct s_tank));
	ans->stacks = malloc(sizeof(struct s_stack*) * 2);
	ans->stacks[1] = NULL;
	ans->stacks[0] = malloc(sizeof(struct s_stack));
	ans->stacks[0]->sum = 0;
	ans->stacks[0]->elem = 0;
	ans->n = 1;
	return (ans);
}

void tankPush(struct s_tank *tank, int energy) {
	struct s_stack **temp;
	struct s_elem *item;
	if (energy > 100 || energy < 10)
		return;
	if (tank->stacks[tank->n - 1]->sum + energy > 1000) {
		tank->n++;
		temp = tank->stacks;
		tank->stacks = malloc(sizeof(struct s_stack*) * (tank->n + 1));
		tank->stacks[tank->n] = NULL;
		for(int i = 0; i < tank->n - 1; i++) {
			tank->stacks[i] = temp[i];
		}
		free(temp);
		tank->stacks[tank->n - 1] = malloc(sizeof(struct s_stack));
		tank->stacks[tank->n - 1]->sum = 0;
	}
	item = malloc(sizeof(struct s_elem));
	item->energy = energy;
	item->next = tank->stacks[tank->n - 1]->elem;
	tank->stacks[tank->n - 1]->elem = item;
	tank->stacks[tank->n - 1]->sum += energy;
	//printf("%d energy added to stack %d with %d total energy\n", tank->stacks[tank->n - 1]->elem->energy, tank->n - 1, tank->stacks[tank->n - 1]->sum);
}

int tankPop(struct s_tank *tank) {
	int ans;
	struct s_stack **temp;
	struct s_elem *elem;
	ans = -1;
	if (tank->stacks[tank->n - 1]->elem) {
		elem = tank->stacks[tank->n - 1]->elem;
		tank->stacks[tank->n - 1]->elem = elem->next;
		ans = elem->energy;
		tank->stacks[tank->n - 1]->sum -= ans;
		if (tank->n > 1 && tank->stacks[tank->n - 1]->sum == 0) {
			tank->n--;
			temp = tank->stacks;
			tank->stacks = malloc(sizeof(struct s_stack*) * (tank->n + 1));
			tank->stacks[tank->n] = NULL;
			for(int i = 0; i < tank->n; i++)
				tank->stacks[i] = temp[i];
			free(temp[tank->n]);
			free(temp);
		}
	}
	//printf("%d energy removed, %d stacks remaining, current stack with %d total energy\n", ans, tank->n, tank->stacks[tank->n - 1]->sum);
	return (ans);
}
