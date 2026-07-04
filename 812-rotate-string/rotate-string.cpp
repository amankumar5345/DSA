class Solution {
public:
    bool rotateString(string s, string goal) {
        if ( s.size() != goal.size())
        return false;
        int n = s.size();
        for (int shift = 0; shift < n; shift++){
            bool match = true;

            for (int i = 0; i < n; i++){
                if (s[(i + shift) % n] != goal[i]){
                    match = false;
                    break;
                }
            }
            if (match)
            return true;
        }
        return false;
    }
};