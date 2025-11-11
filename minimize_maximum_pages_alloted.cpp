//question link : https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
#
Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: If it is not possible to allocate books to all students, return -1.

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
=> [12] and [34, 67, 90] Maximum Pages = 191
=> [12, 34] and [67, 90] Maximum Pages = 157
=> [12, 34, 67] and [90] Maximum Pages = 113.
The third combination has the minimum pages assigned to a student which is 113.
#

class Solution {
public:
    bool canalloc(int p, vector<int> &pp, int s) {
        int t = 0, students = 1;
        for (auto it : pp) {
            if (t + it > p) {
                students++;
                t = it;
            } else {
                t += it;
            }
        }
        return students <= s;
    }

    int findPages(vector<int> &arr, int k) {
        if (k > arr.size()) return -1;
        
        int l = *max_element(arr.begin(), arr.end());
        int r = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (canalloc(mid, arr, k)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
