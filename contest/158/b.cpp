
#include <bits/stdc++.h>

using namespace std;

int n, x;
char a[100];

int main()
{
    //freopen("i.txt", "r", stdin);
    scanf("%d", &n);
    a[0] = '#';
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        x += a[i] == a[i - 1];
        //cout << a[i] << " " << a[i - 1] << '\n';
    }
    printf("%d", x);
}
