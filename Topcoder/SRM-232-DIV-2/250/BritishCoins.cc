
// {{{ VimCoder 0.3.6 <-----------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

// }}}

class BritishCoins
{
public:
	vector <int> coins(int pence)
	{
		vector<int> a;
		a.push_back(pence/240);
		pence %= 240;
		a.push_back(pence/12);
		pence %=12 ;
		a.push_back(pence);
		return a;
	}
};

