import java.util.*;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap <Integer, Integer> hm = new HashMap <> ();

        for(int i=0; i<nums.length; i++)
        {
            int remain = target - nums[i];

            if(hm.containsKey(remain)) {
                return new int[] {hm.get(remain), i};
            }
            hm.put(nums[i], i);
        }

        return new int[] {};
    }
}
