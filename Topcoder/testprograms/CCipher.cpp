#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class CCipher {
public:
	string decode(string, int);
};

string CCipher::decode(string cipherText, int shift) {
	string output;
	int len;
	len = cipherText.length();
	for(int i=0;i<len;i++)
	{
		int temp;
		temp = int(cipherText[i]);
		temp -= 65;
		temp -= shift;
		temp = temp%25;
		temp += 65;
		output += temp;
	}
	return output;
}


//Powered by [KawigiEdit] 2.0!
