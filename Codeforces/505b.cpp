#include<bits/stdc++.h>

using namespace std;

typedef struct node
{
	int data;
	struct node *next = NULL;
}node;

node a[1000][1000];

void insert(int i,int j,int x)
{
	node *head = &a[i][j];
	if(head==NULL)
	{
		head = (node *)malloc(sizeof(node));
		head->data = x;
		head->next=NULL;
	}
	else
	{
		node *t,*temp;
		temp = (node *)malloc(sizeof(node));
		t = head;
		while(t->next!=NULL)
			t = t->next;
		t->next = temp;
		temp->next = NULL;
		temp->data = x;
	}

}

void print(int i,int j)
{
	node *head = &a[i][j];
	node *temp;
	temp = head;
	if(head==NULL)
		return;
	while(head!= NULL)
	{
		cout << head->data;
		cout << " ";
		head = head->next;
	}
	cout << endl;
}

int search(int i,int j,int x)
{
	node *head = &a[i][j];
	if(head==NULL)
		return 0;
	while(head!=NULL)
	{
		if(head->data==x)
			return 1;
	}
	return 0;
}

int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int x,y,c;
		cin >> x >> y >> c;
		insert(x-1,y-1,c);
		insert(y-1,x-1,c);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout << i << j << endl;
			print(i,j);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			node *temp = &a[i][j];
			while(temp!=NULL)
			{
				int x = temp->data;
				for(int k=0;k<n;k++)
				{
					if(search(j,k,x)==1)
						insert(i,k,x);
				}
				temp = temp->next;
			}
		}
	}
	int q;
	int x,y;
	cin >> q;
	cout << q;
	while(q--)
	{
		cin >> x >> y;
		node *head = &a[x-1][y-1];
		int count=0;
		while(head!=NULL)
		{
			count += (head->data>0);
			head = head->next;
		}
		cout << count;
	}
	return 0;
}
