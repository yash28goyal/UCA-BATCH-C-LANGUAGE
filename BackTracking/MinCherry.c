#include <stdio.h>
#include <stdbool.h>

bool valid(int i, int j, int m, int n) {
    if (i < 0 || j < 0 || i >= m || j >= n)
		return false;
	return true;
}

int minCherry(int i, int j, int m, int n, int arr[][n]) {
    if (i == m - 1 && j == n - 1)
	{
		return arr[i][j];
	}
	bool choice1 = valid(i + 1, j, m, n);
	bool choice2 = valid(i, j + 1, m, n);
	if (choice1 && choice2)
	{
		int ch1 = minCherry(i + 1, j, m, n, arr);
		int ch2 = minCherry(i, j + 1, m, n, arr);
		return arr[i][j] + ((ch1 > ch2) ? ch2 : ch1);
	}
	if (choice1)
		return arr[i][j] + minCherry(i + 1, j, m, n, arr);
	return arr[i][j] + minCherry(i, j + 1, m, n, arr);
}

int main() {
    int arr[4][4] = 
    {
		{1, 1, 1, 1},
		{1, 1, 1, 1},
		{1, 1, 1, 1},
		{0, 0, 0, 0}
	};
    int ans = minCherry(0, 0, 4, 4, arr);
    printf("%d", ans);
}