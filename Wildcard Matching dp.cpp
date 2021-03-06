// leetcode wild card matching in two strings
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j] = 0;
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i == 0 and j == 0){ // if length of both the strings is 0
                    dp[i][j] = 1;
                }
                else if(i == 0){ // if j-1 index of string p contains *
                    dp[i][j] = (dp[i][j-1] and p[j-1] == '*');
                }
                else if(j == 0){ // if p is empty and s is not empty
                    dp[i][j] = 0;
                }
                else if(p[j-1] == '*'){ // p[1: j-1] can match with any one in s[1: n]
                    dp[i][j] = (dp[i-1][j] or dp[i][j-1]);
                }
                else if(p[j-1] == '?' or s[i-1] == p[j-1]){ // if its a match or ?
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[n][m];
    }
};
