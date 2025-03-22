class Solution {
    public String[] findRelativeRanks(int[] score) {
        PriorityQueue<Pair<Integer, Integer>>  queue= new PriorityQueue<>(Comparator.comparing(Pair :: getKey, Comparator.reverseOrder()));
    
        for (int i=0; i<score.length;i++) {
            queue.add(new Pair(score[i], i));
        }
        
        String val = "Gold Medal";
        String[] result = new String[score.length];
        int j = 1;
        while(!queue.isEmpty()) {
            if(j == 1){
                val = "Gold Medal";
            }
            else if(j == 2){
                val = "Silver Medal";
            } else if (j == 3) {
                val = "Bronze Medal";
            } else {
                val = String.valueOf(j);
            }
            result[queue.poll().getValue()] = val;
            j++;
        }
        return result;
    }
}