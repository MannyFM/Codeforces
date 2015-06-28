
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
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

int k, j;
string s;
map <char, int> m;
int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &k);
	cin >> s;
	int n = int(s.size());
	for (int i = 0; i < n; i++)
		if (m.find(s[i]) == m.end())
			m[s[i]] = i;
	if (int(m.size()) < k)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	vector <int> v;
	for (auto x : m)
		v.pb(x.S);
	sort(v.begin(), v.end());
	int sz = int(v.size());
	//sz = min(int(v.size()) - 1, k);
	for (j = 0; j < sz; j++)
	{
		if (j == sz - 1 || j == k - 1)
		{
			puts(s.substr(v[j], n - v[j]).c_str());
			break;
		}
		else
			puts(s.substr(v[j], v[j + 1] - v[j]).c_str());
	}
}
