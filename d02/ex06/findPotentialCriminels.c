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

#include "header.h"

int getDescription(struct s_info *info) {
	int description;
	int tens;

	tens = 1;
	description = 0;
	description += tens * info->piercing;
	tens *= 10;
	description += tens * info->tattoo;
	tens *= 10;
	description += tens * info->glasses;
	tens *= 10;
	description += tens * info->eyeColor;
	tens *= 10;
	description += tens * info->hairColor;
	tens *= 10;
	description += tens * info->height;
	tens *= 10;
	description += tens * info->gender;
	return (description);
}

void countCriminals(struct s_criminal **criminals, int tens) {
	int count[10];
	int n;

	for(int i = 0; i < 10; i++)
		count[i] = 0;
	for(n = 0; criminals[n]; n++)
		count[(criminals[n]->description / tens) % 10]++;
	struct s_criminal *output[n];
	for(int i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for(int i = n - 1; i > -1; i--)
		output[--(count[(criminals[i]->description / tens) % 10])] = criminals[i];
	for(int i = 0; i < n; i++)
		criminals[i] = output[i];
}

void sortCriminals(struct s_criminal **criminals) {
	int tens;

	tens = 1;
	for(int j = 0; j <= 6; j++) {
		countCriminals(criminals, tens);
		tens *= 10;
	}
}

int					binarySearch(struct s_criminal **criminals, int start, int end, int description) {
	if (start > end)
		return (-1);
	int m = (start + end) / 2;
	int check = criminals[m]->description;
	if (check == description)
		return (m);
	if (check > description)
		return binarySearch(criminals, start, m - 1, description);
	return binarySearch(criminals, m + 1, end, description);
}

struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info) {
	int description;
	int n;
	int first;
	int last;
	struct s_criminal **ans;

	description = getDescription(info);
	for(n = 0; criminals[n]; n++);
	first = binarySearch(criminals, 0, n - 1, description);
	if (first == -1)
		return (NULL);
	while(first != 0 && description == criminals[first - 1]->description)
		first--;
	for(last = first + 1; criminals[last] && criminals[last]->description == description; last++)
		;
	ans = malloc(sizeof(struct s_criminal*) * (last - first + 1));
	n = first;
	for(int i = 0; i <= last - first; i++)
		ans[i] = criminals[n++];
	ans[last - first] = NULL;
	return (ans);
}
