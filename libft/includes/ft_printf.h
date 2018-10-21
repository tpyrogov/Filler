/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:46:09 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/08/13 14:46:10 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <locale.h>
# include "libft.h"

enum			e_ref{NONE, H, HH, L, LL, Z, J};

enum			e_spec{NON, pc, s, scaps, c, d, i, o, u, x, xcaps, p};

typedef struct	s_flags
{
	enum e_ref	ref;
	enum e_spec	spec;
	char		*mask;
	int			hash;
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			width;
	int			precision;
	int			cur;
	int			neg;
	int			counter;
}				t_flags;

int				ft_printf(char *format, ...);

t_flags			*init_flags();
char			*get_flags(char *format, t_flags *flags);
char			*get_ref(char *format, t_flags *flags);
void			apply_format(char **str, t_flags *flags);

void			change_str(char **res, t_flags *flags);
void			perc_form(char **str, t_flags *flags);
void			char_form(char **str, t_flags *flags);
void			dec_form(char **str, t_flags *flags);
void			oct_form(char **str, t_flags *flags);
void			uns_form(char **str, t_flags *flags);
void			hex_form(char **str, t_flags *flags);
void			int_form(char **str, t_flags *flags);
void			addr_form(char **str, t_flags *flags);

char			*dec_type(va_list ap, t_flags *flags, int caps);
char			*octal_type(va_list ap, t_flags *flags, int caps);
char			*unsigned_type(va_list ap, t_flags *flags, int caps);
char			*hex_type(va_list ap, t_flags *flags, int p);

char			*put_nbr_base(intmax_t num, int base, t_flags *flags);
char			*put_unsigned_nbr(uintmax_t num, int base, t_flags *flags);

char			*str_out(char *s, t_flags *flags);
char			*put_char(char c, t_flags *flags);
void			put_char_loc(wchar_t ch, char **s, t_flags *flags);
char			*put_str_loc(wchar_t *s, t_flags *flags);

int				count(intmax_t x, int base);
int				u_count(uintmax_t x, int base);
uintmax_t		power(uintmax_t num, int power);
char			*to_upper(char *s);

void			plus(char **s, t_flags *flags);
void			zero(char **s, int width, t_flags *flags);
void			space(char **s, t_flags *flags);
void			hash(char **s, t_flags *flags);
void			hash_hex(char **s, int hash, t_flags *flags);
void			space_before(char **s, t_flags *flags);
int				is_zero(char *str);
void			cut(char **s, t_flags *flags);
void			cut_scaps(char **s, t_flags *flags);
int				bit_count(unsigned int c);
void			ft_put_str(char *s, int size);
char			*ft_stradd(char *s1, char *s2, int size1, int size2);

void			mask1(char **s, unsigned int c, t_flags *flags);
void			mask2(char **s, unsigned int c, t_flags *flags);
void			mask3(char **s, unsigned int c, t_flags *flags);
void			mask4(char **s, unsigned int c, t_flags *flags,
					unsigned int mask);

char			*per(t_flags *flags);
void			free_flags(t_flags **flags);
void			free_all(char **s, char **b);

#endif
