import java.util.*;

class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        permute(result, new ArrayList<>(), nums);
        return result;
    }

    private void permute(List<List<Integer>> result, List<Integer> selected, int[] remaining) {

        if (remaining.length == 0) {
            result.add(new ArrayList<>(selected));
            return;
        }

        for (int i = 0; i < remaining.length; i++) {
            if (i == 0 || i != 0 && remaining[i] != remaining[i - 1]) {
                List<Integer> temp = new ArrayList<>(selected); temp.add(remaining[i]);
                int[] newRemaining = new int[remaining.length - 1];
                for (int j = 0, k = 0; j < remaining.length; j++) {
                    if (j != i) {
                        newRemaining[k++] = remaining[j];
                    }
                }
                permute(result, temp, newRemaining);
            }
        }
    }
}