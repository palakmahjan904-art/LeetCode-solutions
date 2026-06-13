// 🎯 Pattern: Fixed-Size Sliding Window
// 🔗 LeetCode Link: https://leetcode.com/problems/maximum-average-subarray-i/
// 📝 Summary: 'k' size ki continuous window ka Maximum Average nikalna hai.
// 💡 Logic: Naye element ko sum me '+' karo aur window ke piche wale element ko '-' karo.
// ⏱️ Complexity: O(n) Time | O(1) Space


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
      int n=nums.size();
    if(n<k){

        return -1;
    }
    int sum=0;
    for(int i=0;i<k;i++)
    {
      sum+=nums[i];
    }
    int maxSum=sum;
    for(int right=k;right<n;right++)
    {
        sum+=nums[right]-nums[right-k];
        maxSum=max(maxSum,sum);
    }
    return (double)maxSum/k ;  
    }
};
