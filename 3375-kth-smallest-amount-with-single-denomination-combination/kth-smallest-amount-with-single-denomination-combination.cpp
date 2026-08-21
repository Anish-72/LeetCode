using ll = long long;
class Solution {
public:
    ll helperFn(vector<int>& coins, ll x){
        int m = coins.size();
        int allOnes = (1 << m) - 1;
        ll cnt = 0;
        for(int mask = 1; mask<= allOnes; mask++){
            ll setBitsLcm = 1;
            for(int j = 0; j < m; j++){
                if(mask & (1 << j)){
                    setBitsLcm = lcm(setBitsLcm, coins[j]);
                }
            } 
            if(__builtin_popcount(mask) & 1){
                cnt += x / setBitsLcm;
            }else{
                cnt -= x / setBitsLcm;
            }
        }
        return cnt;
    }
    ll findKthSmallest(vector<int>& coins, int k) {
        ll l = 0, r = 25 * 2 * 1e9 + 25, ans = 0;
        while(l <= r){
            ll midx = (l + r)/2;
            ll cnt = helperFn(coins, midx);
            if(cnt < k){
                l = midx + 1;
            } else{
                ans = midx;
                r = midx - 1;
            }
           
        }
         return ans;
    }
};