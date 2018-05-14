
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

class ImageCompression
{
public:
	string isPossible(vector <string> image, int k)
	{
		for(int i=0;i<image.size();i++)
		{
			string temp = image[i];
			for(int i=0;i<(temp.length()/k);i++)
			{
				char curr = temp[i*k];
				for(int j=i*k;j<(i+1)*k;j++)
				{
					if(curr != temp[j])
						return "Not Possible";
				}
			}
		}
		return "Possible";
	}
};

