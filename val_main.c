# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

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

int    ft_istrash(char c)
{
    if (c == '\t' || c == '\n' || c == '\v'
        || c == '\f' || c == '\r' || c == ' ')
        return (1);
    return (0);
}

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

int	main(int argc, char **argv)
{
    printf("%d\n", ft_check_dublicate(argv));
    printf("%d\n", ft_check_overflow(argv));
    printf("%d\n", ft_check_sorted(argv));
	if (ft_check_input(argv) == 1)
        ft_arg_error();
    return (0);
}
