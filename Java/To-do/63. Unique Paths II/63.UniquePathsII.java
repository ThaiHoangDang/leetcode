import java.util.*;

class Solution {
  public int uniquePathsWithObstacles(int[][] obstacleGrid) {

    int r = obstacleGrid.length, c = obstacleGrid[0].length;
    if (obstacleGrid[0][0] == 1 || obstacleGrid[r - 1][c - 1] == 1) return 0;
    int[] track = new int[c], track2 = new int[c];
    track[0] = 1;

		for (int i = 0; i < r; i++) {

			for (int j = 0; j < c; j++) {

        if (obstacleGrid[i][j] != 1 && (i != 0 && j != 0)) {

          if (i == 0) {
            track[j] = obstacleGrid[i][j - 1] == 0 ? track[j] : 0;
          } else if (j == 0) {
            track2[j] = obstacleGrid[i - 1][j] == 0 ? track[j] : 0;
          } else track2[j] = (obstacleGrid[i][j - 1] == 0 ? track2[j - 1] : 0) + (obstacleGrid[i - 1][j] == 0 ? track[j] : 0);
        }
			}
			track = track2;
		}
		
		return track[c - 1];
  }
}