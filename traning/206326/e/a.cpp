
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
#define fn "f"

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


int n, m, N = (int)1e5;
int a[maxn], sz;
int t[maxn], l[maxn], c[maxn];
ll len[maxn];

int f(ll j)
{
	int L = 0, R = n + 1;
	while (R - L > 1)
	{
		int md = L + (R - L) / 2;
		if (len[md] < j)
			L = md;
		else
			R = md;
	}
	if (t[R] == 1)
		return l[R];
	j = ((j - len[R - 1]) - 1) % l[R] + 1;
	return a[j];
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", t + i, l + i);
		len[i] = len[i - 1];
		if (t[i] == 1)
		{
			len[i]++;
			if (sz < N)
				a[++sz] = l[i];
		}
		else
		{
			scanf("%d", c + i);
			len[i] += c[i] * 1ll * l[i];
			int j = 1, cnt = 0;
			while (sz < N && cnt < c[i])
			{
				a[++sz] = a[j++];
				if (j > l[i])
					cnt++, j = 1;
			}
		}
	}
//	for (int i = 1; i <= sz; i++)
//		printf("%d ", a[i]);
//	puts("");
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		ll x;
		scanf(I64, &x);
		printf("%d ", f(x));
	}
}

