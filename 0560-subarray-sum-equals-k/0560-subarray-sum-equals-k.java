class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap();
        int count =0, sum = 0;
        for(int i=0; i< nums.length; i++){
            sum += nums[i];
            if(sum == k){
                count++;
            }
            int rem = sum - k;
            if(map.containsKey(rem)){
               count+= map.getOrDefault(rem, 0);
            }
            
            map.put(sum, map.getOrDefault(sum, 0) + 1);
            

        }
        return count;
    }
}