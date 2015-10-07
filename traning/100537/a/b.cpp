#include <bits/stdc++.h>

using namespace std;

//constants
const int MAXN=(int)(1e3+1e1);
const double PI=acos(-1.0);

//defines
#define ll long long
#define F first
#define S second
#define fr freopen("capital.in","r",stdin);
#define fw freopen("capital.out","w",stdout);
#define mp make_pair
#define pb push_back
#define eof (-1)
#define forr(xx,yy,zz) for(int zz=xx;zz<=yy;zz++)
#define forl(xx,yy,zz) for(int zz=xx;zz>=yy;zz--)
#define sqr(x) ((x)*(x))
#define sz(x) (int)x.size()
#define len(s) (int)(s.length())
#define all(a) a.begin(),a.end()
//=

ll n,m,ans,q;
string s;

int main()
{
    fr fw
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    forr(1,m,i)
        s += '0';
    forr(0,m-1,i)
    {                                     
        while (s[i] < '9' && ans < n)
        {
            s[i] = s[i] + 1;
            ans++;
        }
        //cout<<char(s[i]-'0'+1+'0')<<' ';
    }
    cout<<s;
    return 0;
}