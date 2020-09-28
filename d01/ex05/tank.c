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

//initializes stack of stacks

struct s_tank *initTank(void) {
	struct s_tank *ans; //stack of stacks

	ans = malloc(sizeof(struct s_tank)); //allocates memory for stack
	//allocates memory for stack array
	ans->stacks = malloc(sizeof(struct s_stack*) * 2);
	ans->stacks[1] = NULL; //null terminates stack of stacks
	//allocates memory for first stack in stack array
	ans->stacks[0] = malloc(sizeof(struct s_stack));
	ans->stacks[0]->sum = 0; //initializes sum
	ans->stacks[0]->elem = 0; //initializes number 
	ans->n = 1; //initializes stack index
	return (ans); //returns the stack of stacks
}

//adds energy to tank

void tankPush(struct s_tank *tank, int energy) {
	struct s_stack **temp; //temp stack for freeing memory
	struct s_elem *item; //new item to store energy
	if (energy > 100 || energy < 10) //error checking
		return;
	//if total energy exceeds capacity add new stack
	if (tank->stacks[tank->n - 1]->sum + energy > 1000) {
		tank->n++; //increases number of tanks
		temp = tank->stacks; //set temp stack to current stacks
		//allocates memory for new stack of stacks 
		tank->stacks = malloc(sizeof(struct s_stack*) * (tank->n + 1));
		tank->stacks[tank->n] = NULL; //null terminates stack
		//sets each new stack to point to the data in each old stack
		for(int i = 0; i < tank->n - 1; i++) {
			tank->stacks[i] = temp[i];
		}
		free(temp); //free the old stack of stacks
		//allocates memory for new stack
		tank->stacks[tank->n - 1] = malloc(sizeof(struct s_stack));
		//initializes the number in the stack to 0
		tank->stacks[tank->n - 1]->sum = 0;
	}
	item = malloc(sizeof(struct s_elem)); //allocates memory for  new item
	item->energy = energy; //stores energy in item
	//links new item to the top of the stack
	item->next = tank->stacks[tank->n - 1]->elem;
	tank->stacks[tank->n - 1]->elem = item; //pushes item to top of stack
	tank->stacks[tank->n - 1]->sum += energy; //adds energy to stack
	//included for testing
	//printf("%d energy added to stack %d with %d total energy\n", tank->stacks[tank->n - 1]->elem->energy, tank->n - 1, tank->stacks[tank->n - 1]->sum);
}

//removes energy from top of stack of stacks

int tankPop(struct s_tank *tank) {
	int ans; //return value
	struct s_stack **temp; //stores deleted stack
	struct s_elem *elem; //stores deleted energy
	ans = -1; //initialize return value
	//if the tank is not empty remove energy
	if (tank->stacks[tank->n - 1]->elem) {
		elem = tank->stacks[tank->n - 1]->elem; //stores top of stack
		//sets new top of stack to the next element
		tank->stacks[tank->n - 1]->elem = elem->next;
		ans = elem->energy; //sets return value
		//subtracts energy from total energy
		tank->stacks[tank->n - 1]->sum -= ans;
		//check for if you must remove a stack from the stack of stacks
		if (tank->n > 1 && tank->stacks[tank->n - 1]->sum == 0) {
			tank->n--; //remove number of stacks
			temp = tank->stacks; //store stack to be freed
			//allocates memory for smaller stack of stacks
			tank->stacks = malloc(sizeof(struct s_stack*) * (tank->n + 1));
			//null terminates stack of stacks
			tank->stacks[tank->n] = NULL;
			//copies data from old stack to new stack
			for(int i = 0; i < tank->n; i++)
				tank->stacks[i] = temp[i];
			free(temp[tank->n]); //free contents of old stack
			free(temp); //free old stack
		}
	}
	//included for testing
	//printf("%d energy removed, %d stacks remaining, current stack with %d total energy\n", ans, tank->n, tank->stacks[tank->n - 1]->sum);
	return (ans); //return energy removed
}
