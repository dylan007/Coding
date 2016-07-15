#include<iostream>
#include<cmath>
#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
	int T,i;
	cin >> T;
	getchar();
	char a[T][100],b[T][100];
	int flag[T];
	for(i=0;i<T;i++)
	{
		scanf("%s %s",a[i],b[i]);
		getchar();
	}
	memset(flag,0,4*T);
	int count=0;
	for(i=0;i<T;i++)
	{
		char temp[1000];
		if(flag[i]==0)
		{
			count++;
			flag[i]=1;
			strcpy(temp,b[i]);
			for(int j=i;j<T;j++)
			{
				if(flag[j]==0)
				{
					if(strcmp(temp,a[j])==0)
					{
						flag[j]=1;
						strcpy(temp,b[j]);
					}
				}
			}
		}
	}
	cout << count << endl;
	memset(flag,0,4*T);
	for(i=0;i<T;i++)
	{
		char temp[1000];
		if(flag[i]==0)
		{
			cout << a[i] << " ";
			flag[i]=1;
			strcpy(temp,b[i]);
			for(int j=i;j<T;j++)
			{
				if(flag[j]==0)
				{
					if(strcmp(temp,a[j])==0)
					{
						flag[j]=1;
						strcpy(temp,b[j]);
					}
				}
			}
			cout << temp << endl;
		}
	}
	return 0;
}
