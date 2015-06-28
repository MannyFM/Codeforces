
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 12)
#define inf (int)(1e9 + 7)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define li long long
#define pli pair <int, int>

int n, m;
pli t[4 * maxn];
int a[maxn];

pli com(pli a, pli b)
{
    pli res;
    res.f = min(a.f, b.f);
    res.s = max(a.s, b.s);
    return res;
}

void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = mp(a[tl], a[tl]);
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v + v, tl, tm);
    build(v + v + 1, tm + 1, tr);
    t[v] = com(t[v + v], t[v + v + 1]);
}

int cnt = 0;

pli get(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return mp(inf, -inf);
    if (l == tl && r == tr)
    {
        return t[v];
    }
    int tm = (tl + tr) >> 1;
    pli f = (get(v + v, tl, tm, l, min(tm, r)));
    pli s = (get(v + v + 1, tm + 1, tr, max(l, tm + 1), r));
    pli ans = com(f, s);
    /*
    printf("%d %d %d %d %d\n", v, tl, tr, l, r);
    printf("%d %d  %d %d  %d %d\n\n", f.f, f.s, s.f, s.s, ans.f, ans.s);*/
    return ans;
}

void update(int v, int tl, int tr, int pos, int x)
{
    //printf("%d %d %d %d %d\n", v, tl, tr, pos, x);
    if (tl == tr)
    {
        t[v] = mp(x, x);
        return;
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
    t[v] = com(t[v + v], t[v + v + 1]);
}

int main()
{
    freopen("rvq.in", "r", stdin);
    freopen("rvq.out", "w", stdout);
    n = maxn - 3;

    for(int i = 1; i <= n; i++)
        a[i - 1] = ((li)(i) * i) % 12345 + ((((li)i * i) % 23456) * i) % 23456;
    /*
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    puts("");
    */
    build(1, 0, n - 1);
    /*
    puts("\n");
    //TEST
    scanf("%d", &m);
    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l--, r--;
        pli ans = get(1, 0, n - 1, l, r);
        printf("%d %d\n", a[l], a[r]);
        printf("%d %d\n", ans.f, ans.s);
    }
    return 0;
    */
    scanf("%d", &m);
    while (m--)
    {
        //printf("%d:\n", m);
        int x, y;
        scanf("%d%d", &x, &y);
        if (x > 0)
        {
            x--, y--;
           //printf("%d %d\n", x, y);
            pli ans = get(1, 0, n - 1, x, y);
            //printf("%d %d %d %d\n", x, y, ans.f, ans.s);
            printf("%d\n", ans.s - ans.f);
        }
        if (x < 0)
        {
            x = abs(x);
            x--;
            //printf("%d %d:\n", x, y);
            update(1, 0, n - 1, x, y);
        }
    }
}
