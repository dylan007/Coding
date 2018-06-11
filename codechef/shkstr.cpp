/*=======================
Author    : Shounak Dey
Filename  : shkstr.cpp
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

typedef struct node{
	char data;
	node *next[26];
	int eow;
}node;

node *create(){
	node *newNode = (node *)malloc(sizeof(node));
	REP(i,26)
		newNode->next[i] = NULL;
	newNode->eow=0;
	return newNode;
}

void insert(node *root,string a){
	node *temp = root;
	for(int i=0;i<a.length();i++){
		if(temp->next[a[i]-'a'] == NULL){
			temp->next[a[i]-'a'] = create();
			temp->next[a[i]-'a']->data = a[i];
		}
		temp = temp->next[a[i]-'a'];
		if(i==(a.length()-1))
			temp->eow = 1;
	}
}

string findMin(node *root,string a){
	string out = "";
	node *temp = root;
	for(int i=0;i<a.length();i++){
		if(temp->next[a[i]-'a'] == NULL){
			break;
		}
		else{
			out += a[i];
			temp = temp->next[a[i]-'a'];
		}
	}
	// cout << "PREFIX : ";
	// cout << out << endl;
	while(1){
		int flag=0,i;
		if(temp == NULL){
			// cout << "TEMP NULL" << endl;
			return out;
		}
		if(temp->eow){
			// cout << "END OF WORD" << endl;
			return out;
		}
		for(i=0;i<26;i++){
			if(temp->next[i]!=NULL){
				flag=1;
				break;
			}
		}
		if(!flag)
			return out;
		out += temp->next[i]->data;
		temp = temp->next[i];
	}
	// cout << "DONE" << endl;
	return out;
}

void listall(node *root,string a){
	if(root->eow)
		cout << a << endl;
	REP(i,26){
		if(root->next[i])
			listall(root->next[i],a+root->next[i]->data);
	}
	return;
}

node *copy(node *root){
	node *root2 = create();
	REP(i,26){
		if(root->next[i]!=NULL)
			root2->next[i] = copy(root->next[i]);
	}
	root2->eow = root->eow;
	root2->data = root->data;
	return root2;
}

int main()
{
	int n;
	cin >> n;
	vector<node *> point;
	vector<string> s(n);
	REP(i,n){
		cin >> s[i];
	}
	int q;
	cin >> q;
	map<int,string> ans;
	map<int,vector<pair<string,int>>> query;
	REP(i,q){
		int r;
		string x;
		cin >> r >>x;
		r--;
		if(query.find(r) != query.end()){
			query[r].PB(MK(x,i));
		}
		else{
			vector<pair<string,int>> temp;
			temp.PB(MK(x,i));
			query[r] = temp;
		}
	}
	node *root = create();
	REP(i,n){
		insert(root,s[i]);
		if(query.find(i) != query.end()){
			vector<pair<string,int>> q = query[i];
			REP(j,q.size()){
				ans[q[j].second] = findMin(root,q[j].first);
			}
		} 
	}
	REP(i,q){
		cout << ans[i] << endl;
	}
	return 0;
}
