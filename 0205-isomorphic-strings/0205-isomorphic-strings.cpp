class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_set <long long> a;
        unordered_set <int> b,c;
        if(s.size() != t.size()) return false;
        for(int i = 0;i<s.size();i++){
            long long key = ((long long)s[i] << 32) | t[i]; 
            a.insert(key);
            b.insert(s[i]);
            c.insert(t[i]);
        }
        return (a.size()==b.size()&&a.size()==c.size());

    }
};