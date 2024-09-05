import java.util.*;

class Solution {
	public int uniquePaths(int r, int c) {
		int[] track = new int[c], track2 = new int[c];
		Arrays.fill(track, 1); track2[0] = 1;

		for (int i = 1; i < r; i++) {

			for (int j = 1; j < c; j++) {

				track2[j] = track2[j - 1] + track[j];
			}
			track = track2;
		}
		
		return track[c - 1];
	}
}