#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a,int b){return a>b?a:b;}

int solve(int val[],int wt[],int n,int w){
	int dp[n+1][w+1];
	int i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=w;j++){
			if(i==0 || j==0)
				dp[i][j] = 0;
			else if(wt[i-1]<=j)
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][w];
}

int main(){
	int n,w;
	scanf("%d %d",&n,&w);
	int val[n],wt[n];
	int i=0;
	for(i=0;i<n;i++)
		scanf("%d %d",val+i,wt+i);
	printf("%d\n",solve(val,wt,n,w));
	return 0;
}