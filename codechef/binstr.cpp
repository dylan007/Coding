/*=======================
Author    : Shounak Dey
Filename  : binstr.cpp
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
#define popc(a) __builtin_popcount(a) // count set bits
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

typedef struct node{
	int data;
	struct node *child[2];
	int isLeaf;
	int index;
}node;

ll size(ll n){
	double rt = sqrt((double)n);
	rt = (int)rt;
	if(rt*rt == n)
		return rt;
	else
		return rt+1;
}

node *create(){
	node *newNode = (node *)malloc(sizeof(node));
	newNode->child[0] = newNode->child[1] = NULL;
	newNode->isLeaf=0;
}

void insert(node *root, string a,int index){
	node *temp = root;
	for(int i=0;i<a.length();i++){
		if(temp->child[a[i]-'0'] == NULL){
			temp->child[a[i]-'0'] = create();
			temp->child[a[i]-'0']->data = a[i]-'0';
		}
		temp = temp->child[a[i]-'0'];
		if(i==(a.length()-1)){
			temp->isLeaf = 1;
			temp->index = index;
		}
	}
}

void listall(node *root,string a){
	if(root->isLeaf)
		cout << a << " " << root->index << endl;
	REP(i,2){
		if(root->child[i]){
			if(root->child[i]->data == 0)
				listall(root->child[i],a+"0");
			else
				listall(root->child[i],a+"1");
		}
	}
	return;
}

node *copy(node *root){
	node *root2 = create();
	REP(i,2){
		if(root->child[i]!=NULL)
			root2->child[i] = copy(root->child[i]);
	}
	root2->isLeaf = root->isLeaf;
	root2->data = root->data;
	root2->index = root->index;
	return root2;
}

int main()
{
	fast_io;
	ll n;
	cin >> n;
	vector<ll> block(n);
	ll bsize = size(n);
	// Generate block number for each node.
	REP(i,n)
		block[i] = (i/bsize);
	vector<node *> rangetrie;
	vector<string> sin(n);
	int curr=0;
	node *currtrie = create();
	REP(i,n){
		if(curr != block[i])
			rangetrie.PB(copy(currtrie));
		cin >> sin[i];
		insert(currtrie,sin[i],i);
		// cout << "Iteration : " << i+1 << endl;
		// listall(currtrie,"");
		// cout << endl;
		curr = block[i];
	}
	rangetrie.PB(copy(currtrie));
	// for(auto it:rangetrie)
	// 	listall(it,"");
	int q;
	cin >> q;
	vector<pair<ll,ll>> queries;
	while(q--){
		ll x,y;
		cin >> x >> y;
		x--;y--;
		queries.PB(MK(x,y));
	}
	sort(queries.begin(),queries.end());
	return 0;
}