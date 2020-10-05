/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:44:03 by bpace             #+#    #+#             */
/*   Updated: 2020/02/27 02:54:45 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//uses a bubble sort to sort a linked list with chunks of the same number

void sortStones(struct s_stone **stone) {
	struct s_stone *start; //stores the rest of array to sort
	struct s_stone *leftswap; //stores leftmost point of chunk
	struct s_stone *rightswap; //stores rightmost point of chunk
	struct s_stone *middleswap; //stores middlemost point of chunk
	int max = -1; //stores the biggest number in the list
	int check = 0; //checks if the list is sorted

	if (*stone == NULL || (*stone)->next == NULL) //error checking
		return;
	start = *stone; //initalize start to first node in list
	while(start) { //find the maximum number in the list
		max = (start->size > max) ? start->size : max;
		start = start->next;
	}
	max++; //increments largest number
	while(check == 0) {
		check = 1; //sets check to sorted
		leftswap = *stone; //sets left pointer to start of list
		while (leftswap->next && leftswap->size != max) {
			//sets middle pointer to left pointer
			middleswap = leftswap;
			//sets middle pointer to end of chunk
			while (middleswap->next && middleswap->next->size == leftswap->size)
				middleswap = middleswap->next;
			//sets right pointer to middle pointer
			rightswap = middleswap;
			//sets right pointer to ened of next chunk
			while (rightswap->next && rightswap->next->size == middleswap->next->size)
				rightswap = rightswap->next;
			//swaps chunks
			if (leftswap->size > rightswap->size) {
				check = 0; //reset the check
				//if first chunk is start set start to start of second chunk
				if (leftswap == (*stone))
					*stone = middleswap->next;
				else
					start->next = middleswap->next;
				//connects end of first chunk to start of third chunk 
				middleswap->next = rightswap->next;
				//connects end of second chunk to start of first chunk
				rightswap->next = leftswap;
				//sets new start of list to be end of second chunk
				start = rightswap;
			}
			else { //sets new start of list
				start = middleswap;
				leftswap = (start && start->next) ? start->next : start;
			}
		}
		max = leftswap->size;
	}
}
