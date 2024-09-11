import java.util.*;

class Solution {
	public List<List<Integer>> subsets(int[] nums) {
		List<List<Integer>> result = new ArrayList<>();
		result.add(new ArrayList<>());
		for (int num : nums) helper(result, num);
		return result;
	}

	private void helper(List<List<Integer>> result, int num) {

		List<List<Integer>> copy = new ArrayList<>(result);
		for (List<Integer> item : copy) {
			List<Integer> temp = new ArrayList<>(item);
			temp.add(num);
			result.add(temp);
		}

	}
}