
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n, p = 0;
    scanf("%d", &n);
    n--;
    while (n > 4)
    {
        n -= 5;
        n /= 2;
    }
    string s[] = {"Sheldon" , "Leonard" , "Penny" , "Rajesh" , "Howard"};

    cout << s[n];
}
