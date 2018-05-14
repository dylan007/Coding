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

vector<int> arr;

typedef struct node
{
	int data,l,r;
	struct node *left,*right;
}node;

node* create()
{
	node *temp;
	temp = (node *)malloc(sizeof(node));
	temp->left = temp->right =NULL;
	return temp;
}

node* buildrmq(node *head,int x,int y)
{
	head = create();
	if(x==y)
	{
		head->l = x;
		head->r = y;
		head->data = arr[x];
		return head;
	}
	int mid = (x+y)/2;
	head->left = buildrmq(head,x,mid);
	head->right = buildrmq(head,mid+1,y);
	head->data = max(head->left->data,head->right->data);
	head->l = x;
	head->r = y;
	return head;
}

void update(node *head,int pos,int x)
{
	int a = head->l;
	int b = head->r;
	if(pos<a || pos>b)
		return;
	head->data = max(head->data,x);
	update(head->left,pos,x);
	update(head->right,pos,x);
	return;
}

int qrmq(node *head,int x,int y)
{
	if((head->l >= x)&&(head->r <= y))
		return head->data;
	else if((head->l > y) || (head->r < x))
		return INT_MIN;
	return max( qrmq(head->left,x,y),qrmq(head->right,x,y));
}

int main()
{
	int n,x;
	read(n);
	REP(i,n)
	{
		read(x);
		arr.PB(x);
	}
	node *head;
	head = buildrmq(head,0,n-1);
	TEST
	{
		int x,l,r;
		cin >> x >> l >> r;
		cout << x << endl;
		if(x==1)
		{
			l--;
			r--;
			cout << qrmq(head,l,r) << endl;
		}
		else
			update(head,l-1,r);
	}
	return 0;
}

