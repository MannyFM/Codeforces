
#include <bits/stdc++.h>

using namespace std;


#define maxn (int)(1e9 + 7)
#define inf (int)(1e9 + 7)
#define pb push_back
#define null NULL
#define mp make_pair

struct treap
{
	int y;
	int cost;
	treap  * l, * r;
	int size;
	treap() {}
	treap(int y, int cost): y(y), cost(cost), l(null), r(null) {}
};

typedef treap * ptreap;

ptreap root;

int size(ptreap v)
{
	return (v == null) ? 0 : v -> size;
}

void recalc(ptreap v)
{
	if (v)
	v -> size = size(v -> l) + size(v -> r) + 1;
}

void split (ptreap v, ptreap & l, ptreap & r, int x, int add = 0)
{
	if (!v)
	{
		l = r = null;
		return;
	}
	int cut_key = add + size(v -> l);
	if (x <= cut_key)
		split(v -> l, l, v -> l, x, add), r = v;
	else
		split(v -> r, v -> r, r, x, add + 1 + size(v ->l)), l = v;
	recalc(v);
}

void merge(ptreap & t, ptreap l, ptreap r)
{
	if (!l || !r)
		t = l ? l : r;
	else
	if (l -> y > r -> y)
		merge (l -> r, l -> r, r), t = l;
	else
		merge (r -> l, l, r -> l), t = r;
	recalc(t);
}

void shift(ptreap & t, int l, int r)
{
	ptreap t1, t2, t3;
	split(t, t1, t2, l);
	split(t2, t2, t3, r - l + 1);
	merge(t, t2, t1);
	merge(t, t, t3);
	recalc(t);
}

void insert(ptreap & t, ptreap in, int pos)
{
//	cerr << pos << " ";
	ptreap t1, t2;
	split(t, t1, t2, pos);
	merge(t1, t1, in);
	merge(t, t1, t2);
	recalc(t);
}

void out(ptreap in)
{
	if (!in)
		return;
	out(in -> l);
	cout << in -> cost << " ";
	out(in -> r);
}

int main()
{
//    freopen("input.txt", "r", stdin);

	freopen("movetofront.in", "r", stdin);
	freopen("movetofront.out", "w", stdout);

	int n, m, l, r;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		ptreap ni = new treap(rand() << (rand() | 16), i);
		insert(root, ni, i - 1);
	}
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> l >> r;
		shift(root, l - 1, r - 1);
	}
	out(root);
}
