/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:23:41 by adube             #+#    #+#             */
/*   Updated: 2024/02/26 10:39:25 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int redir_type(char c)
{
    if (c == '|')
        return (1);
    else if (c == '>' || c == '<')
        return (2);   
    return (0);
}

int nb_args_tab(char *str)
{
    int i;
    int nb;
    int temp;

    i = 0;
    nb = 0;
    temp = 1;
    while(str[i])
    {
        if (str[i] == 32 || str[i] == 39)
            temp++;
        if (redir_type(str[i]) >= 1 && temp % 2 != 0)
        {
            while (redir_type(str[i]) >= 1 || str[i] == 32)
                i++;
            if (i = 0)
                nb += 1;
            else
                nb += 2;
            if (redir_type(str[i]) == 2)
				nb++;
        }
        i++;
    }
    return (nb);
}