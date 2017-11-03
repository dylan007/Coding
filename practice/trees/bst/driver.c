#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main()
{
	node *head = NULL;
	int n,x,i;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		head = insert(head,x);
	}
	preorder(head);
	printf("\n");
	inorder(head);
	printf("\n");
	postorder(head);
	printf("\n");
	scanf("%d",&n);
	printf("Minimum of the tree is : %d\n",find_min(head)->data);
	printf("Maximum of the tree is : %d\n",find_max(head)->data);
	while(n--)
	{
		scanf("%d",&x);
		printf("Deleting %d\n",x);
		head = delete(head,x);
		inorder(head);
		printf("\n");
	}
	//printf("%d %d\n",search(head,1),search(head,10));
	levelorder(head);
	return 0;
}
