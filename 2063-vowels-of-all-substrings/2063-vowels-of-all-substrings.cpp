class Solution {
public:
    long long countVowels(const string& s) {
        int n = s.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || 
                s[i] == 'o' || s[i] == 'u') {
                sum += 1LL * (i + 1) * (n - i);
            }
        }

        return sum;
    }
};