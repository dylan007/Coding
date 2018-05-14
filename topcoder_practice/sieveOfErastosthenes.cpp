/*
 * =====================================================================================
 *
 *       Filename:  sieveOfErastosthenes.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 16 July 2016 02:36:15  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shounak Dey (), dylandey1996@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define MAX 1000000
	
int primes[MAX] = {0};

void gen_primes()
{
	primes[1] = 1;
	for(ll i=2;i<=MAX;i++)
	{
		if(primes[i] == 0)
		{
			for(ll j=2*i;j<=MAX;j+=i)
				primes[j] = 1;
		}
	}
	return;
}

int main()
{
	int n;
	cin >> n;
	//for(int i=0;i<n;i++)
	//	cout << primes[i] << endl;
	gen_primes();
	cout << primes[n] << endl;
	return 0;
}
