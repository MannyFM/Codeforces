
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn 1000 + 12
#define inf int(1e9 + 7)
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

vector <string> nodes;
vector <int> g[maxn];
int n;

int rec(string s)
{
	string t;
	int i = 0;
	while (s[i] != '.' && s[i] != ':')
		i++;
	nodes.pb(s.substr(0, i));
	if (s[i] == '.')
		return nodes.size() - 1;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
}
