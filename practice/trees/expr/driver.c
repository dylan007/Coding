#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bt.h"

int main()
{
	char s[100];
	scanf("%s",s);
	printf("%s\n",s);
	node *head = construct(s,strlen(s));
	printf("Tree constructed\n");
	inorder(head);
	printf("\n");
	printf("%d\n",evaltree(head));
	return 0;
}
