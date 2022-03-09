#include "push_swap.h"

int	push_to_sort(t_all *s, int flag)
{
	if (flag)
		ft_pa(&s->a, &s->b);
	s->a->flag = -1;
	ft_ra(&s->a);
	s->next++;
	ft_next_num(s);
	return (1);
}

int	ft_next_num(t_all *s)
{
	if (s->a->index == s->next)
		return (push_to_sort(s, 0));
	// if (len_list(s->b) > 0 && s->b->index == s->next)
	// 	return (push_to_sort(s, 1));
	// if (len_list(s->b) >= 3 && get_last(s->b, 0, 0, 0)->index == s->next)
	// {
	// 	ft_rrb(&s->b);
	// 	return (push_to_sort(s, 1));
	// }
	// if (len_list(s->b) > 1 && s->b->next->index == s->next + 1
	// 	&& s->a->next->index == s->next)
	// {
	// 	ft_ss(&s->a, &s->b);
	// 	s->a->flag = -1;
	// 	ft_ra(&s->a);
	// 	s->next++;
	// 	return (push_to_sort(s, 1));
	// }
	return (0);
}

void	sort_stack_b(t_all *s, int flag)
{
	int	i;
	int	k;
	int	mid;

	while (s->b)
	{
		i = 0;
		flag++;
		k = len_list(s->b);
		mid = k / 2 + s->next + 2;
		while (s->b && i++ < k)
		{
			s->b->flag = flag;
			if (s->b->index >= mid || s->b->index == s->next)
			{
				ft_pa(&s->a, &s->b);
				ft_next_num(s);
			}
			else if (s->b)
				ft_rb(&s->b);
		}
	}
}

void	sort_all(t_all *s)
{
	int	i;
	int	flag;

	i = 0;
	while (i++ < s->len)
	{
		if (s->a->index <= s->len / 2)
			ft_pb(&s->a, &s->b);
		else
			ft_ra(&s->a);
	}
	while (s->next < s->len)
	{
		flag = s->a->flag;
		while (s->a && s->a->flag == flag && s->next > 0)
			if (!ft_next_num(s))
				ft_pb(&s->a, &s->b);
		sort_stack_b(s, flag);
	}
}
