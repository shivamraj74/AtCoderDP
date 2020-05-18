// Radhe Radhe
#include<bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include<boost/math/common_factor.hpp>
#include <ext/numeric>
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define array(a,n) int a[n]; for(int i=0;i<n;i++) cin>>a[i];
#define loop(i,a,b,x) for(int i=a;i<b;i+=x)
const int MOD = 1000000007;
//const int N = 10001;
const int N = 1e5 + 10;
//const int N = (2 * (1e5)) + 2;
 
 
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
   
    int t = 1;
    //cin >> t;
    while (t--) {
        int h, w;
        cin >> h >> w;
        vector< string > a(h);
        vector< vector<int> > dp(h + 1, vector<int> (w + 1, 0));
        for (int i = 0; i < h; i++)
            cin >> a[i];
 
        dp[1][1] = 1;
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                if (a[i - 1][j - 1] == '.')
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + dp[i][j - 1]) % MOD;
                else
                    dp[i][j] = 0; 
            }
        }
 
        cout << dp[h][w] << endl;
    }
    return 0;
 
}
