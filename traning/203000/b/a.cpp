
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
int const sz = 'z' - 'a' + 1;
ll const linf = ll(1e18 + 12);
double const eps = 1e-7;
double const pi = acos(-1);
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

int n, k;
bool good[sz];
string s;

struct item
{
	int next[sz];
	item()
	{
		for (int i = 0; i < sz; i++)
			next[i] = 0;
	};
};

vector <item> T;

void add(string s)
{
	int v = 0;
	for (int i = 0; i < int(s.size()); i++)
	{
		int x = s[i] - 'a';
		int to = T[v].next[x];
		if (!to)
		{
			T[v].next[x] = int(T.size());
			T.pb(item());
			to = T[v].next[x];
		}
		v = to;
	}
}

bool Find(string s)
{
	int v = 0;
	for (int i = 0; i < int(s.size()); i++)
	{
		int x = s[i] - 'a';
		int to = T[v].next[x];
		if (!to)
			return false;
		v = to;
	}
	return true;
}

int get(int v, int now)
{
	int ans = 1;
	for (int i = 0; i < sz; i++)
	{
		int to = T[v].next[i];
		if (to && now + !good[i] <= k)
			ans += get(to, now + !good[i]);
	}
	return ans;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	T.pb(item());
	cin >> s;
	char _c;
	for (int i = 0; i < sz; i++)
	{
		scanf("\n%c", &_c);
		good[i] = _c == '1';
	}
	scanf("%d", &k);
	n = int(s.size());
	for (int i = 0; i < n; i++)
		add(s.substr(i, int(s.size() - i)));
	printf("%d", get(0, 0) - 1);
}
