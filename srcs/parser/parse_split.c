/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:09:25 by jubaldo           #+#    #+#             */
/*   Updated: 2024/02/02 13:57:08 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"


typedef struct s_tmp_index
{
	size_t	i;
	size_t	o;
	size_t	j;
}	t_tmp_index;

static void	copy_quotes(char const *s, char **str, t_tmp_index *data)
{
	str[data->j][data->o++] = s[data->i++];
	if (s[data->i - 1] == '\'')
	{
		while (s[data->i] && s[data->i] != '\'')
			str[data->j][data->o++] = s[data->i++];
	}
	else
	{
		while (s[data->i] && s[data->i] != '\"')
			str[data->j][data->o++] = s[data->i++];
	}
	str[data->j][data->o++] = s[data->i++];
}

static void	ft_strcpy2(char const *s, char **str, t_tmp_index *data)
{
	data->o = 0;
	while (s[data->i] && s[data->i] != ' ')
	{
		if (s[data->i] == '\'' || s[data->i] == '\"')
			copy_quotes(s, str, data);
		if (s[data->i])
			str[data->j][data->o++] = s[data->i++];
	}
	if (s[data->i])
		data->i++;
}

void	parse_split(char const *input, char **str, size_t i)
{
	t_tmp_index	data;

	data.i = 0;
	data.j = 0;
	while (data.j < i)
	{
		ft_strcpy2(input, str, &data);
		data.j++;
	}
	str[data.j] = NULL;
}
