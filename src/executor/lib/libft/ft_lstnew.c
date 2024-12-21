
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}
/*
int	main(void)
{
	int		content;
	t_list	*node;

	content = 46;
	node = ft_lstnew(&content);
	if (node)
	{
		printf("content: %i\n", *((int *)(node->content)));
		printf("next address %p\n", (void *)(node->next));
	}
	else
		printf("Node failed to allowcate memory");
	free(node);
	return (0);
}*/
