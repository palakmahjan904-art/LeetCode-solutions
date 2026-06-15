// 🎯 Pattern: Fixed-Size Sliding Window (Mathematical Optimization)
// 🔗 LeetCode Link: https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
// 📝 Summary: 'k' size ke un sub-arrays ka count nikalna jinka average >= threshold ho.
// 💡 Logic: 
//    1. Baar-baar divide (/) karne se bachne ke liye humne shortcut lagaya: targetsum = threshold * k.
//    2. Pehle loop se starting ki 'k' elements ka sum nikala aur target se compare kiya.
//    3. Phir sliding window chalayi: Naya element PLUS (+) aur piche chhootne wala MINUS (-).
//    4. Har slide par agar currentsum >= targetsum hua, toh count++ kar diya.
// ⏱️ Complexity: O(n) Time (Super Fast!) | O(1) Space (Beats 96.03% Memory! 🔥)

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        if(n<k)
        {
            return -1;
        }
        int targetsum=threshold*k ;
        int count=0;
        int currentsum=0;
        for(int i=0;i<k;i++)
        {
            currentsum+=arr[i];
        }
        
            if(currentsum>=targetsum)
            {
                count++;
            }
            for(int right=k;right<n;right++)
            {
             currentsum+=arr[right];
             currentsum-=arr[right-k];
            
             if(currentsum>=targetsum)
             {
                count++;
             }
            }
        
        return count;
    }
};
