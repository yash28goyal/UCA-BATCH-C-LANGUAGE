#include <stdio.h>

int maxCherry(int i, int j, int m, int n, int arr[][n]) {
    if (i >= m || j >= n)
		{
			return 0;
		}

		if (i == m - 1 && j == n - 1)
		{
			return arr[i][j];
		}

		int down = maxCherry(i + 1, j, m, n, arr);

		int right = maxCherry(i, j + 1, m, n, arr);

		return ((down>right) ? down : right) + arr[i][j];
}

int main() {
    int arr[4][4] = 
		{
			{1, 1, 1, 1},
			{1, 1, 1, 1},
			{1, 1, 1, 1},
			{0, 0, 0, 0}
		};

    int ans = maxCherry(0, 0, 4, 4, arr);
    printf("%d", ans);
    return 0;
}