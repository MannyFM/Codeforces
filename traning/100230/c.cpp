
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define maxn (int)(2e4 + 10)
#define inf (ll)(1e18 + 7)
#define pb push_back

struct edge
{
    int a, b;
    ll c;
};

int n, m, s;
vector <edge> e;
bool neg[maxn];

int main()
{
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &s);
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edge d;
        d.a = a, d.b = b, d.c = c;
        e.pb(d);
    }
    vector <ll> d(n + 2, inf);
    vector <int> pr(n + 2, -1);
    d[s] = 0ll;
    int x;
    for(int i = 0; i < n; i++)
    {
        x = -1;
        for(int j = 0; j < m; j++)
        {
            if (d[e[j].a] < inf)
            {
                if (d[e[j].b] > d[e[j].a] + e[j].c)
                {
                    d[e[j].b] = max(-inf, d[e[j].a] + e[j].c);
                    pr[e[j].b] = e[j].a;
                    x = e[j].b;
                }
            }
        }
    }
    if (x != -1)
    {
        int y = x;
        for(int i = 0; i < n; i++)
            y = pr[y];
        vector <int> path;
		for (int cur = y; ; cur = pr[cur]) {
			path.push_back(cur);
			if (cur == y && path.size() > 1)  break;
		}
        for(int i = 0; i < (int)(path.size()); i++)
            neg[path[i]] = 1;
    }
    for(int i = 1 i <= n; i++)
    {

    }
    for(int i = 1; i <= n; i++)
    {
        if (d[i] == inf)
        {
            printf("*\n");
            continue;
        }
        if (neg[i])
            printf("-\n");
        else
            cout << d[i] << '\n';
    }
}
