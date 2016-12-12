#ifdef JUDGE
#include <fstream>
std::ifstream cin("aplusb.in");
std::ofstream cout("aplusb.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

int main() {
    int a, b;
    cin >> a >> b;
    cout << a + b << std::endl;
    return 0;
}
