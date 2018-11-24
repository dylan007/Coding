#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define INF 1000000

int main(){
	int n,e;
	scanf("%d %d",&n,&e);
	int adj[n][n];
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++) adj[i][j] = INF;
		adj[i][i] = 0;
	}
	for(i=0;i<e;i++){
		int x,y,w;
		scanf("%d %d %d",&x,&y,&w);
		x--;y--;
		adj[x][y] = w;
	}
	int k;
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if((adj[i][j]) > (adj[i][k] + adj[k][j]))
					adj[i][j] = adj[i][k] + adj[k][j];
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d ",adj[i][j]);
		printf("\n");
	}
}