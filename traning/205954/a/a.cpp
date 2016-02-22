
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(3e5) + 17;
int const maxb = int(2e6 + 12);
int const inf = int(1e9 + 7);
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
//#define fn ""

template <typename T>
bool umax(T & a, T b)
{
	return a < b ? (a = b, 1) : 0;
}

template <typename T>
bool umin(T & a, T b)
{
	return a > b ? (a = b, 1) : 0;
}

int gcd(int x, int y)
{
    while (y)
    {
        x %= y;
        swap(x, y);
    }
    return x;
}

int n, a[maxn];
int s[30][maxn], lg[maxn];
int mn[30][maxn];

void pre()
{
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
    for (int i = 1; i <= n; i++)
    {
        s[0][i] = a[i];
        mn[0][i] = a[i];
    }
    for (int k = 1; k <= lg[n]; k++)
        for (int i = 1; i <= n; i++)
        {
            s[k][i] = gcd(s[k - 1][i], s[k - 1][i + (1 << (k - 1))]);
            mn[k][i] = min(mn[k - 1][i], mn[k - 1][i + (1 << (k - 1))]);
        }
}

bool ok(int l, int r)
{
    int k = lg[r - l + 1];
    return gcd(s[k][l], s[k][r - (1 << k) + 1]) == min(mn[k][l], mn[k][r - (1 << k) + 1]);
}

bool check(int k)
{
    for (int i = 1; i + k <= n; i++)
        if (ok(i, i + k))
            return 1;
    return 0;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    pre();
    int l = 0, r = n + 1;
    while (r - l > 1)
    {
        int m = (l + r) >> 1;
        if (check(m))
            l = m;
        else
            r = m;
    }
	vector <int> v;
	for (int i = 1; i + l <= n; i++)
		if (ok(i, i + l))
			v.pb(i);
	printf("%d %d\n", (int)v.size(), l);
	for (int x : v)
		printf("%d ", x);
}

