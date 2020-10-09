/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printYoungest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 21:23:43 by bpace             #+#    #+#             */
/*   Updated: 2020/03/05 02:08:11 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//uses binary search to find youngest person in array

int printYoungestHelper(int *ages, int start, int end) {
	int m, l, r, max;

	if (end < start) //error checking
		return (-1);
	m = (end + start) / 2; //finds middle index
	max = ages[m]; //initializes int that stores current smallest number
	//stores smallest number left of m
	l = printYoungestHelper(ages, start, m - 1);
	//stores smallest number right of m
	r = printYoungestHelper(ages, m + 1, end);
	if (l != -1 && l < max)
		max = l; //sets return value as smallest number
	if (r != -1 && r < max)
		max = r; //sets return value as smallest number
	return (max); //returns smallest age
}

//searches through the array using divide and conquer approach

void printYoungest(int *ages, int length) {
	//prints the youngest age found in int array
	printf("Youngest : %d\n", printYoungestHelper(ages, 0, length - 1));
}
