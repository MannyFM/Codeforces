
#include <bits/stdc++.h>

using namespace std;

#define inf (int)(1e9 + 7)

struct item
{
	int prior;
	int value;
	int sz;
	int mn;
	item * l, * r;
	item () {};
	item (int value, int prior) : value(value), prior(prior), l(NULL), r(NULL), mn(value);
};

typedef item * pitem;

int cnt(pitem t)
{
	return t ? t -> sz : 0;
}

int min(pitem t)
{
	return t ? t -> mn : inf;
}

void upd(pitem & t)
{
	if (t)
	{
		t -> sz = 1 + cnt(t -> l) + cnt(t -> r);
		t -> mn = min(t -> mn, min(min(t -> l), min(t -> r)));
	}
}

void split(pitem t, pitem &l, pitem & r, int key, int add = 0)
{
	if (!t)
		return void(l = r = NULL);
	int cur_key = add + cnt(t -> r);
	if (key <= cur_key)
		split(t -> l, l, t -> l, key, add), r = t;
	else
		split(t -> r, t -> r, r, key, add + 1 + cnt(t -> l)), l = t;
	upd(t);
}

void merge(pitem & t, pitem l, pitem r)
{
	if (!l || !r)
		t = l ? l : r;
	else if (l -> prior > r -> prior)
		merge(l -> r, l -> r, r), t = l;
	else
		merge(r -> l, l, r -> l), t = r;
	upd(t);
}

void insert(pitem & t, pitem it, int pos)
{
	if (!t)
		return void(t = it);
	pitem t1, t2;
	split(t, t1, t2, pos);
	merge(t1, t1, it);
	merge(t, t1, t2);
	upd(t);
}

int get_min(pitem t, int l)
{
	pitem t1, t2;
	split(t, t1, t2, l);
	cout << t2 ? t2 -> value : -1 << " ";
	int ans = t2 -> value;
}