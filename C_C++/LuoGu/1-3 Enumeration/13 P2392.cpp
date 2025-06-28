#include <iostream>
#include <string.h>
using namespace std;

const int COURSE = 4; // 课程数量
const int M_S = 20; // 最大作业数量
const int M_T = 60; // 作业最大时间
int main()
{
    int ans = 0; // 最终结果
    int course[COURSE]; // 存储每个课程的作业数量
    int work[M_S]; // 存储一个作业花费的时间
    int dp[M_S * M_T / 2 + 1]{}; // 背包

    /* 输入作业数量*/
    for(int _ = 0; _ < COURSE; _++)
        cin >> course[_];

    /*分别对每个课程进行运算*/
    for(int i = 0; i < COURSE; i++) {
        int sum = 0; // 该课程总时间
        /*输入作业花费时间*/
        for(int j = 0; j < course[i]; j++) {
            cin >> work[j];
            sum += work[j];
        }

        /*解背包问题*/
        for(int j = 0; j < course[i]; j++) // 遍历作业
            for(int k = sum / 2; k >= work[j]; k--) // 遍历背包
                /*
                    通过动态规划解决背包问题
                    大的背包由小的背包所决定
                */
                dp[k] = max(dp[k], dp[k - work[j]] + work[j]);
        
        /*这门课程花费的时间*/
        ans += sum - dp[sum / 2];
        /*初始化背包*/
        memset(dp, 0, sizeof(dp) / sizeof(int));
    }
    cout << ans;
    return 0;
}