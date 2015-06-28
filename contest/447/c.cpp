
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e5 + 12)
#define inf int(1e9 + 7)
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

int n, a[maxn], ans;
int l[maxn], r[maxn];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	int t = 0;
	for (int i = 1; i <= n; i++)
	{
		t = max(t, i + 1);
		while (t <= n && a[t] > a[t - 1])
			t++;
		r[i] = t;
		ans = max(ans, r[i] - i + 1);
	}
	t = n;
	ans = min(ans, n);
	for (int i = n; i > 0; i--)
	{
		t = min(t, i - 1);
		while (t && a[t] < a[t + 1])
			t--;
		l[i] = t;

	}
	for (int i = 1; i <= n; i++)
		if (a[i + 1] - a[i - 1] > 1)
			ans = max(ans, r[i + 1] - l[i - 1] - 1);
	printf("%d", ans);
}
