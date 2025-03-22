class Solution {
    public int singleNumber(int[] nums) {
        List<Integer> counts = new ArrayList<>();
        for (int i : nums) {
            if(counts.contains(i)){
                counts.remove(Integer.valueOf(i));
            } else {
                counts.add(i);
            }
        }
        return counts.get(0);
    }
}