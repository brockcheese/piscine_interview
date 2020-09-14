/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 02:49:02 by bpace             #+#    #+#             */
/*   Updated: 2020/03/05 15:37:49 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int toInt(char *bits) {
	int ans = 0;
	int b = 1;
	for(int i = 5; i >= 0; i--) {
		ans += (bits[i] - '0') * b;
		b *= 2;
	}
	if (ans > 31)
		ans -= 64;
	return (ans);
}

char *leftShift(char *bin, int k) {
	int i;

	for(i = 0; i < 6 - k; i++) {
		bin[i] = bin[i + k];
	}
	while(i < 6)
		bin[i++] = '0';
	return (bin);
}

char *rightShift(char *bin, int k) {
	int i;
	int sign;

	sign = bin[0];
	for(i = 5; i >= k; i--) {
		bin[i] = bin[i - k];
	}
	while (i > -1)
		bin[i--] = sign;
	return (bin);
}
