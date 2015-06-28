
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e3 + 2)
#define inf (int)(1e9 + 7)
#define pb push_back
#define f first
#define s second

int n, t[4 * maxn];
int a[maxn];

void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = a[tr];
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v + v, tl, tm);
    build(v + v + 1, tm + 1, tr);
    t[v] = min(t[v + v], t[v + v + 1]);
}

int get(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return inf;
    if (l == tl && r == tr)
    {
        return t[v];
    }
    int tm = (tl + tr) >> 1;
    return min(get(v + v, tl, tm, l, min(tm, r)), get(v + v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(int v, int tl, int tr, int pos, int x)
{
    if (tl == tr)
    {
        t[v] = x;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm)
    {
        update(v + v, tl, tm, pos, x);
    }
    else
    {
        update(v + v + 1, tm + 1, tr, pos, x);
    }
    t[v] = min(t[v + v], t[v + v + 1]);
}

int main()
{
    freopen("stupid_rmq.in", "r", stdin);
    freopen("stupid_rmq.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    build(1, 0, n - 1);
    int m;
    scanf("%d", &m);
    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l--, r--;
        printf("%d\n", get(1, 0, n - 1, l, r));
    }
}
