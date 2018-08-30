/*=======================
Author    : Shounak Dey
Filename  : 1b.cpp
=======================	*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define MK make_pair 
#define SZ(a) (int)(sizeof(a))
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define read(n) scanf("%d",&n)
#define readl(n) scanf("%lld",&n)
#define readul(n) scanf("%llu",&n);


#define SORTV(a) sort(a.begin(),a.end())
#define TEST int Test;cin >> Test;while(Test--)
#define gcd(a,b) __gcd(a,b)
#define ffs(a) __builtin_ffs(a) // find first set
#define clz(a) __builtin_clz(a) // count leading zeroes
#define ctz(a) __builtin_ctz(a) // count trailing zeroes
#define popc(a) __ builtin_popcount(a) // count set bits
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)


#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }

vector<string> split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return move(v);
}

void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
	cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
	err(++it, args...);
}

int check(string a){
	FOR(i,1,a.length()-1){
		if(a[i]=='C' && (a[i-1]>='0' && a[i-1]<='9') && (a[i+1]>='0' && a[i+1]<='9'))
			return 1;
	}
	return 0;
}

int main()
{
	TEST{
		string a;
		cin >> a;
		string out = "";
		if(check(a)){
			int r,c;
			r = c=0;
			int pos=1;
			while(a[pos]!='C'){
				r = r*10 + (a[pos]-'0');
				pos++;
			}
			pos++;
			while(pos<a.length()){
				c = c*10 + (a[pos]-'0');
				pos++;
			}
			while(c){
				int temp = (c)%26;
				if(temp==0)
					out = 'Z' + out;
				else
					out = char(temp+'A'-1) + out;
				c /= 26;
				error(temp,c);
			}
			out += to_string(r);
		}
		else{
			int index,r=0;
			int pos = 0;
			int c=0;
			while(pos<a.length()){
				if((a[pos-1]>='A' && a[pos-1]<='Z') && (a[pos]>='0' && a[pos]<='9'))
					break;
				c = c*26 + (a[pos]-'A'+1);
				pos++;
			}
			while(pos<a.length()){
				r = r*10 + (a[pos]-'0');
				pos++;
			}
			// error(r,c);
			out += "R" + to_string(r) + "C" + to_string(c);
		}
		cout << out << endl;
	}
	return 0;
}