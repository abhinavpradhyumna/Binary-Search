/*Problem Link : https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
Given an array arr[] where each element denotes the length of a board, and an integer k representing the number of painters available. Each painter takes 1 unit of time to paint 1 unit length of a board.

Determine the minimum amount of time required to paint all the boards, under the constraint that each painter can paint only a contiguous sequence of boards (no skipping or splitting allowed).

Examples:

Input: arr[] = [5, 10, 30, 20, 15], k = 3
Output: 35
Explanation: The optimal allocation of boards among 3 painters is - 
Painter 1 → [5, 10] → time = 15
Painter 2 → [30] → time = 30
Painter 3 → [20, 15] → time = 35
Job will be done when all painters finish i.e. at time = max(15, 30, 35) = 35
*/
class Solution {
  public:
  
    bool canpaint(int b , vector<int>&a , int k)
    {
        int t=0 , dt = 1;
        for(auto it : a)
        {
            if(t+it>b)
            {
                t = it;
                dt++;
            }
            else
            {
                t+=it;
            }
        }
        return dt <= k;
    }
  
    int minTime(vector<int>& arr, int k) {
        // code here
        int l = *max_element(arr.begin(),arr.end());
        int r = accumulate(arr.begin(),arr.end(),0);
        int mid = l;
        int ans = INT_MAX;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(canpaint(mid,arr,k))
            {
                ans = min(ans,mid);
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return ans;
    }
};
