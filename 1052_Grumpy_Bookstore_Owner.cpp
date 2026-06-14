// 🎯 Pattern: Fixed-Size Sliding Window (With Initial Baseline Sum)
// 🔗 LeetCode Link: https://leetcode.com/problems/grumpy-bookstore-owner/
// 📝 Summary: Dukaandar ki continuous 'minutes' gussa control karne ki power ka use karke maximum satisfied customers nikalna.
// 💡 Logic: 
//    1. Pehle jo automatic satisfied hain unka sum alag loop me nikal lo (grumpy == 0).
//    2. Fir sliding window se check karo ki continuous 'minutes' me kahan sabse zyada extra customers bachaye ja sakte hain (grumpy == 1).
//    3. Dono sums ko jod kar total return kar do.
// ⏱️ Complexity: O(n) Time | O(1) Space

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        if(n<minutes)
        {
            return -1;
        }
        int alreadystisfied=0;
          for(int i=0;i<n;i++){
               if(grumpy[i]==0)
                alreadystisfied+=customers[i];
          }
        int extra=0;
        for(int i=0;i<minutes;i++)
        {
           if(grumpy[i]==1)
           {
            extra+=customers[i];
           }
        }
          int maxextra=extra;
          for(int check=minutes;check<n;check++)
          {
            if(grumpy[check]==1)
            {
                extra+=customers[check];
            }
            if(grumpy[check-minutes]==1)
            {
                extra-=customers[check-minutes];
            }
             maxextra=max(maxextra,extra);
          }
         
          return alreadystisfied+maxextra;
    }
};
