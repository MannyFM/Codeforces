#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e5 + 12);
int const maxb = int(2e6 + 12);
int const inf = int(1e9 + 7);
int const mod = 1000003;
ll const linf = ll(1e18 + 12);
double const eps = 1e-7;
double const pi = acos(-1);
#ifdef _WIN32
    #define I64 "%I64d"
#else
    #define I64 "%lld"
#endif
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define next MyLittleNext
//#define end MyLittleEnd
#define all(x) x.begin(), x.end()
#define fn "army"

int n;
int a[maxn];
int pre[maxn];

int bp(int x, int y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    int a = bp(x, y >> 1);
    a = (a * a) % mod;
    if (y & 1)
        a = (a * x) % mod;
    return a;
}

void upd(int l, int r)
{
    for (int i = l; i <= r; i++)
        a[i]++;
    pre[0] = 1;
    for (int i = 1; i <= n; i++)
        pre[i] = (pre[i - 1] * 1ll * a[i]) % mod;
}

int get(int l, int r)
{
    return (pre[r] * 1ll * (pre[l - 1] ? bp(pre[l - 1], mod - 2) : 1)) % mod;
}

int main()
{
    #ifdef fn
        freopen(fn".in", "r", stdin);
        freopen(fn".out", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        a[i] =
    }
    upd(0, 0);
    int m, x, y, c;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &c, &x, &y);
        if (c)
        {
            printf("%d\n", get(x, y));
        }
        else
        {
            upd(x, y);
        }
    }
}