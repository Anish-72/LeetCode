class Solution {
public:
    int kthDigit(long long k) {
        if (k <= 9){
            return k;
        } 
        k -= 9;
        long long d = 2;
        long long start_b = 1;
        
        while (true) {
            long long cnt = 9 * start_b;
            long long size = 10 * d;
            long long total_digits = cnt * size;
            
            if (k <= total_digits) {
                break;
            }
            k -= total_digits;
            start_b *= 10;
            d++;
        }
        
        k -= 1;
        long long block_offset = k / (10 * d);
        long long b = start_b + block_offset;
        long long rem = k % (10 * d);
        long long idx = rem / d;
        long long dig = rem % d;
        
        long long num = 0;
        if (b % 2 == 0) {
            num = 10 * b + idx;
        } else {
            num = 10 * b + (9 - idx);
        }
        
        std::string s = std::to_string(num);
        return s[dig] - '0';
    }
};