#include<bits/stdc++.h>
using namespace std;

int n;
int adj[100000][100000] = {0};


int check(int visited[])
{
    for(int i=0;i<n;i++)
        if(visited[i]==0) return 1;
    return 0;
}

void size_tree(int x,int visited[],int flag)
{
    for(int i=0;i<n;i++)
    {
        if(adj[x][i]==1)
        {
            if(visited[i]>0)
                return;
            visited[i] = flag;
            size_tree(x,visited,flag);
        }
    }
    return;
}

int main() {
    int T;
    cin >> n >> T;
    int x,y;
    //int adj[n][n] = {0};
    for(int i=0;i<T;i++)
    {
        cin >> x >> y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    int count=0;
    int visited[n] = {0};
    int c=1;
    while(check(visited)==1)
    {
        int i;
        for(i=0;i<n;i++)
            if(visited[i]==0) break;
        size_tree(i,visited,c);
        int a=0;
        for(int i=0;i<n;i++) a+=(c==visited[i]);
        count += a*(a-1)/2;
    }
    return 0;
}

