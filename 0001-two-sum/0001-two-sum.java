class Solution {
    public int[] twoSum(int[] nums, int target) {
        
        HashMap<Integer, Integer> map = new HashMap<>();
        int currIdx = 0;
        
        for(int n : nums){
            int comp = target - n;

            if (map.containsKey(comp)){
                int[] ans = {currIdx, map.get(comp)};
                return ans;
            }else{
                map.put(n, currIdx);
            }

            currIdx++;
        }

        return new int[]{};
    }
}