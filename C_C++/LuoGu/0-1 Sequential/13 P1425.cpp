#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

    int h1,m1,h2,m2;
    cin >> h1 >> m1 >> h2 >> m2;
    cout << (m1>=m2?h2-h1-1:h2-h1) << ' ' << (m2-m1+60)%60 << endl;

    return 0;
}