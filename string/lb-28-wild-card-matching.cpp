class Solution{
    public:
    bool match(string wild, string pattern){
        int m = wild.size();
        int n = pattern.size();
        int dp[n+1][m+1]={0};
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 and j==0) dp[i][j]=1;
                else if(i==0) dp[i][j]=(wild[j-1]=='*') ? dp[i][j-1] : 0;
                else if(j==0) dp[i][j]=0;
                else{
                    if(wild[j-1]=='*'){
                        bool ans = false;
                        int k=i;
                        while(k>=0){
                            ans = ans or dp[k][j-1];
                            k--;
                        }
                        dp[i][j] = ans;
                        
                    }else if(wild[j-1]=='?'){
                        dp[i][j] = dp[i-1][j-1]; // diagonal
                    }else{
                        dp[i][j] = (wild[j-1]==pattern[i-1])?dp[i-1][j-1]:0;
                    }
                }
            }
        }
        return dp[n][m];
    }
};