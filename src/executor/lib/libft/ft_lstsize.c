
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp_lst;

	i = 0;
	temp_lst = lst;
	while (temp_lst)
	{
		i++;
		temp_lst = temp_lst->next;
	}
	return (i);
}
/*
int	main(void)
{
	t_list	*lst;
	t_list	*node_a;
	t_list	*node_b;
	t_list	*node_c;
	t_list	*node_d;

	lst = NULL;
	node_a = (t_list *)malloc(sizeof(t_list));
	if (!node_a)
		return(1);
	node_b = (t_list *)malloc(sizeof(t_list));
	if (!node_b)
		return(1);
	node_c = (t_list *)malloc(sizeof(t_list));
	if (!node_c)
		return(1);
	node_d = (t_list *)malloc(sizeof(t_list));
	if (!node_d)
		return(1);
	ft_lstadd_front(&lst, node_a);
	ft_lstadd_front(&lst, node_b);
	ft_lstadd_front(&lst, node_c);
	ft_lstadd_front(&lst, node_d);

	printf("list = %i\n",ft_lstsize(lst));
	return (0);
}*/
