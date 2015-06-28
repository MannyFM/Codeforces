
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e6 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "b"

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

int n, m, x, a[2000];

int solvemin()
{
	multiset <int> s;
	ll ans = 0;
	for (int i = 0; i < m; i++)
		s.insert(a[i]);
	x = n;
	while (x)
	{
		auto it = begin(s);
		int t = *it;
		s.erase(it);
		ans += t;
		x--;
		t--;
		if (t)
			s.insert(t);
	}
	return ans;
}

int solvemax()
{
	priority_queue <int> q;
	for (int i = 0; i < m; i++)
		q.push(a[i]);
	x = n;
	ll ans = 0;
	while (x)
	{
		int t = q.top();
		q.pop();
		ans += t;
		x--;
		t--;
		if (t)
			q.push(t);
	}
	return ans;
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d", a + i);
	printf("%d %d", solvemax(), solvemin());
}