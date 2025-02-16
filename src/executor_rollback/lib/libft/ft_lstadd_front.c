
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (*lst)
		new->next = *lst;
	else
		new->next = NULL;
	*lst = new;
}
/*
int	main(void) 
{
    t_list *list = NULL;

    t_list *node1 = (t_list *)malloc(sizeof(t_list));
	if (node1 == NULL)
		return (1);
    node1->content = (void *)10;
    node1->next = NULL;

    t_list *node2 = (t_list *)malloc(sizeof(t_list));
	if (node2 == NULL)
		return (1);
    node2->content = (void *)20;
    node2->next = NULL;

    t_list *node3 = (t_list *)malloc(sizeof(t_list));
	if (node3 == NULL)
		return (1);
    node3->content = (void *)30;
    node3->next = NULL;

    ft_lstadd_front(&list, node1);
    ft_lstadd_front(&list, node2);
    ft_lstadd_front(&list, node3);

    t_list *current = list;
    while (current) {
        printf("%d -> ", (int)(intptr_t)current->content);
	current = current->next;
    }
    printf("NULL\n");

    current = list;
    while (current) {
        t_list *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}*/
