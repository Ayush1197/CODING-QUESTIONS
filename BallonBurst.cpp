class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int siz=nums.size();
        if(siz==0) return 0;
        int dp[siz][siz]={0};
        for(int i=0;i<siz;i++)
      {    
          for(int j=0;j<siz;j++)
              dp[i][j]=0;
      }   
        for(int len=1;len<=siz;len++)
        {
            for(int i=0;i<=(siz-len);i++)
            {
                int j= i+len-1;
                for(int k=i;k<=j;k++)
                {
                    int leftvalue=1;
                     int rightvalue=1;
                if(i!=0)
                    leftvalue=nums[i-1];
                 if(j!=(siz-1))
                    rightvalue=nums[j+1];
                
                int before=0;
                    int after=0;
                if(i!=k)
                    before=dp[i][k-1];
                if(j!=k)
                    after=dp[k+1][j];
                dp[i][j]=max(((leftvalue*nums[k]*rightvalue)+before+after),dp[i][j]);
                }
            }
       
        } 
     
    for(int i=0;i<siz;i++)
      {    
          for(int j=0;j<siz;j++)
              printf("%d ",dp[i][j]);
          printf("\n");
      }

     return dp[0][siz-1];
    }
};
