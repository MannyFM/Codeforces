
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e5 + 12)
#define inf int(1e9 + 7)
#define mod int(1e9 + 9)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define LOCAL

int n, X[maxn], Y[maxn];
set <pii> all;
map <pii, int> id;
set <int> up[maxn], down[maxn];
set <pair<int, pii>> can;

bool is(int x, int y)
{
	return all.find(mp(x, y)) != all.end();
}

int Can(int x, int y)
{
	if (!is(x, y))
		return -1;
	int ID = id[mp(x, y)];
	for (auto v : up[ID])
		if (down[v].size() == 1)
			return 0;
	return 1;
}

bool f(int x, int y)
{
	int c = Can(x, y);
	if (c == 1)
		can.insert(mp(id[mp(x, y)], mp(x, y)));
	if (c == 0)
		can.erase(mp(id[mp(x, y)], mp(x, y)));
	return c == 0;
}

void go(int ID, int x, int y)
{
	for (int dx = -1; dx < 2; dx++)
		if (is(dx + x, y + 1))
			f(dx + x, y + 1);
	for (int dx = -1; dx < 2; dx++)
		if (is(dx + x, y - 1))
			f(dx + x, y - 1);
}

void output(int ID)
{
	printf("me %d\nup:\n", ID);
	for (auto i : up[ID])
		printf("%d ", i);
	puts("\ndown:");
	for (auto i : down[ID])
		printf("%d ", i);
	puts("\n");
}

int main()
{
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", X + i, Y + i);
		all.insert(mp(X[i], Y[i]));
		id[mp(X[i], Y[i])] = i;
	}
	for (int i = 0; i < n; i++)
	{
		for (int dx = -1; dx <= 1; dx++)
			if (is(dx + X[i], Y[i] + 1))
				up[i].insert(id[mp(dx + X[i], Y[i] + 1)]);
		for (int dx = -1; dx <= 1; dx++)
			if (is(dx + X[i], Y[i] - 1))
				down[i].insert(id[mp(dx + X[i], Y[i] - 1)]);
	}
	for (int i = 0; i < n; i++)
		f(X[i], Y[i]);
	/*
	for (auto v : can)
		printf("%d : (%d %d)\n", v.F, v.S.F, v.S.S);
	*/
	bool step = 0;
	vector <int> ans;
	while (!can.empty())
	{
		auto it = can.begin();
		if (!step)
		{
			it = can.end();
			it--;
		}
		while (f(it -> S.F, it -> S.S))
		{
			it = can.begin();
			if (!step)
			{
				it = can.end();
				it--;
			}
		}
		step ^= 1;
		int ID = it -> F;
		int x = it -> S.F;
		int y = it -> S.S;
		can.erase(it);
		ans.pb(ID);
		all.erase(mp(x, y));
		/*
		if (ID == 9)
		{
			printf("%d:\n", ID);
			output(ID);
			for (auto i : up[ID])
				output(i);
			for (auto i : down[ID])
				output(i);
		}
		*/
		for (auto i : up[ID])
			down[i].erase(ID);
		for (auto i : down[ID])
			up[i].erase(ID);
		/*
		if (ID == 9)
		{
			output(ID);
			for (auto i : up[ID])
				output(i);
			for (auto i : down[ID])
				output(i);
		}
		*/
		go(ID, x, y);
	}
	/*
	for (auto i : ans)
		printf("%d ", i);
	puts("");
	*/
	reverse(ans.begin(), ans.end());
	ll res = 0ll, p = 1ll;
	for (auto i : ans)
	{
		res = (res + p * i) % mod;
		p = (p * n) % mod;
	}
	printf("%I64d", res);
}
