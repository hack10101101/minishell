////#include "builtin.h"

//void	ft_lstadd_back(t_list **list, t_list *new)
//{
//	t_list	*lst;

//	lst = *list;
//	if (!lst)
//		lst = new;
//	else
//	{
//		while (lst->next)
//		lst = lst->next;
//		lst->next = new;
//	}
//}

//t_list	*ft_lstnew(void *content)
//{
//	t_list 	*list;

//	list = malloc(sizeof(t_list));
//	list->content = content;
//	list->next = NULL;
//	return (list);
//}

//void ft_essai(t_list **essai)
//{
//	int     i;

//	i = -1;
//	while (++i < 10)
//		ft_lstadd_back(essai, ft_lstnew("second"));
//	while (*essai)
//	{
//		printf("%s\n", (char *)(*essai)->content);
//		*essai = (*essai)->next;
//	}
//	printf("1000000\n");
//}

//void	first_one(t_list *essai, t_list **premier)
//{
//	essai = ft_lstnew("first");
//	printf("essai = %p\n", essai->content);
//	premier = &essai;
//	printf("premier = %p\n", (*premier)->content);
//}

//int main(void)
//{
//	t_list *essai;
//	t_list **premier;

//	first_one(essai, premier);
//	printf("essai = %p\n", essai->content);
//	ft_essai(&essai);
//	printf("A\n");
//	printf("premier = %p\n", (*premier)->content);
//	essai = premier;
//	while (essai)
//	{
//		printf("%s\n", (char *)essai->content);
//		essai = essai->next;
//	}
//}