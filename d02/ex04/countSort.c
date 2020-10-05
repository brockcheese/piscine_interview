/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:44:07 by bpace             #+#    #+#             */
/*   Updated: 2020/02/27 18:28:33 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//simple count sort

void countSort(unsigned char *utensils, int n) {
	int count[n]; //array that stores the number of similar values

	for(int i = 0; i < n; i++) {
		count[i] = 0; //initializes array
	}
	for(int i = 0; i < n; i++) {
		count[utensils[i]]++; //counts number of values with same num
	}
	int j = 0; //new index
	for(int i = 0; utensils[j] && i < n; i++) {
		while(count[i]--)
			utensils[j++] = i; //sets values to values in count
	}
}
