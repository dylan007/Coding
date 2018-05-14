#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int graph[3000][3000],s=0;

int check(int n,int x,int visited[])
{
    cout << x << " " << visited[x] << endl;
    if(visited[x]==1)
        return 1;
    visited[x] = 1;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(graph[x][i]==1)
        {
            ans |= check(n,i,visited);
        }
    }
    return ans;
}

void reset(int n)
{
    s=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) graph[i][j] = 0;
}

struct customLess {
        bool operator()(pair<pair<int,int>,int> const& a ,pair<pair<int,int>,int> const& b)
        {
            return a.second < b.second;
        }
};


int main() {
    int n,e;
    cin >> n >> e;
    vector< pair <pair <int,int>,int> > adj;
    for(int i=0;i<e;i++)
    {
        int x,y,w;
        cin >> x >> y >> w;
        pair<int,int> temp;
        pair< pair<int,int>, int > temp2;
        temp = make_pair(x,y);
        temp2 = make_pair(temp,w);
        adj.push_back(temp2);
    }
    int s;
    cin >> s;
    sort(adj.begin(),adj.end(),customLess());
    //vector< pair<int,int> , int > mst;
    for(int i=0;i<e;i++)
        cout << adj[i].first.first << " " << adj[i].first.second << " " << adj[i].second << endl;
    reset(n);
    int x,y,w,ans=0;
    for(int i=0;i<e;i++)
    {
        x = adj[i].first.first;
        y = adj[i].first.second;
        w = adj[i].second;
        x--;
        y--;
        graph[x][y]=1;
        graph[y][x]=1;
        /*for(int k=0;k<n;k++)
        {
            for(int j=0;j<n;j++)
                cout << graph[k][j] << " ";
            cout << endl;
        }*/
        //cout << endl;
        int visited[3000]={0};
        s=0;
        s = check(n,x,visited);
        cout << s << endl;
        //cout << s << endl;
        //cout << endl << endl;
        if(s>0)
        {
            graph[x][y]=0;
            graph[y][x]=0;
        }
        else
            ans += w;
    }
    cout << ans << endl;
    return 0;
}

