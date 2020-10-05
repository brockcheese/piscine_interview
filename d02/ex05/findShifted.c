/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findShifted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:46:13 by bpace             #+#    #+#             */
/*   Updated: 2020/02/27 19:07:16 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//finds beginning of shifted array using binary search

int		findPivot(int *rocks, int start, int end) {
	if (start > end) //exit condition
		return (-1);
	if (start == end) //returns answer
		return (start);
	int mid = (start + end) / 2; //initalizes middle point of the array
	if (mid < end && rocks[mid] > rocks[mid + 1])
		return mid; //returns answer
	if (mid > start && rocks[mid] < rocks[mid - 1])
		return mid; //returns answer
	if (rocks[start] >= rocks[mid]) //searches in left half of array
		return findPivot(rocks, start, mid - 1);
	return findPivot(rocks, mid + 1, end); //searches right half of array
}

//binary search to find specific value

int		binarySearch(int *rocks, int start, int end, int value) {
	if (start > end) //error checking
		return (-1);
	int mid = (start + end) / 2; //initializes middle point to middle index
	if (rocks[mid] == value) //return answer
		return (mid);
	if (rocks[mid] < value) //search left half of array
		return binarySearch(rocks, mid + 1, end, value);
	//search right half of array
	return binarySearch(rocks, start, mid - 1, value);
}

//searches a sorted array that is shifted for a specific value

int		searchShifted(int *rocks, int length, int value) {
	//finds start of sorted array
	int pivot = findPivot(rocks, 0, length - 1);

	if (pivot == -1) //if array not shifted search array
		return (binarySearch(rocks, 0, length - 1, value));
	if (rocks[pivot] == value)
		return (pivot); //return answer if found
	if (value >= rocks[0]) //search left part of shifted array recursively
		return (binarySearch(rocks, 0, pivot - 1, value));
	//search right part of shifted array recursively
	return (binarySearch(rocks, pivot + 1, length - 1, value));
}
