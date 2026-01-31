class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Brute Force O(n^2)
        //  int j = 0, ans = 0;
        //  vector <char> store;
        //  while(j<s.size()){
        //      while(find(store.begin(),store.end(),s[j]) != store.end()){
        //          store.erase(store.begin());
        //      }
        //      store.push_back(s[j]);
        //      ans = max(ans,(int)store.size());
        //      j++;
        //  }
        //  return ans;

        // Optimized O(n)
        int i = 0, j = 0, ans = 0;
        vector<int> last(256, -1);
        while (j < s.size()) {
            i = max(i, last[s[j]] + 1);
            last[s[j]] = j;
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};