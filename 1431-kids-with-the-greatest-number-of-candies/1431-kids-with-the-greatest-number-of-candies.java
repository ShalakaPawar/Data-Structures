class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int[] initialArr = Arrays.copyOf(candies, candies.length);
        Arrays.sort(candies);
        int max = Arrays.stream(candies).max().getAsInt();

        List<Boolean> result = new ArrayList<>(Collections.emptyList());
        Arrays.stream(initialArr).forEach(ele -> {
            if(ele + extraCandies >= max)
                result.add(true);
            else
                result.add(false);
        });
        return result;
    }
}