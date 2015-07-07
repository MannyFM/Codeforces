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
ll const linf = ll(1e18 + 12);
double const eps = 1e-7;
double const pi = acos(-1);
#ifdef WIN32
    #define I64 "%I64d"
#else
    #define I64 "%lld"
#endif
#define mp make_pair
#define pb push_back
#define F first
#define S second
//#define fn ""

int n, x;
int cnt[(1 << 12) + 12];
int ans = 0;
vector <pii> a;
vector <pii> b;

void f()
{
	int sz = int(a.size());
	for (int i = 0; i < sz; i += 2)
	{
		pii buff;
		buff.F = a[i].F / 2;
		buff.S = max(a[i].S, a[i + 1].S) + cnt[buff.F];
		ans += abs(a[i].S - a[i + 1].S);
		b.pb(buff);
	}
	/*
	for (int i = 0; i < int(a.size()); i++)
		printf("%d %d  ", a[i].F, a[i].S);
	puts("");
	for (int i = 0; i < int(b.size()); i++)
		printf("%d %d  ", b[i].F, b[i].S);
	puts("");
	*/
}
int main()
{
    #ifdef fn
        freopen(fn".in", "r", stdin);
        freopen(fn".out", "w", stdout);
    #endif
    scanf("%d", &n);
    int sz = (1 << (n + 1)) - 2;
    for (int i = 2; i <= sz + 1; i++)
    	scanf("%d", cnt + i);
    for (int i = 0, j = (1 << n); i < (1 << n); i++, j++)
    	a.pb(mp(j, cnt[j]));
    while (a.size() > 1)
    {
    	f();
    	a = b;
    	b.clear();
    }
    printf("%d", ans);
}
