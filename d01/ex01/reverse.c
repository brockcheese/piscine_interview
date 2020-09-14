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

void printReverseHelper(struct s_node *lst) {
	if (lst == NULL)
		return;
	if (lst->next == NULL)
		printf("%s", lst->word);
	else {
		printReverseHelper(lst->next);
		printf(" %s", lst->word);
	}
}

void printReverse(struct s_node *lst) {
	printReverseHelper(lst);
	printf("\n");
}
