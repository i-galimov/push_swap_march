# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// struct
int		counter;

typedef struct s_list
{
	int				value;
	int				index;
	int				flag;
	struct s_list	*next;
}			t_list;

typedef struct s_all
{
	struct s_list	*a;
	struct s_list	*b;
	int				next;
	int				num;
}			t_all;

// errors.c

void    error(void)
{
    write(1, "Error\n", 6);
    exit(1);
}

void    ft_arg_error(void)
{
    write(1, "Incorrect arguments\n", 20);
    exit(1);
}

// validation.c

int ft_atoi(const char *str)
{
    int         i;
    int         neg;
    long long   res;
    i = 0;
    res = 0;
    neg = 1;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            neg *= -1;
        i++;
    }
    if (!(str[i] >= '0' && str[i] <= '9'))
        ft_arg_error();
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + neg * (str[i] - 48);
        i++;
        if (res > 2147483647 || res < -2147483648)
            ft_arg_error();
    }
    if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
        ft_arg_error();
    return (res);
}
// int *ft_arg_conv(char *av, int *len, int put)
// {
//     int     i;
//     int     *res;
//     char    **strs;
//     i = 0;
//     strs = ft_split(av, ' ');
//     if (!strs)
//         ft_arg_error();
//     while (strs[*len])
//         (*len)++;
//     res = malloc(sizeof(int) * (*len));
//     if (!res)
//         ft_arg_error();
//     while (i < (*len))
//     {
//         res[i] = ft_atoi(strs[i]);
//         free(strs[i]);
//         i++;
//     }
//     free(strs);
//     return (res);
// }

int   ft_check_dublicate(char **argv)
{
    int    i;
    int    j;

    i = 0;
    while (argv[(++i) + 1])
    {
        j = i;
        while (argv[++j])
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
                return (1);
        }
    }
    return (0);
}

int    ft_check_overflow(char **argv)
{
    int    i;

    i = 0;
    while (argv[++i])
    {
        if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
            return (1);
    }
    return (0);
}

int    ft_check_sorted(char **argv)
{
    int    i;

    i = 1;
    while (argv[i + 1])
    {
        if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
            return (0);
        i++;
    }
    return (1);
}

int    ft_check_input(char **argv)
{
    if (ft_check_dublicate(argv) == 1 || ft_check_overflow(argv) == 1 
	|| ft_check_sorted(argv) == 1)
        return (1);
    return (0);
}

// sx_px.c
void	ft_sa(t_list	**a)
{
	t_list	*tmp;

	tmp = (*a)->next;
	(*a)->next = (*a)->next->next;
	tmp->next = (*a);
	*a = tmp;
	write(1, "sa\n", 3);
	counter++;
}

void	ft_sb(t_list	**b)
{
	t_list	*tmp;

	tmp = (*b)->next;
	(*b)->next = (*b)->next->next;
	tmp->next = (*b);
	*b = tmp;
	write(1, "sb\n", 3);
	counter++;
}

void	ft_ss(t_list	**a, t_list	**b)
{
	t_list	*tmp;

	tmp = (*a)->next;
	(*a)->next = (*a)->next->next;
	tmp->next = (*a);
	*a = tmp;
	tmp = (*b)->next;
	(*b)->next = (*b)->next->next;
	tmp->next = (*b);
	*b = tmp;
	write(1, "ss\n", 3);
	counter++;
}

void	ft_pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*a == 0)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
	counter++;
}

void	ft_pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*b == 0)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
	counter++;
}
// rotate.c
void	ft_rra(t_list **a)
{
	t_list	*tmp;
	t_list	*last_prev;

	if (!*a || !(*a)->next)
		return ;
	last_prev = *a;
	while (last_prev->next->next)
		last_prev = last_prev->next;
	last_prev->next->next = *a;
	*a = last_prev->next;
	last_prev->next = 0;
	write(1, "rra\n", 4);
	counter++;
}

void	ft_rrb(t_list **b)
{
	t_list	*tmp;
	t_list	*last_prev;

	if (!*b || !(*b)->next)
		return ;
	last_prev = *b;
	while (last_prev->next->next)
		last_prev = last_prev->next;
	last_prev->next->next = *b;
	*b = last_prev->next;
	last_prev->next = 0;
	write(1, "rrb\n", 4);
	counter++;
}

void	ft_rrr(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*last_prev;

	if (*a && (*a)->next)
	{
		last_prev = *a;
		while (last_prev->next->next)
			last_prev = last_prev->next;
		last_prev->next->next = *a;
		*a = last_prev->next;
		last_prev->next = 0;
	}
	if (*b && (*b)->next)
	{
		last_prev = *b;
		while (last_prev->next->next)
			last_prev = last_prev->next;
		last_prev->next->next = *b;
		*b = last_prev->next;
		last_prev->next = 0;
	}
	if ((*a && (*a)->next) || (*b && (*b)->next))
		write(1, "ft_rrr\n", 4);
		counter++;
}

void	ft_ra(t_list **a)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*a) || !(*a)->next)
		return ;
	last = *a;
	while (last->next)
		last = last->next;
	tmp = *a;
	*a = (*a)->next;
	last->next = tmp;
	tmp->next = 0;
	write(1, "ra\n", 3);
	counter++;
}

void	ft_rb(t_list **b)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*b) || !(*b)->next)
		return ;
	last = *b;
	while (last->next)
		last = last->next;
	tmp = *b;
	*b = (*b)->next;
	last->next = tmp;
	tmp->next = 0;
	write(1, "rb\n", 3);
	counter++;
}

// rr.c
void	ft_rr(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*last;

	if ((*a) && (*a)->next)
	{
		last = *a;
		while (last->next)
			last = last->next;
		tmp = *a;
		*a = (*a)->next;
		last->next = tmp;
		tmp->next = 0;
	}
	if ((*b) && (*b)->next)
	{
		last = *b;
		while (last->next)
			last = last->next;
		tmp = *b;
		*b = (*b)->next;
		last->next = tmp;
		tmp->next = 0;
	}
	if (((*a) && (*a)->next) || ((*b) && (*b)->next))
		write(1, "rr\n", 3);
		counter++;
}

// sort_many_num.c
int	push_to_sort(t_all *s, int flag)
{
	// if (flag)
	// 	ft_pa(&s->a, &s->b);
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
	// if (count(s->b) > 0 && s->b->order == s->next)
	// 	return (push_to_sort(s, 1));
	// if (count(s->b) >= 3 && get_last(s->b, 0, 0, 0)->order == s->next)
	// {
	// 	ft_rrb(&s->b);
	// 	return (push_to_sort(s, 1));
	// }
	// if (count(s->b) > 1 && s->b->next->order == s->next + 1
	// 	&& s->a->next->order == s->next)
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
		k = count(s->b);
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

void	sort_many_num(t_all *s)
{
	int	i;
	int	flag;

	i = 0;
	while (i++ < s->num)
	{
		if (s->a->index <= s->num / 2)
			ft_pb(&s->a, &s->b);
		else
			ft_ra(&s->a);
	}
	while (s->next < s->num)
	{
		flag = s->a->flag;
		while (s->a && s->a->flag == flag && s->next > 0)
			if (!ft_next_num(s))
				ft_pb(&s->a, &s->b);
		sort_stack_b(s, flag);
	}
}

// sort_array.c
int    count_list(t_list *lst)
{
    int    i;

    i = 1;
    while (lst->next)
    {
        lst = lst->next;
        i++;
    }
    return (i);
}

void    define_index(t_list **a, int *arr)
{
    t_list    *tmp;
    int        i;
    int        size;

    size = count_list(*a);
    tmp = *a;
    while (tmp)
    {
        i = 0;
        while (i < size)
        {
            if (tmp->value == arr[i])
            {
                tmp->index = i;
                break ;
            }
            i++;
        }
        tmp = tmp->next;
    }
}

void    ft_swap(int    *a, int *b)
{
    int    tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void    sort_array(int argc, char **argv, t_list **a)
{
    int        *arr;
    int        i;
    int        j;

    i = 0;
    j = 1;
    arr = malloc(sizeof(int) * (argc - 1));
    while (j < argc)
        arr[i++] = ft_atoi(argv[j++]);
    i = 0;
    while (i != argc - 1)
    {
        j = 0;
        while (j != argc - 2)
        {
            if (arr[j] > arr[j + 1])
                ft_swap(&arr[j], &arr[j + 1]);
            j++;
        }
        i++;
    }
    define_index(a, arr);
    free(arr);
}

// sort_by_three.c
static void    case_sort1(t_list **a)
{
    ft_sa(a);
    ft_rra(a);
}

static void    case_sort2(t_list **a)
{
    ft_ra(a);
}

static void    case_sort3(t_list **a)
{
    ft_sa(a);
    ft_ra(a);
}

static void    case_sort4(t_list **a)
{
    ft_rra(a);
}

void    sort_by_three(t_list **a)
{
    int    first_number;
    int    second_number;
    int    third_number;

    first_number = (*a)->value;
    second_number = (*a)->next->value;
    third_number = (*a)->next->next->value;
    if (first_number > second_number && first_number < third_number)
        ft_sa(a);
    if (first_number > second_number && second_number > third_number)
        case_sort1(a);
    if (first_number > third_number && second_number < third_number)
        case_sort2(a);
    if (first_number < third_number && second_number > third_number)
        case_sort3(a);
    if (first_number < second_number && first_number > third_number)
        case_sort4(a);
    else
        return ;
}

// sort_by_five
int    ft_find_min(t_list **a)
{
    t_list    *tmp;
    int        min;

    min = INT_MAX;
    tmp = (*a);
    while (tmp)
    {
        if (min > tmp->value)
            min = tmp->value;
        tmp = tmp->next;
    }
    return (min);
}

void    ft_moves(t_list **a, t_list **b, int argc)
{
    int     small;
    t_list  *tmp;

    tmp = *a;
    small = ft_find_min(a);
    if (tmp->next->value == small)
        ft_sa(a);
    else if (tmp->next->next->value == small)
    {
        ft_ra(a);
        ft_ra(a);
    }
    else if (tmp->next->next->next->value == small && argc == 6)
    {
        ft_rra(a);
        ft_rra(a);
    }
    else if ((tmp->next->next->next->value == small && argc == 5) \
    || (tmp->value != small && argc == 6))
        ft_rra(a);
    ft_pb(a, b);
}

void    sort_by_five(t_list **a, t_list **b, int argc)
{
    int    i;

    i = argc;
    while (i != 4)
        ft_moves(a, b, i--);
    sort_by_three(a);
    ft_pa(a, b);
    if (argc == 6)
        ft_pa(a, b);
}

// list_ops.c
void    create_list(t_list **head, char **argv)
{
    int    i;

    i = 1;
    (*head) = ft_lstnew(ft_atoi(argv[1]));
    while (argv[++i])
        ft_lstadd_back(head, ft_lstnew(ft_atoi(argv[i])));
}

t_list	*ft_lstnew(void *value)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(*lst));
	if (lst == NULL)
		return (NULL);
	lst->next = NULL;
	lst->value = value;
	return (lst);
}

void    free_list(t_all **head)
{
    if ((*head)->next != NULL)
        free_list(&(*head)->next);
    free(*head);
}
// push_swap.c

void    type_sort(t_list **a, t_list **b, t_all *s, int argc)
{
    if (argc == 3)
        ft_sa(a);
    if (argc == 4)
        sort_by_three(a);
    if (argc == 5 || argc == 6)
        sort_by_five(a, b, argc);
    if (argc > 6)
        sort_many_num(s);
}

void    push_swap(int argc, char **argv)
{
    t_list    *a;
    t_list    *b;
    t_all   *s;

    
    if (ft_check_input(argv))
    {
        write(1, "Error: input is wrong, try again\n", 33);
        exit(1);
    }
    if (ft_check_sorted(argv))
        exit(0);
    create_list(&a, argv);
    
    type_sort(&a, &b, &s, argc);
    free_list(&a);
}

int	main(int argc, char **argv)
{
    t_list  a;
    t_list  b;
    t_all   s;

    if (argc == 1)
        exit(0);
    printf("%d\n", ft_check_dublicate(argv));
    printf("%d\n", ft_check_overflow(argv));
    printf("%d\n", ft_check_sorted(argv));
	if (ft_check_input(argv) == 1)
        ft_arg_error();
    create_list(&a, argv);
    sort_array(argc, argv, &a);
    type_sort(&a, &b, &s, argc);
    free_list(&a);

    return (0);
}
