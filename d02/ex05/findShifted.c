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

int		findPivot(int *rocks, int start, int end) {
	if (start > end)
		return (-1);
	if (start == end)
		return (start);
	int mid = (start + end) / 2;
	if (mid < end && rocks[mid] > rocks[mid + 1])
		return mid;
	if (mid > start && rocks[mid] < rocks[mid - 1])
		return mid;
	if (rocks[start] >= rocks[mid])
		return findPivot(rocks, start, mid - 1);
	return findPivot(rocks, mid + 1, end);
}

int		binarySearch(int *rocks, int start, int end, int value) {
	if (start > end)
		return (-1);
	int mid = (start + end) / 2;
	if (rocks[mid] == value)
		return (mid);
	if (rocks[mid] < value)
		return binarySearch(rocks, mid + 1, end, value);
	return binarySearch(rocks, start, mid - 1, value);
}

int		searchShifted(int *rocks, int length, int value) {
	int pivot = findPivot(rocks, 0, length - 1);

	if (pivot == -1)
		return (binarySearch(rocks, 0, length - 1, value));
	if (rocks[pivot] == value)
		return (pivot);
	if (value >= rocks[0])
		return (binarySearch(rocks, 0, pivot - 1, value));
	return (binarySearch(rocks, pivot + 1, length - 1, value));
}
