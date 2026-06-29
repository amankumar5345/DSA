class Solution {
public:
    bool isLetter (char c){
        return (c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z');
    }
    string reverseOnlyLetters(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r){
            if(!isLetter(s[l])){
                l++;
            }
            else if (!isLetter(s[r])){
                r--;
            }
            else {
                swap (s[l], s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};