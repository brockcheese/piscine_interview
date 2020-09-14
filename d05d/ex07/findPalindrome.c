/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPalindrome.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 23:28:27 by bpace             #+#    #+#             */
/*   Updated: 2020/03/04 23:42:13 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*delete(char *sequence, int n) {
	int j = -1;;

	char *ans = malloc(sizeof(char) * strlen(sequence) + 1);
	ans[strlen(sequence)] = '\0';
	for(int i = 0; sequence[i]; i++) {
		if (i != n)
			ans[++j] = sequence[i];
	}
	return (ans);
}

char	*fph(char *sequence, int nd, int start, int end) {
	char *ans;

	if (start >= end)
		return (sequence);
	if (sequence[start] == sequence[end])
		return (fph(sequence, nd, start + 1, end - 1));
	if (sequence[start + 1] == sequence[end + 1]) {
		ans = delete(sequence, start);
		ans = delete(sequence, end);
	}
	if (sequence[start + 1] == sequence[end] && nd > 0) {
		ans = fph(delete(sequence, start), nd - 1, start, end - 1);
		if (ans)
			return (ans);
	}
	if (sequence[start] == sequence[end - 1] && nd > 0) {
		ans = fph(delete(sequence, end), nd - 1, start, end - 2);
		if (ans)
			return (ans);
	}
	ans = fph(delete(sequence, start), nd - 1, start, end - 1);
		if (ans)
			return (ans);
	ans = fph(delete(sequence, end), nd - 1, start, end - 2);
		if (ans)
			return (ans);
	return(NULL);
}

char	*findPalindrome(char *sequence, int nDelete) {
	return (fph(sequence, nDelete, 0, strlen(sequence) - 1));
}
