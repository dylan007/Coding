#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class YahtzeeScore {
public:
	int maxPoints(vector <int>);
};

int YahtzeeScore::maxPoints(vector <int> toss) {

	int temp=0,c=0;
	int max=0;
	sort(toss.begin(),toss.begin() + 6);
	for(int i=0;i<6;i++)
	{
		if(temp!=toss[i])
		{
			max = (max>(c*temp))?max:(c*temp);
			temp = toss[i];
			c=1;
		}
		else
			c++;
	}
	max = (max > (c*temp))?max:(c*temp);
	return max;
}


double test0() {
	int t0[] = { 2, 2, 3, 5, 4 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	YahtzeeScore * obj = new YahtzeeScore();
	clock_t start = clock();
	int my_answer = obj->maxPoints(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = { 6, 4, 1, 1, 3 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	YahtzeeScore * obj = new YahtzeeScore();
	clock_t start = clock();
	int my_answer = obj->maxPoints(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = { 5, 3, 5, 3, 3 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	YahtzeeScore * obj = new YahtzeeScore();
	clock_t start = clock();
	int my_answer = obj->maxPoints(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 10;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
