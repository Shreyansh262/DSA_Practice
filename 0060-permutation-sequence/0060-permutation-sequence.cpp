class Solution {
public:
    int factorial(int num) {
        if(num<=1) return 1;
        return num*factorial(num-1);
    }
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        k--; 

        for (int i = n; i > 0; i--) {
            int x = k / factorial(i - 1);

            ans += to_string(nums[x]);  
            nums.erase(nums.begin() + x); 
            k = k % factorial(i - 1);
        }

        return ans;
    }
};