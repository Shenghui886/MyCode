// 暴力搜索

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

    int R ,C ,K, ans = 0,  spatialAns = 0;
    cin >> R >> C >> K;
    bool playGround[R][C];
    for(int i = 0; i < R; i++) {
        int line = 0;
        for(int j = 0; j < C; j++) {
            char _;
            cin >> _;
            spatialAns += playGround[i][j] = (_ == '.');
            if(K == 1) continue;
            if(playGround[i][j]) {
                line++;
            } else {
                if(line>=K) ans+=line-K+1;
                line = 0;
            }
        }
        if(line>=K) ans+=line-K+1;
    }
    if(K==1) {
        cout << spatialAns;
        return 0;
    }
    for(int i = 0; i < C; i++) {
        int line = 0;
        for(int j = 0; j < R; j++) {
            if(playGround[j][i]) {
                line++;
            } else {
                if(line>=K) ans+=line-K+1;
                line = 0;
            }
        }
        if(line>=K) ans+=line-K+1;
    }
    cout << ans;

    return 0;
}