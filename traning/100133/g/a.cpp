
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const sz = 'z' - 'a' + 1;
int const maxn = int(1e6 + 12);
int const maxb = int(2e6 + 12);
int const inf = int(1e9 + 7);
ll const linf = ll(1e18 + 12);
double const eps = 1e-7;
double const pi = acos(-1);
#define mp make_pair
#define pb push_back
#define fn "dictionary"
#define F first
#define S second

struct vertex
{
	int next[sz];
	int suff, newsuff;
	int id;
	bool end;
	vertex()
	{
		for (int i = 0; i < sz; i++)
			next[i] = 0;
		suff = 0;
		newsuff = 0;
		id = 0;
		end = 0;
	}
};

vector <vertex> T(1, vertex());

void add(string s, int id)
{
	int v = 0;
	for (int i = 0; i < int(s.size()); i++)
	{
		int c = s[i] - 'a';
		if (!T[v].next[c])
		{
			T[v].next[c] = int(T.size());
			T.pb(vertex());
		}
		v = T[v].next[c];
	}
	T[v].end = 1;
	T[v].id = id;
}

void bfs()
{
	queue <int> qu;
	qu.push(0);
	while (!qu.empty())
	{
		int v = qu.front();
		qu.pop();
		for (int c = 0; c < sz; c++)
		{
			int to = T[v].next[c], u = T[v].suff;
			if (!to)
			{
				T[v].next[c] = T[u].next[c];
				continue;
			}
			qu.push(to);
			if (v == 0)
				T[to].suff = 0;
			else
				T[to].suff = T[u].next[c];
			u = T[to].suff;
			T[to].newsuff = T[u].end ? u : T[u].newsuff;
			//printf("%d %c -> %d: %d %d\n", v, c + 'a', to, T[to].suff, T[to].newsuff);
		}
	}
}

string t;
char _S[maxn];
int n;
vector <int> C;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%s", _S);
	t = string(_S);
	scanf("%d", &n);
	C.assign(n, 0);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", _S);
		add(string(_S), i);
	}
	bfs();
	
	int v = 0;
	for (int i = 0; i < int(t.size()); i++)
	{
		v = T[v].next[t[i] - 'a'];
		int u = v;
		while (u > 0)
		{
			if (T[u].end)
				C[T[u].id]++;
			u = T[u].newsuff;
		}
		//printf("%d ", v);
	}
	//puts("");
	for (int i = 0; i < n; i++)
		puts(C[i] ? "Yes" : "No");
}
