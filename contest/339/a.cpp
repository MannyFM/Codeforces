
#include <bits/stdc++.h>

using namespace std;

int n, a[100];
char x;

int main()
{
    string s;
    cin >> s;
    for(int i = 0; i < (int)(s.length()); i += 2)
    {
        a[n++] = s[i] - '0';
    }
    sort(a, a + n);
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d+", a[i]);
    }
    printf("%d", a[n - 1]);
}
