
#include <bits/stdc++.h>

using namespace std;

#define inf (int)(1e9 + 7)
#define maxn (int)(1e5 + 12)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define fn "abcd"

int n, x;

int main()
{
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d", &x);
        a = x / 100;
        b = x % 100;
        puts((a * a + b * b) % 7 == 1 ? "YES" : "NO");
    }
    
}
