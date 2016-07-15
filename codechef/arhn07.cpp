#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	getchar();
	char str1[1000],str2[1000];
	while(T--)
	{
		scanf("%s%*C%s",str1,str2);
		getchar();
		int count=0;
		int i,len;
		if(strlen(str1)!=strlen(str2))
			cout << "-1" << endl;
		else
		{
			len = strlen(str1);
			for(i=0;i<len;i++)
				count += (str1[i]!=str2[i]);
			cout << count << endl;
		}
	}
	return 0;
}
