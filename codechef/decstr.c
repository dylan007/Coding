#include<stdio.h>
#include<stdlib.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int i,n,t,z;
		scanf("%d",&n);
		t = n/26;
		char out[27] = "abcdefghijklmnopqrstuvwxyz";
		char reverse[27] = "zyxwvutsrqponmlkjihgfedcba";
		t = n/25;z = n%25;
		if(z) while(z>=0){printf("%c",out[z--]);}
		while(t--){printf("%s",reverse);}
		printf("\n");
	}
	return 0;
}
