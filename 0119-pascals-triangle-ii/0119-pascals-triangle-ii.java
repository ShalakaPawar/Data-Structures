class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> prev = new ArrayList();
        
        for (int i = 0 ; i< rowIndex+1; i++) {
            List<Integer> curr = new ArrayList(Collections.nCopies(i + 1, 1));
            for (int j = 1 ; j < i; j++) {
                curr.set(j, prev.get(j-1) + prev.get(j));
            }
            
            prev = curr;
        }
        return prev;


    }

}