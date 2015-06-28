
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e5 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "c"
#define f first
#define s second

template<typename T>
T min(T a, T b, T c)
{
	return min(a, min(b, c));
}

template<typename T>
T max(T a, T b, T c)
{
	return max(a, max(b, c));
}

vector <pii> v;
int n, m, a[maxn], b[maxn];

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		v.pb(mp(a[i], 0));
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", b + i);
		v.pb(mp(b[i], 1));
	}
	int f = 3 * n, s = 3 * m;
	int F = f, S = s;
	sort(begin(v), end(v));
	for (int i = 0; i < int(v.size()); )
	{
		int j = i;
		while (j < int(v.size()) && v[i].f == v[j].f)
		{
			if (v[j].s)
				s--;
			else
				f--;	
			j++;
		}
		if (f - s > F - S || (f - s == F - s && f > F))
		{
			F = f;
			S = s;
		}
		i = j;
	}
	printf("%d:%d", F, S);

}