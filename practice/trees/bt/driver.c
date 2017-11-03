#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bt.h"

int main()
{
	char s[100];
	scanf("%s",s);
	node *head = construct(s,strlen(s));
	inorder(head);
	printf("\n");
	return 0;
}
