/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 23:05:37 by bpace             #+#    #+#             */
/*   Updated: 2020/02/25 23:30:29 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rotate(int **picture, int n) {
	int i, j, temp;

	for(i = 0; i < n/2; i++) {
		for(j = i; j < n - i - 1; j++) {
			temp = picture[i][j];
			picture[i][j] = picture[n - j - 1][i];
			picture[n - j - 1][i] = picture[n - i - 1][n - j - 1];
			picture[n - i - 1][n - j - 1] = picture[j][n - i - 1];
			picture[j][n - i - 1] = temp;
		}
	}
}
