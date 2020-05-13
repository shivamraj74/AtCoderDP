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
        int n, W;
        cin >> n >> W;
        vector<int> weight(n), value(n);
        for (int i = 0; i < n; ++i) {
            cin >> weight[i] >> value[i];
        }
 
        const int MAX_VALUE = 100 * 1000 + 1, INF = 1e15 + 5;
        vector<int> dp(MAX_VALUE, INF);
        dp[0] = 0;
 
        int answer = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = MAX_VALUE - 1; j >= value[i]; j--)
            {
                if (dp[j - value[i]] + weight[i] <= W)
                {
                    dp[j] = min(dp[j], dp[j - value[i]] + weight[i]);
                    answer = max(answer, j);
                }
            }
        }
        cout << answer << endl;
    }
    return 0;
 
}
