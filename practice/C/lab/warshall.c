#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int n,e;
	scanf("%d %d",&n,&e);
	int adj[n][n];
	int i,j;
	for(i=0;i<n;i++) memset(adj[i],0,sizeof(adj[i]));
	for(i=0;i<e;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x][y] = w;
	}
	int k;
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
		}
	}
	return 0;
}