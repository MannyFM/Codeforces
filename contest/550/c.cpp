
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
#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif
#define mp make_pair
#define pb push_back
#define F first
#define S second

set <int> pos[12];

bool check(int x)
{
	vector <int> v;
	int y = x;
	while (y > 0)
		v.pb(y % 10), y /= 10;
	if (x == 0)
		v.pb(x);
	reverse(v.begin(), v.end());
	int r = -1;
	//printf("%d:\n", x);
	for (int i = 0; i < int(v.size()); i++)
	{
		auto it = pos[v[i]].upper_bound(r);
		if (it == pos[v[i]].end())
			return 0;
		r = *it;
		//printf("%d %d\n", v[i], r);
	}
	return 1;
}

string s;
vector <int> e;

int main()
{
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	for (int x = 0; x <= 1000; x += 8)
		e.pb(x);
	cin >> s;
	int n = int(s.length());
	for (int i = 0; i < n; i++)
		pos[s[i] - '0'].insert(i);
	for (int i = 0; i < int(e.size()); i++)
		if (check(e[i]))
		{
			printf("YES\n%d", e[i]);
			return 0;
		}
	puts("NO");
}
