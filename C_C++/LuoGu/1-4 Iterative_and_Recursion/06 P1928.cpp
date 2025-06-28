// P1928 外星密码
// Use stack DAT

#include<stdio.h>

int main(void) {

    int count = 0, num = 0;
    char ch = 0, arr[20000];
    while((ch = getchar()) != EOF)
    {
        if(ch == '[')
        {
            count++;
            while((ch = getchar()) != ']')
                arr[num++] = ch;
            arr[num] = '\0';
            for(int i = 0; i < arr[0]; i++) 
                fputs(arr + 1, stdout);
        }
    }

    return 0;
}

