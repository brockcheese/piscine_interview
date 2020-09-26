/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:26:47 by bpace             #+#    #+#             */
/*   Updated: 2020/02/26 14:35:42 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//helper function for recursion

void printReverseHelper(struct s_node *lst) {
	if (lst == NULL) //escape recursion if lst is done
		return;
	if (lst->next == NULL) //print last word
		printf("%s", lst->word);
	else { //recursion for the rest of the words
		printReverseHelper(lst->next);
		printf(" %s", lst->word); //prints current word
	}
}

//prints sentence in reverse order

void printReverse(struct s_node *lst) {
	printReverseHelper(lst); //sends to helper function
	printf("\n"); //prints newline
}
