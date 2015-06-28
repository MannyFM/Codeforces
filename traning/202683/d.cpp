
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
#define fn "sum2"
#define F first
#define S second

int n;
ll a[maxn];
vector <ll> s;
int len;

ll sum(int l, int r)
{
	ll ans = 0ll;
	for (int i = l; i <= r; )
	{
		//printf("%d %I64d ", i, ans);
		if (i % len == 0 && i + len - 1 <= r)
		{
			//printf("%I64d\n", s[i / len]);
			ans += s[i / len];
			i += len;
		}
		else
		{
			ans += a[i];
			i++;
		}
	}
	//printf("%I64d\n", ans);
	return ans;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%I64d", a + i);
	len = int(sqrt(n)) + 1;
	s.assign(len, 0ll);
	for (int i = 0; i < n; i++)
		s[i / len] += a[i];
	/*
	printf("%d\n", len);
	for (auto i : s)
		printf("%d ", i);
	puts("");
	*/
	int m, l, r;  ;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &l, &r);
		printf("%I64d\n", sum(l - 1, r - 1));
	}	
}
