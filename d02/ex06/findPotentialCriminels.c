/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPotentialCriminels.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:24:52 by bpace             #+#    #+#             */
/*   Updated: 2020/03/05 04:46:48 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

//returns the integer description given the completed data structure

int getDescription(struct s_info *info) {
	int description; //returned value
	int tens; //tens place

	tens = 1; //initalizes tens place
	description = 0; //initializes return value
	description += tens * info->piercing; //adds piercing info
	tens *= 10; //moves tens place
	description += tens * info->tattoo; //adds tattoo info
	tens *= 10; //moves tens place
	description += tens * info->glasses; //adds glasses info
	tens *= 10; //moves tens place
	description += tens * info->eyeColor; //adds eye color info
	tens *= 10; //moves tens place
	description += tens * info->hairColor; //adds hair color info
	tens *= 10; //moves tens place
	description += tens * info->height; //adds height info
	tens *= 10; //moves tens place
	description += tens * info->gender; //adds geder info
	return (description);
}

//count sorts for criminals

void countCriminals(struct s_criminal **criminals, int tens) {
	int count[10]; //array that stores count for each digit
	int n;

	for(int i = 0; i < 10; i++)
		count[i] = 0; //initializes count array
	for(n = 0; criminals[n]; n++) //increments count at tens place
		count[(criminals[n]->description / tens) % 10]++;
	struct s_criminal *output[n]; //creates struct array
	for(int i = 1; i < 10; i++) //sets the array to store indexes
		count[i] += count[i - 1];
	for(int i = n - 1; i > -1; i--) //inserts nodes at their correct index
		output[--(count[(criminals[i]->description / tens) % 10])] = criminals[i];
	for(int i = 0; i < n; i++) //reassigns original copy to the sorted copy
		criminals[i] = output[i];
}

//sorts the array based on the integer description in an increasing order

void sortCriminals(struct s_criminal **criminals) {
	int tens; //tens place

	tens = 1; //initialize tens place
	for(int j = 0; j <= 6; j++) {
		countCriminals(criminals, tens); //count sort each tens place
		tens *= 10; //moves tens place
	}
}

//binary search to find item with matching description

int					binarySearch(struct s_criminal **criminals, int start, int end, int description) {
	if (start > end) //error checking
		return (-1);
	int m = (start + end) / 2; //stores middle index
	int check = criminals[m]->description; //stores description of m index
	if (check == description)
		return (m); //exit condition
	if (check > description) //searches left half of array
		return binarySearch(criminals, start, m - 1, description);
	//searches right half of array
	return binarySearch(criminals, m + 1, end, description);
}

//searched through sorted array for criminal given a numerical description

struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info) {
	int description; //stores integer description
	int n;
	int first;
	int last;
	struct s_criminal **ans;

	description = getDescription(info); //gets description from struct passed
	for(n = 0; criminals[n]; n++); //counts items in struct array
	//searches array for criminals matching description
	first = binarySearch(criminals, 0, n - 1, description);
	if (first == -1) //error checking
		return (NULL);
	while(first != 0 && description == criminals[first - 1]->description)
		first--; //sets first index to first item matching description
	for(last = first + 1; criminals[last] && criminals[last]->description == description; last++)
		; //finds index of the last matching description
	//allocates memory for return value
	ans = malloc(sizeof(struct s_criminal*) * (last - first + 1));
	n = first; //sets index to store items
	for(int i = 0; i <= last - first; i++)
		ans[i] = criminals[n++]; //copy nodes to return array
	ans[last - first] = NULL; //null terminate the array
	return (ans); //return the array of searched items
}
