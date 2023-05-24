/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:24:41 by maderuel          #+#    #+#             */
/*   Updated: 2023/02/21 14:18:32 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_format
{
	int		preci;
	int		width;
	int		hash;
	int		dot;
	int		space;
	int		zero;
	int		plus;
	int		minus;
	int		len;
	char	flag;
}	t_format;

int			ft_printf(const char *str_in, ...);

t_format	*ft_init_mod(t_format *mod);
t_format	*ft_set_mod(char f, t_format *mod);
void		ft_putchar(const char c);
void		ft_putstr(char *s);
int			ft_strnlen(const char *s, const char c);
int			ft_puthex_fd(unsigned long long nbr, int fd);
int			ft_puthex_maj_fd(unsigned long long nbr, int fd);
int			ft_is_flag(const char c);
int			ft_is_mod(const char c);
int			ft_seen(t_format *mod, const char c);
int			ft_putnstr(char *str, unsigned int n);
int			ft_print_str_mod(va_list args, t_format *mod);
int			ft_putnchar(char c, int n);
int			ft_print_nbr_mod(va_list args, t_format *mod);
int			ft_print_var_mod(t_format *mod, va_list args);
int			ft_print_var(t_format *mod, va_list args);
int			ft_puthex_mod(va_list args, t_format *mod);
int			ft_putunsigned_fd(unsigned int nbr, int fd);
int			ft_putunsigned_mod(va_list args, t_format *mod);
int			ft_parse_flag(va_list args, const char *str, t_format *mod);
int			ft_putmod_c(t_format *mod, va_list args);
int			print_mod_p(va_list args, t_format *mod);
int			ft_putnhex(unsigned long long nbr, t_format *mod);

#endif
