

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

class MaximumRangeDiv2
{
public:
	int findMax(string s)
	{
		int c1=0,c2=0;
		for(int i=0;i<s.length();i++)
		{
			c1 += s[i]=='+';
			c2 += s[i]=='-';
		}
		return max(c1,c2);
	}
};

