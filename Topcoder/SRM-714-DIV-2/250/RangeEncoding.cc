
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

class RangeEncoding
{
public:
	int minRanges(vector <int> arr)
	{
		sort(arr.begin(),arr.end());
		int ans=0;
		int curr=arr[0];
		for(int i=1;i<arr.size();i++)
		{
			if(curr == (arr[i]-1))
			{
				curr = arr[i];
				continue;
			}
			ans++;
			curr = arr[i];
		}
		return ans;
	}
};

