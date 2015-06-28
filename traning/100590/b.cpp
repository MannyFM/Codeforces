
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
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "a"

map <int, int> s;
int n, a[maxn], b[maxn];

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i), s[a[i]]++;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", b + i);
		if (s[b[i]])
			ans++, s[b[i]]--;
	}
	printf("%d", ans);

}