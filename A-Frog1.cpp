//Radhe Radhe
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
const int N = 10001;
 
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    
    int t = 1;
    //cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 1], dp[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + abs (a[i] - a[i - 1]);
            if (i > 2) {
                dp[i] = min(dp[i], dp[i - 2] + abs(a[i] - a[i - 2]));
            }
        }
        cout << dp[n] << endl;
 
 
    }
    return 0;
 
}
