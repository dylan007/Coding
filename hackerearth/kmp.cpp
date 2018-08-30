#include<bits/stdc++.h>

using namespace std;

void construct(vector<int> &F,string p){
    F[0] = 0;
    for(int i=1;i<F.size();i++){
        int j = F[i-1];
        while(j>0 && p[i]!=p[j])
            j = F[j-1];
        if(p[i]==p[j])
            j++;
        F[i] = j;
    }
    return;
}

int main(){
    string p,t;
    cin >> p >> t;
    vector<int> F(p.length());
    construct(F,p);
    int ans=0,q=0;
   	for(int i=0;i<t.length();i++){
   		while(q>0 && p[q]!=t[i])
   			q = F[q];
   		if(p[q]==t[i])
   			q++;
   		if(q==p.length()){
   			ans++;
   			q = F[q-1];
   		}
   	}
    cout << ans << endl;
    return 0;
}