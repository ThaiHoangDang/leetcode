import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> result = new ArrayList<>();
        helper(result, n, k, new ArrayList<>(), 1);
        return result;
    }

    private void helper(List<List<Integer>> result, int n, int k, List<Integer> listSoFar, int start) {
        if (listSoFar.size() == k) {
            result.add(new ArrayList<>(listSoFar)); // Add a copy of listSoFar
            return;
        }

        for (int i = start; i <= n; i++) {
            listSoFar.add(i);
            helper(result, n, k, listSoFar, i + 1); // Move to the next number
            listSoFar.remove(listSoFar.size() - 1); // Backtrack
        }
    }
}
