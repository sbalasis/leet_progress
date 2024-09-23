class Solution {
public:
    vector<int> countBitsMine(int n) {
        vector<int> re = vector(n+1,0);
        int i = 0;
        for(auto& v:re) {
            int tmp = i;
            while (tmp > 0) {
                v += tmp & 1;
                tmp>>=1;
            }
            i++;
        }
        return re;
    }
 
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        for(int i=1;i<=n;i++){
            if(i%2==0){
                ans[i]=ans[i/2];
            }else{
                ans[i]=ans[i/2]+1;
            }
        }return ans;
    }
};