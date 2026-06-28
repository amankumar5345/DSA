class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> mapST (256, -1);
        vector <int> mapTS(256, -1);
        for (int i = 0; i <s.size(); i++){
            if(mapST[s[i]] != mapTS[t[i]]){
                return false;
            }
            mapST [s[i]] = i;
            mapTS[t[i]] = i;
        }
        return true;
    }
};