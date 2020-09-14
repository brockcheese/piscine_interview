/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 22:49:08 by bpace             #+#    #+#             */
/*   Updated: 2020/03/02 23:11:27 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int toInt(char *bits) {
	int ans = 0;
	int b = 1;
	for(int i = 5; i >= 0; i--) {
		ans += (bits[i] - '0') * b;
		b *= 2;
	}
	return (ans);
}

char *getSum(char *a, char *b) {
	int r = 0;
	for(int i = 5; i >= 0; i--) {
		r += a[i] - '0' + b[i] - '0';
		b[i] = (char)(r % 2 + '0');
		r /= 2;
	}
	return (b);
}
