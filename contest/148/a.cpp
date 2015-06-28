
#include <bits/stdc++.h>

using namespace std;

t

int main()
{
    scanf("%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &d);
    for(int i = 1; i <= d; i++)
    {
        for(int j = 0; j < 4; j++)
            if (i % a[j] == 0)
        {
            cnt++;
            break;
        }
    }
    printf("%d", cnt);
}
