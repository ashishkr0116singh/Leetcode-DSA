/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void dfs(int** image, int imageSize, int* imageColSize,
         int sr, int sc, int newColor, int oldColor) {
    // Boundary check
    if (sr < 0 || sr >= imageSize || sc < 0 || sc >= imageColSize[sr]) return;
    // Stop if pixel is not the old color
    if (image[sr][sc] != oldColor) return;

    // Recolor the pixel
    image[sr][sc] = newColor;

    // Explore neighbors
    dfs(image, imageSize, imageColSize, sr+1, sc, newColor, oldColor);
    dfs(image, imageSize, imageColSize, sr-1, sc, newColor, oldColor);
    dfs(image, imageSize, imageColSize, sr, sc+1, newColor, oldColor);
    dfs(image, imageSize, imageColSize, sr, sc-1, newColor, oldColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize,
                int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes) {
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    int oldColor = image[sr][sc];
    if (oldColor != newColor) {
        dfs(image, imageSize, imageColSize, sr, sc, newColor, oldColor);
    }
    return image;
}
