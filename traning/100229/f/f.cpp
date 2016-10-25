
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn 2015
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "bacon"
#define LOCAL
#define F first
#define S second

struct vertex
{
	map <char, int> next;
};

vector <vertex> T;

int N;
char s[maxn];

void add(int j)
{
	int v = 0;
	for (int i = j; i < N; i++)
	{
		int c = s[i] - 32;
		if (T[v].next.find(c) == T[v].next.end())
		{
			T[v].next[c] = int(T.size());
			T.pb(vertex());
		}
		v = T[v].next[c];
	}
}

int main()
{
	freopen(fn".in", "r", stdin);
	freopen(fn".out", "w", stdout);
	T.pb(vertex());
	scanf("%s", s);
	N = strlen(s);
	for (int i = 0; i < N; i++)
		add(i);
	printf("%d", int(T.size()) - 1);
}