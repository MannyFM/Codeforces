
#include <bits/stdc++.h>

using namespace std;

string a, h = "hello";
int j;

int main()
{
    cin >> a;
    for (int i = 0; i < (int)(a.size()); i++)
    {
        if (a[i] == h[j])
            j++;
    }
    puts(j == (int)(h.size()) ? "YES" : "NO");
}
