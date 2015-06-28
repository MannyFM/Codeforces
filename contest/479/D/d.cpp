
#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define maxn (int)(1e5+123)
#define ch(chs) (0 <= chs && chs <= l)

int n, x, y, l;
int a[maxn];
set <int> d;

int main()
{
    cin >> n >> l >> x >> y;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
    {
        d.insert(a[i]);
    }
    int fx = 0, fy = 0;
    for(int i = 1; i < n; i++)
    {
        if (a[i] >= x && (d.find(a[i] - x) != d.end()))
        {
            fx = 1;
        }
        if (a[i] >= y && (d.find(a[i] - y) != d.end()))
        {
            fy = 1;
        }
        if (fx && fy)
            break;
    }
    //cout << fx << " " << fy << '\n';
    if (fx && fy)
    {
        cout << 0;
        return 0;
    }
    if (fx xor fy)
    {
        printf("1\n%d", (fx ? a[n - 1] + y - l : a[n - 1] + x - l));
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        int k1 = a[i] - x + y;
        if (0 <= k1 && k1 <= l && (d.find(k1) != d.end()) && ch(k1 - y))
        {
            printf("1\n%d", k1 - y);
            return 0;
        }
        int k2 = a[i] - x - y;
        if (0 <= k2 && k2 <= l && (d.find(k2) != d.end()) && ch(k2 + y))
        {
            printf("1\n%d", k2 + y);
            return 0;
        }
        int k3 = a[i] + x + y;
        if (0 <= k3 && k3 <= l && (d.find(k3) != d.end()) && ch(k3 - y))
        {
            printf("1\n%d", k3 - y);
            return 0;
        }
        int k4 = a[i] + x - y;
        if (0 <= k4 && k4 <= l && (d.find(k4) != d.end()) && ch(k4 + y))
        {
            printf("1\n%d", k4 + y);
            return 0;
        }
    }
    printf("2\n%d %d", a[n - 1] - x, a[n - 1] - y);

}
