#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *num1, *num2;

int cmp(char **str1, char **str2)
{
    int len1 = strlen(*str1);
    int len2 = strlen(*str2);

    if(len1 - len2 < 0 || (len1 == len2 && strcmp(*str1, *str2) < 0))
    {
        char *tmp = *str2;
        *str2 = *str1;
        *str1 = tmp;
        return -1;
    }
    if(strcmp(*str1, *str2) == 0)
        return 0;
    return 1;
}


void minus(char *str1, const char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for(int i = 1; i <= len2; i++)
        str1[len1 - i] -= str2[len2 - i] - '0';

    for(int i = 1; i <= len1; i++)
        if(str1[len1 - i] < '0')
        {
            str1[len1 - i] += 10;
            str1[len1 - i - 1]--;
        } 
        

}

int main(void) {
    
    num1 = (char *)malloc(10100 * sizeof(char));
    num2 = (char *)malloc(10100 * sizeof(char));
    
    scanf("%s", num1);
    scanf("%s", num2);
    int a = cmp(&num1, &num2);
    minus(num1, num2);
    char *out = NULL;
    if(a == 0)
    {
        putchar('0');
        return 0;
    }
    if(a < 0)
        putchar('-');
    for(int i = 0;; i++)
       if(num1[i] > '0')
       {
           out = &num1[i];
           break;
       }

    puts(out);

    return 0;
}
