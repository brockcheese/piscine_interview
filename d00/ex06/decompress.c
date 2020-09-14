/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:34:11 by bpace             #+#    #+#             */
/*   Updated: 2020/02/25 22:49:20 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_string *stringInit(void) {
	struct s_string	*dyString;

	if (!(dyString = malloc(sizeof(struct s_string))))
		return (NULL);
	dyString->content = NULL;
	dyString->length = 0;
	dyString->capacity = 0;
	return (dyString);
}

int		stringAppend(struct s_string *dyString, char *str) {
	int realloccheck;

	int newlen = str ? strlen(str) + dyString->length : dyString->length;
	realloccheck = 0;
	while(newlen + 1 > dyString->capacity) {
		dyString->capacity += 1000000;
		realloccheck = 1;
	}
	if (realloccheck == 1) {
		if (!(dyString->content = realloc(dyString->content, dyString->capacity)))
			return (0);
	}
	if (str) {
		strcpy(dyString->content + dyString->length, str);
		dyString->length = newlen;
		dyString->content[dyString->length] = '\0';
	}
	return (1);
}

char *decompress(char *cBook) {
	char *header[255];
	char *ans, ch;
	int i, j, comma;

	struct s_string *s = stringInit();
	i = -1;
	while (++i < 255)
		header[i] = NULL;
	i = -1;
	j = -1;
	comma = 0;
	while(cBook[++i] != '>') {
		if (cBook[i] == ',') {
			header[++j] = strndup(cBook + comma + 1, i - comma - 1);
			comma = i;
		}
	}
	header[++j] = strndup(cBook + comma + 1, i - comma - 1);
	comma = i;
	while((ch = cBook[++i])) {
		if (ch == '@') {
			ans = strndup(cBook + comma + 1, i - comma - 1);
			if (!(stringAppend(s, ans)))
				return (ans);
			free(ans);
			ch = cBook[++i];
			if (!(stringAppend(s, header[(unsigned char) ch - 1])))
				return (header[(unsigned char) ch - 1]);
			comma = i;
		}
	}
	ans = strdup(cBook + comma + 1);
	stringAppend(s, ans);
	free(ans);
	for(int k = 0; header[k]; k++)
		free(header[k]);
	ans = s->content;
	free(s);
	return (ans);
}
