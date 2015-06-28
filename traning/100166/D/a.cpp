
#include <bits/stdc++.h>

using namespace std;

#define inf int(1e9 + 9)
#define maxn int(2e3 + 12)
#define maxm int(1e5 + 12)
#define pb push_back
#define fn "path"
#define ll long long
#define linf (ll)(2e18 + 9)

struct edge
{
    int a, b;
    ll c;
    edge(int a, int b, ll c) : a(a), b(b), c(c) {};
};

int n, m, s, x;
vector <edge> e;
vector <int> g[maxn];
vector <ll> d;
vector <char> us;

void dfs(int v)
{
    us[v] = 1;
    for (int i = 0; i < int(g[v].size()); i++)
    {
        int to = g[v][i];
        if (!us[to])
            dfs(to);
    }
}

void ford()
{
    d.assign(n + 1, linf);
    d[s] = 0ll;
    for (int i = 0; i < n; i++)
    {
        x = -1;
        for (int j = 0; j < m; j++)
        {
            if (d[e[j].a] < linf)
            {
                if (d[e[j].b] > d[e[j].a] + e[j].c)
                {
                    d[e[j].b] = d[e[j].a] + e[j].c;
                    x = e[j].b;
                }
            }
        }
    }
}

int main()
{
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        scanf("%d%d%I64d", &a, &b, &c);
        edge it = edge(a, b, c);
        e.pb(it);
        g[a].pb(b);
    }
    us.assign(n + 1, 0);
    //cerr << "ford ";
    ford();
    if (x != -1)
    {
        //cerr << "dfs ";
        dfs(x);
    }
    //cerr << "ans";
    /*
    for (int i = 1; i <= n; i++)
        printf("%I64d ", d[i]);
    puts("");
    for (int i = 1; i <= n; i++)
        printf("%d ", (int)us[i]);
    puts("");
    */
    for (int i = 1; i <= n; i++)
    {
        if (!us[i])
        {
            if (d[i] == linf)
            {
                puts("*");
            }
            else
            {
                printf("%I64d\n", d[i]);
            }
        }
        else
        {
            puts(d[i] == linf ? "*" : "-");
        }
    }
}