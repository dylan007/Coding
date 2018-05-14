#include<bits/stdc++.h>

using namespace std;

int main()
{
	string board[8];
	for(int i=0;i<8;i++)
		cin >> board[i];
	int white=0;
	int black=0;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			switch(board[i][j])
			{
				case 'Q':
					white+=9;
					break;
				case 'R':
					white+=5;
					break;
				case 'B':
					white+=3;
					break;
				case 'N':
					white+=3;
					break;
				case 'P':
					white+=1;
					break;
				case 'q':
					black+=9;
					break;
				case 'r':
					black+=5;
					break;
				case 'b':
					black+=3;
					break;
				case 'n':
					black+=3;
					break;
				case 'p':
					black+=1;
					break;
			}
		}
	}
	if(black > white)
		cout << "Black\n";
	else if(black < white)
		cout << "White\n";
	else
		cout << "Draw\n";
	return 0;
}
