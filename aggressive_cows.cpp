//Question Link : https://www.geeksforgeeks.org/problems/aggressive-cows/1
class Solution {
public:
    bool canplace(int c, vector<int>& s, int d) {
        int count = 1;      
        int last = s[0];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] - last >= d) {
                count++;
                last = s[i];
                if (count >= c) return true;
            }
        }
        return false;
    }

    int aggressiveCows(vector<int>& stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int l = 1;
        int r = stalls.back() - stalls.front();
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canplace(k, stalls, mid)) {
                ans = mid;
                l = mid + 1; 
            } else {
                r = mid - 1; 
            }
        }
        return ans;
    }
};
