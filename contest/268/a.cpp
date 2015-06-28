
#include <bits/stdc++.h>

using namespace std;

int n, cnt;
int a[100020];

int main()
{
    cnt = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i++)
        if (a[i] != a[i - 1])
            cnt++;
    printf("%d", cnt);
}
