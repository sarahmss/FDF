/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_fl.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:11:40 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/13 09:55:13 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_FL_H
# define GET_NEXT_LINE_FL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft.h"

# define BUFF_SIZE 17

int		get_next_line_fl(const int fd, char **line);

char	*ft_strncpy(char *dst, const char *src, size_t len);

char	*ft_strnew(size_t size);

#endif
