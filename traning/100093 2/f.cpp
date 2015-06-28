#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e5 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define sqr(x) ((x) * (x))
#define mp make_pair
#define pb push_back
#define fn "forest"
#define LOCAL

int v1, v2;
long double a;

long double d(long double xa, long double ya, long double xb, long double yb)
{
    long double ans = sqr(xa - xb) + sqr(ya - yb);
    ans = sqrt(ans);
    return ans;
}

long double f(long double x)
{
    long double s1 = d(0.0, 1.0, x, a);
    long double s2 = d(x, a, 1.0, 0.0);
    long double t1 = s1 / v1;
    long double t2 = s2 / v2;
    return t1 + t2;
}

int main()
{
    #ifdef LOCAL
        freopen(fn".in", "r", stdin);
        freopen(fn".out", "w", stdout);
    #endif
    cin >> v1 >> v2 >> a;
    long double l = 0.0, r = 1.0;
    for (int i = 0; i < 300000; i++)
    {
        //cout << l << " " << r << '\n';
        long double m1 = l + (r - l) / 3;
        long double m2 = r - (r - l) / 3;
        if (f(m1) > f(m2))
            l = m1;
        else
            r = m2;
    }
    printf("%.12f", (double)l);
    //printf("%.09f %.09f", l, r);
}
