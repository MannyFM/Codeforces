
#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define maxn (int)(1e5+123)

int n;
pair <int, int> a[maxn];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].f >> a[i].s;
    sort(a, a + n);
    /*
    for(int i = 0; i < n; i++)
    {
        cout << a[i].f << " " << a[i].s << '\n';
    }
    */
    int ans = a[0].s;
    for(int i = 1; i < n; i++)
    {
        if (a[i].s >= ans)
            ans = a[i].s;
        else
            ans = a[i].f;
    }
    cout << ans;
}
