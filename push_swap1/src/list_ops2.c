#include "push_swap.h"

int	check_value(t_list *list, int *n, int value)
{
	if (list->value == value)
		return (0);
	if (list->value > value)
		list->index++;
	else
		(*n)++;
	return (1);
}

t_list	*get_last(t_list *begin_list, int data, int *n, int flag)
{
	t_list	*list;

	list = begin_list;
	while (list->next)
	{
		if (flag)
		{
			if (!check_value(list, n, data))
				return (0);
		}
		list = list->next;
	}
	return (list);
}
