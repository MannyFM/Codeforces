
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(2e5 + 7)
#define inf (int)(1e9 + 7)
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef stack < pair <int, int> > sta;

sta st1, st2;
int n, a[maxn], c, t, ans = 0;

void push(int x)
{
	int mn = st1.empty() ? x : max(x, st1.top().s);
	st1.push(mp(x, mn));
}

int pop()
{
	if (st2.empty())
	{
		while (!st1.empty())
		{
			int v = st1.top().f;
			st1.pop();
			int mn = st2.empty() ? v : max(v, st2.top().s);
			st2.push(mp(v, mn));
		}
	}
	int res = st2.top().f;
	st2.pop();
	return res;
}

int get()
{
	int ans = -inf;
	if (st1.empty() || st2.empty())
		ans = st1.empty() ? (st2.empty() ? -inf : st2.top().s) : st1.top().s;
	else
		ans = max(st1.top().s, st2.top().s);
	return ans;
}

int main()
{
	cin >> n >> t >> c;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < c; i++)
	{
		push(a[i]);
	}
	ans += (get() <= t);
	for (int i = c; i < n; i++)
	{
		pop();
		push(a[i]);
//		printf("%d\n", get());
		ans += (get() <= t);
	}
	printf("%d", ans);
}