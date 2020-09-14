/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   externalSort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 21:51:13 by bpace             #+#    #+#             */
/*   Updated: 2020/02/27 21:51:15 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		sort(int *arr, int start, int end) {
	int temp;
	int i = start - 1;

	for (int j = start; j < end; j++) {
		if (arr[j] > arr[end]) {
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[++i];
	arr[i] = arr[end];
	arr[end] = temp;
	return (i);
}

void quickSort(int *arr, int start, int end) {
	if (start < end) {
		int pivot = sort(arr, start, end);
		quickSort(arr, start, pivot - 1);
		quickSort(arr, pivot + 1, end);
	}
}

void externalSort(char *scoreFile, char *sortedFile, int ram) {
	FILE *input, *output;
	int arr[ram / 4];
	int n, i, b[ram / 4];
	int pointer;
	int chunk;
	char s[256];
	int files;


	input = openFile(scoreFile, "r");
	files = 0;
	while((n = readBlock(input, arr, ram / 4))) {
		quickSort(arr, 0, n - 1);
		files++;
		sprintf(s, "%d%s", files, sortedFile);
		writeFile(s, arr, n);
	}
	fclose(input);
	chunk = (ram / 4) / files;
	output = openFile(sortedFile, "w");
	for(int j = 0; j < (ram / 4) / chunk; j++) {
		i = 0;
		pointer = 0;
		while (i < files) {
			sprintf(s, "%d%s", i + 1, sortedFile);
			input = openFile(scoreFile, "r");
			fseek(input, i * chunk, SEEK_SET);
			n = readBlock(input, b, chunk);
			memmove(&arr[i * chunk], b, n);
			pointer += n;
			fclose(input);
			i++;
		}
		quickSort(arr, pointer - n, pointer - 1);
		for (int k = 0; k < pointer; k++)
			fprintf(output, "%d\n", arr[k]);
	}
	fclose(output);
}
