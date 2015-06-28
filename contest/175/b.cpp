
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
#define F first
#define S second

map <string, int> m;
vector <int> v;
int n;

string calc(int x)
{
	int pos = 0;
	while (pos < int(v.size()) && v[pos] != x)
		pos++;
	double d = (pos + .0) / (v.size() + .0);
	double nd = 1 - d;
	//printf("%.9f ", nd);
	if (d > 0.5)
		return "noob";
	if (d >= 0.2)
		return "random";
	if (d >= 0.1)
		return "average";
	if (d >= 0.01)
		return "hardcore";
	return "pro";
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		string s;
		int pts;
		cin >> s >> pts;
		m[s] = max(m[s], pts);
	}
	for (auto i : m)
		v.pb(i.S);
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	printf("%d\n", v.size());
	for (auto i : m)
	{
		printf("%s %s\n", i.F.c_str(), calc(i.S).c_str());
	}
}
