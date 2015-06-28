
#include <bits/stdc++.h>

using namespace std;

int cnt[30];
string a, b, out;

int main()
{
    cin >> a >> b >> out;
    for (int i = 0; i < (int)(a.size()); i++)
        cnt[(int)(a[i] - 'A')]++;
    for (int i = 0; i < (int)(b.size()); i++)
        cnt[(int)(b[i] - 'A')]++;
    for (int i = 0; i < (int)(out.size()); i++)
    {
        int j = (int)(out[i] - 'A');
        cnt[j]--;
    }
    /*
    for (int i = 0; i < 30; i++)
        printf("%d ", cnt[i]);
    */
    for(int i = 0; i < 30; i++)
        if (cnt[i] != 0)
    {
        puts("NO");
        return 0;
    }
    puts("YES");
}
