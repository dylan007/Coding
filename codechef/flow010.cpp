#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string a;
        cin >> a;
        switch(a[0])
        {
            case 'b':
            case 'B':
                cout << "BattleShip" << endl;
                break;
            case 'c':
            case 'C':
                cout << "Cruiser" << endl;
                break;
            case 'd':
            case 'D':
                cout << "Destroyer" << endl;
                break;
            case 'f':
            case 'F':
                cout << "Frigate" << endl;
                break;
        }
    }
    return 0;
}
