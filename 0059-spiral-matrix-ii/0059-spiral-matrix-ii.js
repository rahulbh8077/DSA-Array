var generateMatrix = function(n) {
    const matrix = Array.from({ length: n }, () => Array(n).fill(0));

    let top = 0;
    let bottom = n - 1;
    let left = 0;
    let right = n - 1;
    let num = 1;

    while (top <= bottom && left <= right) {
        // Left -> Right
        for (let col = left; col <= right; col++) {
            matrix[top][col] = num++;
        }
        top++;

        // Top -> Bottom
        for (let row = top; row <= bottom; row++) {
            matrix[row][right] = num++;
        }
        right--;

        // Right -> Left
        if (top <= bottom) {
            for (let col = right; col >= left; col--) {
                matrix[bottom][col] = num++;
            }
            bottom--;
        }

        // Bottom -> Top
        if (left <= right) {
            for (let row = bottom; row >= top; row--) {
                matrix[row][left] = num++;
            }
            left++;
        }
    }

    return matrix;
};
