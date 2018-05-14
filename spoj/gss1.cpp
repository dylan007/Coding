//Shounak Dey
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

struct node{
	int best,left,right,segsum;
	node(){
		best = 0;
		left = 0;
		right = 0;
		segsum = 0;
	}
};

void merge(node &root,node &a,node &b){
	root.segsum = a.segsum + b.segsum;
	root.left = max(a.segsum + b.left,a.left);
	root.right = max(a.right+b.segsum,b.right);
	root.best = max(max(a.best,b.best),a.right+b.left);
}


void build(vector<int> &tree,vector<int> arr,int low,int high,int curr)
{
	if(low == high){
		tree[curr].best = tree[curr].segsum = tree[curr].left = tree[curr].right = arr[low];
		return;
	}
	int mid = (low+high)/2;
	int parent = curr;
	curr <<= 1;
	build(tree,arr,low,mid,curr);
	tree[parent] = max(tree[parent],tree[curr]);
	curr |= 1;
	build(tree,arr,mid+1,high,curr);
	merge(tree[parent],tree[curr-1],tree[curr]);
	return;
}

int query(vector<int> tree,int l,int r,int low,int high,int curr)
{
	//cout << low << " " << high << endl;
	if(l>=low && high<=r)
		return tree[curr];
	if(high<l || low>r)
		return INT_MIN;
	int mid = (low+high)/2;
	return max(query(tree,l,r,low,mid,curr*2),query(tree,l,r,mid+1,high,curr*2+1));
}


int main()
{
	int n;
	read(n);
	vector<int> arr(n);
	REP(i,n)
		read(arr[i]);
	vector<node> tree(n<<1+1);
	//cout << tree.size() << endl;
	build(tree,arr,0,n-1,1);
	for(auto it:tree)
		cout << it.best << " " << it.left << " " << it.right << " " << it.segsum << endl;
	//FOR(i,1,tree.size())
	//	cout << tree[i] << " ";
	//cout << endl;
//	int q;
//	cin >> q;
	//while(q--)
//	{
	//	int x,y;
	//	read(x);read(y);
	//	cout << query(tree,x-1,y-1,0,n,1) << endl;
//	}
	return 0;
}

