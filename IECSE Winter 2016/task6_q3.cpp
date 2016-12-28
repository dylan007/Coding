#include<bits/stdc++.h>

using namespace std;

int arr[10000][10000];

void display(int x,int y)
{
    cout << arr[x][y] << endl;
}

void rowc(int row[],int x,int y)
{
    int temp;
    temp = row[x];
    row[x] = row[y];
    row[y] = temp;
}

void colc(int col[],int x,int y)
{
    int temp;
    temp = col[x];
    col[x] = col[y];
    col[y] = temp;
}

int main()
{
    int n,m,q;
    cin >> n >> m >> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin >> arr[i][j];
    }
    int row[n], col[m];
    for(int i=0;i<n;i++)
        row[i] = i;
    for(int i=0;i<m;i++)
        col[i] = i;
    while(q--)
    {
        string a;
        int x,y;
        cin >> a >> x >> y;
        x--;
        y--;
        switch(a[0])
        {
        case 'q':
            display(row[x],col[y]);
            break;
        case 'r':
            rowc(row,x,y);
            break;
        case 'c':
            colc(col,x,y);
            break;
        }
    }
    return 0;
}
