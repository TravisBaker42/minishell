
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp_lst;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		temp_lst = *lst;
		while (temp_lst->next)
			temp_lst = temp_lst->next;
		temp_lst->next = new;
	}
}
/*
t_list	*ft_create_node(int nb)
{
	t_list *new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = malloc(sizeof(int));
	if (!new_node->content)
	{
		free(new_node);
		return (NULL);
	}
	*(int *)new_node->content = nb;
	new_node->next = NULL;

	return (new_node);
}

void ft_print_list(t_list *lst) 
{
    while (lst) {
        printf("%d ", *(int *)lst->content); 
		lst = lst->next;
    }
    printf("\n");
}

int	main(void)
{
	t_list	*lst;
	t_list	*node_a;
	t_list	*node_b;
	t_list	*node_c;
	t_list	*node_d;
	t_list	*node_e;

	lst = NULL;

	node_a = ft_create_node(0);
	node_b = ft_create_node(1);
	node_c = ft_create_node(2);
	node_d = ft_create_node(4);
	node_e = ft_create_node(5);

	ft_lstadd_front(&lst, node_a);
	ft_lstadd_front(&lst, node_b);
	ft_lstadd_front(&lst, node_c);
	ft_lstadd_front(&lst, node_d);
	ft_print_list(lst);
	ft_lstadd_back(&lst, node_e);
	ft_print_list(lst);

	return (0);
}*/
