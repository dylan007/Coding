#include<bits/stdc++.h>

using namespace std;

typedef struct node{
	struct node* child[26];
	bool isLeaf;
}node;

struct node *newNode(){
	struct node *temp;
	temp = (node *)malloc(sizeof(node));
	for(int i=0;i<26;i++)
		temp->child[i] = NULL;
	temp->isLeaf = true;
	return temp;
}


void insert(node *head, string data,int pos)
{
	int temp = int(data[pos])-int('a');
	if(head->child[temp] == NULL)
		head->child[temp]=newNode();
	pos++;
	if(pos<data.length())
	{
		head->isLeaf = false;
		insert(head->child[temp],data,pos);
	}
	else
		head->isLeaf = true;
}

int find(node *head, string data, int pos)
{
	//cout << data[pos] << endl;
	int temp = int(data[pos])-int('a');
	//cout << temp << " " << head->child[temp] << endl;
	if(!head->isLeaf && pos+1==data.length())
		return data.length()+1;
	if(head->isLeaf && (pos+1 != data.length()))
		return pos+2;
	if(head->child[temp] == NULL)
		return pos+1;
	return find(head->child[temp],data,pos+1);
}

int main()
{
	int n;
	cin >> n;
	string temp;
	getline(cin,temp);
	vector<string> firewall,out;
	node *head = newNode();
	for(int i=0;i<n;i++)
	{
		string a;
		getline(cin,a);
		//cout << a << endl;
		if(a[0]=='+')
		{
			a = a.substr(2);
			insert(head,a,0);
		}
		else
		{
			a = a.substr(2);
			firewall.push_back(a);
		}
	}
	int flag=0;
	for(int i=0;i<firewall.size();i++)
	{
		int pos = find(head,firewall[i],0);
		if(pos>firewall[i].length())
			flag = 1;
		out.push_back(firewall[i].substr(0,pos));
	}
	if(flag){
		cout << "-1" << endl;
		return 0;
	}
	sort(out.begin(),out.end());
	cout << out.size() << endl;
	for(int i=0;i<out.size();i++)
		cout << out[i] << endl;
	return 0;
}

