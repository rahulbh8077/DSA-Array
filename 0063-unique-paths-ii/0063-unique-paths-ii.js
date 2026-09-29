var uniquePathsWithObstacles = function(obstacleGrid) {
    const m = obstacleGrid.length;
    const n = obstacleGrid[0].length;

    const dp = Array(n).fill(0);
    dp[0] = 1;

    for (let row = 0; row < m; row++) {
        for (let col = 0; col < n; col++) {

            // Obstacle: no path can pass through it
            if (obstacleGrid[row][col] === 1) {
                dp[col] = 0;
            } 
            // Add paths coming from the left
            else if (col > 0) {
                dp[col] += dp[col - 1];
            }
        }
    }

    return dp[n - 1];
};
