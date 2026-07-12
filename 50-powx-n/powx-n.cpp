class Solution {
public:
    double Pow(double x, long long N) {
       if (N == 0) {
            return 1.0;
        }

        // 2. Fast Exponentiation: We calculate the half-power just once
        double half = Pow(x, N / 2);

        // 3. If N is even (Example: x^4 = x^2 * x^2)
        if (N % 2 == 0) {
            return half * half;
        } 
        // 4. If N is odd (Example: x^5 = x^2 * x^2 * x)
        else {
            return half * half * x;
        }
    }

    double myPow(double x, int n) {

        long long N = n;
        if(N<0){
            x = 1/x;
            N = -N;
        }

        return Pow(x, N);


    }
};