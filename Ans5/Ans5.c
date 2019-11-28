#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char * longestPalindrome(char *str);

int main()
{
    char *str;
    str = (char *)malloc(sizeof(char));
    scanf("%s", str);
    printf("%s\n", str);

    char *res;
    res = longestPalindrome(str);
    printf("%s\n", res);
    return 0;
}


char * longestPalindrome(char *str)
{
    int len = strlen(str);
    int maxSubStrLen = 0;
    int startIdx, endIdx;
    int searchIdx = 0, searchLen = 1;

    int i, m, n;
    if (len <= 1)
    {
        return str;
    }

    while (searchIdx < len)
    {
        for (i = searchIdx + 1; i < len; i++)
        {
            if (str[searchIdx] != str[i])
            {
                break;
            }
            searchLen++;
        }
        m = i;
        n = searchIdx - 1;
        while ((n >= 0) && (m < len))
        {
            if (str[n] != str[m])
            {
                break;
            }
            m++;
            n--;
            searchLen += 2;
        }
        if (searchLen > maxSubStrLen)
        {
            maxSubStrLen = searchLen;
            startIdx = n + 1;
            endIdx = m - 1;
        }
        searchLen = 1;
        searchIdx++;
    }
    str[endIdx + 1] = '\0';
    return &str[startIdx];
}