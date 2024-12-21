
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		del(lst->content);
	free (lst);
}
/*
void	del(void *content)
{
	free(content);
}

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
	t_list	*last_node;
	t_list	*current_node;

	lst = NULL;
	last_node = NULL;

	node_a = ft_create_node(0);
	node_b = ft_create_node(1);
	node_c = ft_create_node(2);
	node_d = ft_create_node(3);

	ft_lstadd_front(&lst, node_a);
	ft_lstadd_front(&lst, node_b);
	ft_lstadd_front(&lst, node_c);
	ft_lstadd_front(&lst, node_d);
	ft_print_list(lst);

	current_node = lst;
	while (current_node && current_node != node_c)
	{
		last_node = current_node;
		current_node = current_node->next;
	}
	if(last_node)
		last_node->next = current_node->next;
	else
		lst = current_node->next;
	ft_lstdelone(current_node, del);
	ft_print_list(lst);
	return (0);
}*/
