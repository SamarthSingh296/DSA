class Solution {

public:
    static const int MAX = 200000000;
    bool isPrime(int n) {
        if (n < 2)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    bool palindrome(int n) {
        if (n < 0)
            return false;
        string s = to_string(n);
        string l = s;
        reverse(l.begin(), l.end());
        return (s == l);
    }
    int primePalindrome(int n) {
        if (n <= 2)
            return 2;
        if (n <= 3)
            return 3;
        if (n <= 5)
            return 5;
        if (n <= 7)
            return 7;
        if (n <= 11)
            return 11;

        for (int len = 1; len <= 5; len++) {
            int start = pow(10, len - 1);
            int end = pow(10, len);
            for (int i = start; i < end; i++) {
                string s = to_string(i);
                string l = s;
                reverse(l.begin(), l.end());
                int pal = stoi(s + l.substr(1));
                if (pal >= n && isPrime(pal))
                    return pal;
            }
        }
        return -1;

        // for(int i=n;i<MAX;i++){
        //     if(isPrime(i)&&palindrome(i))return i;
        // }
        // return -1;
    }
};