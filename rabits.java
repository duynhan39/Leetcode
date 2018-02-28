import java.util.HashMap;

class Solution {
    public int numRabbits(int[] answers) {
        HashMap<Integer, Integer> counts = new HashMap<>();
        for(int each:answers) {
            if(!counts.containsKey(each)) {
                counts.put(each, 1);
            } else {
                counts.put(each, counts.get(each)+1);
            }
        }
        Integer total=0;
        for(int each:counts.keySet()) {
            total+=((counts.get(each)+each)/(each+1))*(each+1);
        }
        return total;
    }
    
}
