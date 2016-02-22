
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

int n;
vector <int> g[maxn];
map <string, int> id;

string norm(const string & s)
{
	string ans = "";
	for (char c : s)
		if ('A' <= c && c <= 'Z')
			ans += c - 'A' + 'a';
		else
			ans += c;
	return ans;
}

int dfs(int v)
{
	int ans = 0;
	for (int to : g[v])
		umax(ans, dfs(to));
	return ans + 1;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		string s, t;
		cin >> s >> t;
		cin >> t;
		s = norm(s);
		t = norm(t);
		if (!id.count(s))
			id[s] = id.size();
		if (!id.count(t))
			id[t] = id.size();
		g[id[t]].pb(id[s]);
	}
	printf("%d", dfs(id["polycarp"]));
}

