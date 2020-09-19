/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 22:22:45 by bpace             #+#    #+#             */
/*   Updated: 2020/02/21 15:50:51 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// Sorts the given array based on the name of the paintings.

void	sortArtsHelper(struct s_art **arts, int start, int end) {
	int i;
	int p;
	struct s_art*	pivot;
	struct s_art*	temp;
	char*			check1; //included for testing
	char*			check2; //included for testing

	if (start >= end) //checks if the starting index is past the end index
		return;
	pivot = arts[end]; //sets the pivot to the last index
	p = start; //initializes p to the starting index
	i = start; //initializes i to the starting index
	while(i <= end) {
		check1 = arts[i]->name; //included for testing
		check2 = pivot->name;	//included for testing
		//if the indexed name is less than the pivot name
		if (strcmp(arts[i]->name, pivot->name) <= 0) { 
			temp = arts[i]; //swap items at the index and pivot
			arts[i] = arts[p];
			arts[p] = temp;
			p++;
		}
		i++;
	}
	sortArtsHelper(arts, start, p-2); //recurse everything before the pivot
	sortArtsHelper(arts, p, end); //recurse everything after the pivot
}

void	sortArts(struct s_art **arts) {
	int len; //integer for storing length

	len = -1; //length initialization
	while(arts[++len]) //counts the length of the array
		;
	sortArtsHelper(arts, 0, len - 1); //begins recursive sort
}
