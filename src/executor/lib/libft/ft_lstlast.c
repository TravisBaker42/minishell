
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
int	main(void)
{
	t_list	*lst;
	t_list	*node_a;
	t_list	*node_b;
	t_list	*node_c;
	t_list	*node_d;
	t_list	*last_node;

	lst = NULL;

	node_a = (t_list *)malloc(sizeof(t_list));
	if (!node_a)
		return(1);
	node_a->content = malloc(sizeof(int)); 
	*(int *)node_a->content = 6;

	node_b = (t_list *)malloc(sizeof(t_list));
	if (!node_b)
		return(1);
	node_b->content = malloc(sizeof(int)); 
	*(int *)node_b->content = 1;

	node_c = (t_list *)malloc(sizeof(t_list));
	if (!node_c)
		return(1);
	node_c->content = malloc(sizeof(int)); 
	*(int *)node_c->content = 2;

	node_d = (t_list *)malloc(sizeof(t_list));
	if (!node_d)
		return(1);
	node_d->content = (int *)malloc(sizeof(int)); 
	*(int *)node_d->content = 3;

	ft_lstadd_front(&lst, node_a);
	ft_lstadd_front(&lst, node_b);
	ft_lstadd_front(&lst, node_c);
	ft_lstadd_front(&lst, node_d);

	last_node = ft_lstlast(lst);
	printf("list = %i\n", *((int *)last_node->content));
	return (0);
}*/
