/*
 * =====================================================================================
 *
 *       Filename:  similar-pairs.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Tuesday 15 December 2015 10:53:13  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shounak Dey (), dylandey1996@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include<iostream>
#include<vector>

using namespace std;

vector<int> graph[110001];
int T, ST[100001*4] = {0}, N, deg[100001] = {0};

void update(int node, int b, int e, int idx, int val)  {

	if(b > node || e < node) return;

	if(b == e) {
		ST[idx] += val;
		return;
	}

	update(node, b, (b + e)/2, 2 * idx, val);
	update(node, (b + e)/2 + 1, e, 2 * idx + 1, val);

	ST[idx] = ST[2 * idx]  + ST[2 * idx + 1];

}

long Query(int l, int r, int b, int e, int idx) {

	if( l > e || r < b) return 0;

	if(l <= b && r >= e) return ST[idx];

	return Query(l, r, b, (b + e)/2, 2 * idx) + Query(l, r, (b + e)/2 + 1, e, 2 * idx + 1);
}

long long SimilarPairs(int node) {

	int l = max(1, node - T), r  = min(N, node + T);
	long res = 0;

	res = Query(l, r, 1, N, 1);

	update(node, 1, N, 1, 1);

	for(int i = 0; i < graph[node].size(); i++) {
		res +=  SimilarPairs(graph[node][i]);
	}

	update(node, 1, N, 1, -1);

	return res;
}

int main() {

	long x, y, root, result, start;


	cin >> N >> T;

	for(int i = 0; i < N - 1; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		deg[y]++;
	}

	for(int i = 1; i <= N; i++) if(!deg[i]) root = i;

	result = SimilarPairs(root);

	cout << result << endl;

	cin.get();

	return 0;

}
