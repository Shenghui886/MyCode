#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {

    int _,__;
    cin >> _ >> __;
    int h=8,m=-10;
    m -= (_-1)/__+1;
    h -= ceil(abs(m) / 60.0);
    h = (h+24)%24;
    m += ceil(abs(m) / 60.0) * 60;
    printf("%02d:%02d", h, m);

    return 0;
}