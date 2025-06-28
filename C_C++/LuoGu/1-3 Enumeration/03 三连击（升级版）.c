// P1618 三连击（升级版）

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool arr[10];

int main(void) {
	
	bool judge = false;
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	
	for(int i = 102; i <= 500; i++)
	{
		int ansa = i;
		int ansb = i * b * 1. / a;
		int ansc = i * c * 1. / a;
        if(ansb < 1000 && ansc < 1000)
        {
            for(int j = 0; j < 3; j++)
            {
                arr[ansa % 10] = true;
                arr[ansb % 10] = true;
                arr[ansc % 10] = true;
                ansa /= 10;
                ansb /= 10;
                ansc /= 10;
            }
            int m = 1;
            for(; m < 10; m++)
                if(!arr[m])
                    break;
            if(m == 10)
            {
                printf("%d %d %d\n", i, (int) (i * b * 1. / a), (int) (i * c * 1. / a));
                judge = true;
            }
		}
		memset(arr, false, sizeof(bool) * 10);
	}
	if(!judge)
		puts("No!!!");
	
	return 0;
}
