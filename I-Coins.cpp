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
        int n;
        cin >> n;
 
        vector<double> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
 
        vector<double> dp(n + 1);  
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j >= 0; j--) { 
                dp[j] = (j == 0 ? 0 : dp[j - 1] * a[i]) + dp[j] * (1 - a[i]);
            }
        }
 
        double answer = 0;
        for (int heads = ceil(n / 2.0); heads <= n; heads++) {
            answer += dp[heads];
        }
 
        cout << fixed << setprecision(9) << answer;
    }
    return 0;
 
}
