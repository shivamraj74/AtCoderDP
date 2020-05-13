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
        int n, k; cin >> n >> k;
        int h[n];
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        dp[1] = abs(h[1] - h[0]);
        for (int i = 2; i < n; i++) {
            for (int j = i - 1, jump = 0; j  >= 0 && jump < k; j--, jump++) {
                dp[i] = min(dp[i], dp[j] + abs(h[j] - h[i]));
            }
        }
        cout << dp[n - 1];
 
    }
    return 0;
 
}
