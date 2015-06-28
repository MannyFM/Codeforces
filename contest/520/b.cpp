
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e4 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

int n, m;
int us[maxn];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	if (n > m)
	{
		printf("%d", n - m);
		return 0;
	}
	queue <int> q;
	q.push(n);
	us[n] = 1;
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		if (v == m)
			break;
		if (v > 1 && !us[v - 1])
		{
			us[v - 1] = us[v] + 1;
			q.push(v - 1);
		}
		if (v + v < maxn && !us[v + v])
		{
			us[v + v] = us[v] + 1;
			q.push(v + v);
		}
	}
	printf("%d", us[m] - 1);
}