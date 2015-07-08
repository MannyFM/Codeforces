#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e5 + 12);
int const maxlen = int(1e6 + 12);
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
//#define fn ""

int n, a[maxn];
int cnt[maxlen], L, R;
ll ans;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	L = maxlen, R = -maxlen;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		cnt[a[i]]++;
		L = min(L, a[i]);
		R = max(R, a[i]);
	}
	int last = R + 1;
	for (int len = R; len >= L; len--)
	{
		if (cnt[len] & 1)
		{
			cnt[len]--;
			if (cnt[len - 1])
				cnt[len - 1]++;
		}
		if (last != R + 1)
		{
			int C = min(cnt[len] / 2, cnt[last] / 2);
			/*
			if (C)
				printf(" %d %d %d " I64 "\n", len, last, C, C * 1ll * last * len);
			*/
			ans += C * 1ll * last * len;
			cnt[len] -= C * 2;
			cnt[last] -= C * 2;
		}
		ans += (cnt[len] / 4) * 1ll * len * len;
		/*
		if (cnt[len])
			printf("%d " I64 "\n", len, (cnt[len] / 4) * 1ll * len * len);
		*/
		cnt[len] -= (cnt[len] / 4) * 4;
		if (cnt[len])
			last = len;
	}
	printf(I64, ans);
	
}
