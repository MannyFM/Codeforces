
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

int v1, v2, t, d;
int l[200], r[200];
ll L[200], R[200];
ll ans;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d%d", &v1, &v2, &t, &d);
	if (v1 > v2)
		swap(v1, v2);
	l[1] = v1, L[1] = l[1];
	r[t] = v2, R[t] = r[t];
	for (int i = 2; i <= t; i++)
	{
		l[i] = l[i - 1] + d;
		L[i] = l[i] + L[i - 1];
	}
	for (int i = t - 1; i > 0; i--)
	{
		r[i] = r[i + 1] + d;
		R[i] = R[i + 1] + r[i];
	}
	
//	for (int i = 1; i <= t; i++)
//		printf("(%d %d) ", l[i], r[i]);
//	puts("");
	
	for (int i = 1; i < t; i++)
		for (int j = i + 1; j <= t; j++)
		{
			if (r[j] - l[i] > d || r[j] - l[i] < 0)
				continue;
			ll S = L[i] + R[j] + (j - i - 1) * (min(r[j], l[i]) + d);
			if (umax(ans, S));
				//printf("[%d %d] %d -%d- %d = " I64 "\n", i, j, l[i], min(l[i], r[j]) + d, r[j], S);
		}
	for (int i = 1; i < t; i++)
	{
		if (r[i + 1] - l[i] > d || r[i + 1] - l[i] < 0)
			continue;
		if (umax(ans, R[i + 1] + L[i] + 0ll));
//			printf("%d " I64 "\n", i, s);
	}
	printf(I64, ans);
}

