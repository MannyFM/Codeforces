
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e3 + 12)
#define inf (int)(1e9 + 7)
#define pb push_back

struct edge
{
    int a, b, c;
};

int n, m;
vector <edge> e;

int main()
{
    freopen("maze.in", "r", stdin);
    //freopen("maze.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edge d;
        d.a = a, d.b = b, d.c = -c;
        e.pb(d);
    }

    vector <int> d(n + 1, inf);
    d[1] = 0;
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
                    //printf("%d:%d %d:%d %d\n", e[j].b, d[e[j].b], e[j].a, d[e[j].a], e[j].c);
                    d[e[j].b] = max(-inf, d[e[j].a] + e[j].c);
                    x = e[j].b;
                }
            }
        }
    }
    /*
    for(int i = 1; i <= n; i++)
    {
        printf("%d ", d[i]);
    }
    puts("");
    */
    if (d[n] == inf)
    {
        puts(":(");
        return 0;
    }

    if (x != -1)
    {
        puts(":)");
        return 0;
    }
    if (d[n] == inf)
    {
        puts(":(");
        return 0;
    }
    cout << -d[n];
}
