/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:23:44 by juochen           #+#    #+#             */
/*   Updated: 2019/02/09 13:23:46 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"
#include "../../includes/astree.h"

int		is_number_node(t_token **curtoken)
{
	if (*curtoken == NULL)
		return (-1);
	if ((*curtoken)->type == NUMBER_TOKEN && (*curtoken)->data != NULL)
		return (1);
	return (-1);
}

int		is_right_operator(t_token **curtoken, char *type, char **ops)
{
	if (*curtoken == NULL)
		return (-1);
	if (ft_strcmp((*curtoken)->data, type) == 0)
	{
		*curtoken = (*curtoken)->next;
		*ops = type;
		return (1);
	}
	return (0);
}

int		is_word_node(t_token **curtoken)
{
	if (*curtoken == NULL)
		return (-1);
	if (((*curtoken)->type == STRING_TOKEN || (*curtoken)->type == NUMBER_TOKEN)
		&& (*curtoken)->data != NULL)
		return (1);
	return (-1);
}

int		is_separator_op(t_token **curtoken, char **op)
{
	if (*curtoken == NULL)
		return (-1);
	if (ft_strcmp((*curtoken)->data, ";") == 0)
	{
		*op = ";";
		*curtoken = (*curtoken)->next;
		return (1);
	}
	else if (ft_strcmp((*curtoken)->data, "&") == 0)
	{
		*op = "&";
		*curtoken = (*curtoken)->next;
		return (1);
	}
	op = NULL;
	return (0);
}
