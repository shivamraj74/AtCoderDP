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
 
 
 
 
int longestCommonSubsequence(string s1, string s2, vector<vector<int>>& dp)
{
    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
 
            dp[i][j] = max({dp[i][j], dp[i][j - 1], dp[i - 1][j]});
        }
    }
    return dp[s1.size()][s2.size()];
}
 
 
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
   
    int t = 1;
    //cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
 
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        int count = longestCommonSubsequence(s1, s2, dp);  
 
        string s = "";
        int i = s1.size(), j = s2.size();
        while (i > 0 && j > 0)
        {
            if (dp[i - 1][j - 1] + 1 == dp[i][j] && dp[i - 1][j] + 1 == dp[i][j] && dp[i][j - 1] + 1 == dp[i][j])
            {
                i--;
                j--;
                s = s1[i] + s; 
            }
            else if (dp[i][j - 1] > dp[i - 1][j])
                j--;
            else
                i--;
        }
        cout << s << endl;
    }
    return 0;
 
}
