
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn 100000 + 12
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "rvq"
#define F first
#define S second

int n, a[maxn];
int lg[maxn];
int s[30][maxn];
//min max

void pre()
{
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
    for (int i = 1; i <= n; i++)
        s[0][i] = a[i];
    for (int k = 1; k <= lg[n]; k++)
        for (int i = 0; i <= n; i++)
            s[k][i] = min(s[k - 1][i], s[i + (1 << (k - 1))]);
}

int get(int l, int r)
{
    int k = lg[r - l + 1];
    return min(s[k][i], s[k][r - (1 << k) + 1]);
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	int m, l, r;
	scanf("%d%d%d", &n, &m, &a[1]);
	for (int i = 1; i <= n; i++)
        a[i + 1] = (23 * a[i] + 21563) % 16714589;
    scanf("%d%d", &l, &r);

}
