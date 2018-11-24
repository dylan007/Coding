#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int t[100];

void bct(char pat[],int l){
	int i=0;
	for(i=0;i<l;i++)
		t[pat[i]-'a'] = l-1-i; 
}

int horspool(char txt[],char pat[]){
	int m = strlen(txt);
	int n = strlen(pat);
	int i = n-1;
	int k;
	while(i<m){
		k = 0;
		while((k<n) && (pat[n-1-k] == txt[i-k]))
			k++;
		if(k==n)
			return i-n+1;
		else
			i += t[txt[i]-'a'];
		// printf("%d\n",i);
	}
	return -1;
}

int main(){
	char txt[100],pat[100];
	scanf("%s%*C%s",txt,pat);
	// printf("%s %s\n",txt,pat);
	memset(t,-1,sizeof(t));
	bct(pat,strlen(pat));
	int i;
	for(i=0;i<26;i++)
		printf("%d ",t[i]);
	printf("\n");
	printf("%d\n",horspool(txt,pat));
	return 0;
}