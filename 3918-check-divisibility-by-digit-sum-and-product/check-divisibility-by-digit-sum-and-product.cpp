class Solution {
private:
    int isSum(int n){
        int temp = n;
        int sum = 0;
        while(temp > 0){
            sum+= temp % 10;
            temp = temp / 10;
        }
        return sum;
    }
    int isProd(int n){
        int temp = n;
        int prod = 1;
        while(temp > 0){

            prod *= temp % 10;
            temp = temp / 10;
        }
       return prod;
    }
public:
    bool checkDivisibility(int n) {
        if(n<10){
            return false;
        }
        int tSum = isSum(n) + isProd(n);

        if(n % tSum== 0){
            return true;
        }
        return false;


    }
};