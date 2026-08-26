class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0;
        int sumEven = 0;
        
        for(int i = 1; i<= 2*n; i++){
            if(i % 2 == 0){
                sumEven += i;
            }else{
                sumOdd += i;
            }
        }
        int temp = 0;
        if(sumEven > sumOdd){
            temp = sumEven;
        }else{
            temp = sumOdd;
        }
        int ans = 0;
        for(int i = 1; i<temp; i++){
            if(sumEven % i == 0 && sumOdd % i == 0){
                ans = i;
            }
        }
        return ans;
    }
};