/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimumMoves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:22:28 by bpace             #+#    #+#             */
/*   Updated: 2020/02/26 21:55:48 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//finds the minimum amount of moves to complete a game of snakes and ladders

int minimumMoves(struct s_node *node) {
	int minn; //find minimum moves in order
	int minr; //find minimum moves random

	if (!node || node->isFinal == -1) //error checking
		return (-1);
	if (node->isFinal == 1) //if no moves are required return
		return (0);
	node->isFinal = -1; //breadcrumb to track if program has been there
	//recursively find the number of moves by traversing in order
	minn = minimumMoves(node->next) + 1;
	//recursively find the number of moves using the random node
	minr = minimumMoves(node->random) + 1;
	node->isFinal = 0; //reset breadcrumb
	if (minn == 0) { //if minn returns an error return recursive moves
		if (minr == 0) //error check
			return -1;
		return (minr); //return amount of moves recursively
	}
	if (minr == 0) //if minr returns an error return moves in order
		return (minn);
	return ((minn < minr) ? minn : minr); //return path with least moves
}
