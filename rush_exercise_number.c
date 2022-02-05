/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:55:54 by edpaulin          #+#    #+#             */
/*   Updated: 2022/02/05 12:02:15 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static size_t	ft_strlen(char *s);
static int		ft_is_lowercase(char c);
static int		ft_check_entry(char *s);
static int		ft_get_exercise_number(char c);
static void		ft_print_entire_table(void);
static void		ft_print_exercise_number(char c);
static void		ft_print_usage_exemple(void);

int	main(int argc, char *argv[])
{
	if (argc != 2 || !ft_check_entry(argv[1]))
	{
		ft_print_usage_exemple();
		return (1);
	}
	if (argv[1][0] == 'T')
		ft_print_entire_table();
	else
		ft_print_exercise_number(argv[1][0]);
	return (0);
}

static size_t	ft_strlen(char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

static int	ft_is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

static int	ft_is_entire_table(char c)
{
	return (c == 'T');
}

static int	ft_check_entry(char *s)
{
	return (s && ft_strlen(s) == 1 && (ft_is_lowercase(s[0]) || ft_is_entire_table(s[0])));
}

static int	ft_get_exercise_number(char c)
{
	return ((c -71) % 5);
}

static void	ft_print_entire_table(void)
{
	char	c;

	c = 'a';
	while (c <= 'z')
	{
		ft_print_exercise_number(c);
		c++;
	}
}

static void	ft_print_exercise_number(char c)
{
	int	n;

	n = ft_get_exercise_number(c);
	if (n == 1)
		printf("\033[32mThe Rush exercise number for '%c' is: %d\033[0m\n", c, n);
	else if (n == 2)
		printf("\033[33mThe Rush exercise number for '%c' is: %d\033[0m\n", c, n);
	else if (n == 3)
		printf("\x1b[36mThe Rush exercise number for '%c' is: %d\033[0m\n", c, n);
	else if (n == 4)
		printf("\033[35mThe Rush exercise number for '%c' is: %d\033[0m\n", c, n);
	else
		printf("\033[34mThe Rush exercise number for '%c' is: %d\033[0m\n", c, n);
}

static void	ft_print_usage_exemple(void)
{
	printf("\033[31mERROR\033[0m\n");
	printf("Usage exemple (only lowercase letters):\t\033[32m./rush_number e\033[0m\n");
	printf("Or to see the entire table:\t\t\033[32m./rush_number T\033[0m\n");
}
