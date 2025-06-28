#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {

    int water=20*100;
    int h,r;
    cin >> h >> r;
    double pi=3.14;
    cout << ceil(water/(h*r*pi)) << endl;

    return 0;
}