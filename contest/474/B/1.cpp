
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5+12)
#define maxq (int)(1e6+12)
#define inf (int)(1e9+7)

int a[maxn], n, pos[maxq], m, x;
int s[maxn];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    s[0] = a[0];
    for(int i = 0; i < s[0]; i++)
        pos[i] = 1;
    for(int i = 1; i < n; i++)
    {
        s[i] = s[i - 1] + a[i];
        for(int j = s[i - 1]; j < s[i]; j++)
            pos[j] = i + 1;
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> x;
        cout << pos[x - 1] << '\n';
    }
}
