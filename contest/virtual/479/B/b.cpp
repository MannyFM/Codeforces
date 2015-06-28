
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(123)

int n, a[maxn], k;
int s, m;
vector < pair <int, int> > ans;

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    while (k--)
    {
        int Min = 0, Max = 0;
        for(int i = 0; i < n; i++)
        {
            if (a[Min] > a[i])
                Min = i;
            if (a[Max] < a[i])
                Max = i;
        }
        if (a[Min] + 1 >= a[Max])
            break;
        a[Min] ++, a[Max]--;
        m++;
        ans.push_back(make_pair(Max + 1, Min + 1));
    }
    int Min = 0, Max = 0;
    for(int i = 0; i < n; i++)
    {
        if (a[Min] > a[i])
            Min = i;
        if (a[Max] < a[i])
            Max = i;
    }
    cout << a[Max] - a[Min] << " " << m << '\n';
    for(int i = 0; i < m; i++)
        cout << ans[i].first << " " << ans[i].second << '\n';
}
