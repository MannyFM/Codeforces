
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
#define fn "a"
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


int n;
string d[150];

bool cmp(string s, string t)
{
	int c1 = 0, c2 = 0;
	for (int i = 0; i < int(s.size()); i++)
		c1 += (s[i] == '0');
	for (int j = 0; j < int(t.size()); j++)
		c2 += (t[j] == '0');
	return c1 > c2;
}

vector <string> v;

bool can(string s, string t)
{
	int n = min(int(s.size()), int(t.size()));
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '0' || t[i] == '0')
			continue;
		return 0;
	}
	return 1;
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> d[i];
		reverse(begin(d[i]), end(d[i]));
	}
	sort(d, d + n, cmp);
	v.pb(d[0]);
	for (int i = 1; i < n; i++)
	{
		int ok = 1;
		for (int j = 0; j < int(v.size()); j++)
		{
			//cout << d[i] << " " << v[j] << " " << can(d[i], v[j]) << '\n';
			if (!can(d[i], v[j]))
			{
				ok = 0;
				break;
			}
		}
		if (ok)
			v.pb(d[i]);
	}
	printf("%d\n", v.size());
	for (int i = 0; i < int(v.size()); i++)
	{
		reverse(begin(v[i]), end(v[i]));
		cout << v[i] << " ";
	}
}