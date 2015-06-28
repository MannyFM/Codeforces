
#include <bits/stdc++.h>

using namespace std;

int n, k, a[123];
int m, s;
vector < pair <int, int> > ans;

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    while(k--)
    {
        int mn = 0, mx = 0;
        for(int i = 0; i < n; i++)
        {
            if (a[mn] > a[i])
                mn = i;
            if (a[mx] < a[i])
                mx = i;
        }
        if (a[mn] + 1 >=a[mx])
            break;
        a[mn]++, a[mx]--;
        ans.push_back(make_pair(mx + 1, mn + 1));
    }
    int mn = 0, mx = 0;
    for(int i = 0; i < n; i++)
    {
        if (a[mn] > a[i])
            mn = i;
        if (a[mx] < a[i])
            mx = i;
    }
    cout << a[mx] - a[mn] << " " << ans.size() << '\n';
    for(int i = 0; i < (int)(ans.size()); i++)
        cout << ans[i].first << " " << ans[i].second << '\n';
}
