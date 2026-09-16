class Solution {
public:

    long long digits(long long x) {
        long long total = 0;
        long long start = 1;
        long long d = 1;

        while (start <= x) {
            long long end = min(x, start * 10 - 1);

            total += (end - start + 1) * d;

            start *= 10;
            d++;
        }

        return total;
    }

    int findNthDigit(int n) {

        long long start = 1;
        long long end = n;

        while (start < end) {

            long long mid = start + (end - start) / 2;

            if (digits(mid) >= n) {
                end = mid;
            }
            else {
                start = mid + 1;
            }
        }

        long long num = start;

        long long before = digits(num - 1);

        long long index = n - before - 1;

        string s = to_string(num);

        return s[index] - '0';
    }
};