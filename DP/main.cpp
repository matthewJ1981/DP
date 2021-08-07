//#define TESTING 1

#ifndef TESTING

#include <iostream>
#include <vector>
std::vector<int> stairs(int totStairs, int maxSteps)
{
	std::vector<int> dp(totStairs + 1);

	dp[0] = 1;
	dp[1] = 1;
	for (int currStair = 2; currStair <= totStairs; ++currStair)
	{
		for (int steps = 1; steps <= maxSteps; ++steps)
		{
			if (currStair - steps >= 0)
				dp[currStair] += dp[currStair - steps];
		}
	}

	return dp;
}

std::vector<int> paidStairs(int totStairs, int stairsArr[], int maxSteps)
{
	std::vector<int> dp(totStairs + 1, std::numeric_limits<int>::max());

	dp[0] = 0;
	for (int currStair = 1; currStair <= totStairs; ++currStair)
	{
		for (int steps = 1; steps <= maxSteps; ++steps)
		{
			if (currStair - steps >= 0)
				dp[currStair] = stairsArr[currStair] + std::min(dp[currStair], dp[currStair - steps]);
		}
	}

	return dp;
}

std::vector<int> paidStairsRoute(int totStairs, int stairsArr[], int maxSteps)
{
	std::vector<int> dp(totStairs + 1, std::numeric_limits<int>::max());
	std::vector<int> path(totStairs + 1);

	dp[0] = 0;
	for (int currStair = 1; currStair <= totStairs; ++currStair)
	{
		for (int steps = 1; steps <= maxSteps; ++steps)
		{
			if (currStair - steps >= 0)
			{
				if (dp[currStair] < dp[currStair - steps])
				{
					dp[currStair] = stairsArr[currStair] + dp[currStair];
					path[currStair] = currStair;
				}
				else
				{
					dp[currStair] = stairsArr[currStair] + dp[currStair - steps];
					path[currStair] = currStair - steps;
				}
			}
		}
	}

	std::vector<int> actualPath;
	for (int currStair = totStairs; currStair >= 0; currStair = path[currStair])
	{
		actualPath.push_back(currStair);
		if (currStair == 0)
			break;
	}
	std::reverse(actualPath.begin(), actualPath.end());
	return actualPath;
}

bool isBlocked(int i, int j, std::vector<std::pair<int, int>>& coords)
{
	for (int k = 0; k < coords.size(); ++k)
	{
		if (i == coords[k].first && j == coords[k].second)
		{
			return true;
		}
	}

	return false;
}
int matrixBlocked(int m, int n, std::vector<std::pair<int, int>>& coords)
{
	std::vector<std::vector<int>> dp(m, std::vector<int>(n));

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (isBlocked(i, j, coords))
			{
				dp[i][j] = 0;
				continue;
			}

			if (i > 0 && j > 0)
				dp[i][j] += dp[i][j - 1] + dp[i - 1][j];
			else if (i > 0)
				dp[i][j] += dp[i - 1][j];
			else if (j > 0)
				dp[i][j] += dp[i][j - 1];
			else dp[i][j] = 1;
		}
	}

	return dp[m - 1][n - 1];
}

int matrix(int m, int n)
{
	std::vector<std::vector<int>> dp(m, std::vector<int>(n));

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i > 0 && j > 0)
				dp[i][j] += dp[i][j - 1] + dp[i - 1][j];
			else if (i > 0)
				dp[i][j] += dp[i - 1][j];
			else if (j > 0)
				dp[i][j] += dp[i][j - 1];
			else dp[i][j] = 1;
		}
	}

	return dp[m - 1][n - 1];
}

int matrixMax(int m, int n, std::vector<std::vector<int>> amounts)
{
	std::vector<std::vector<int>> dp(m, std::vector<int>(n));

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i > 0 && j > 0)
				dp[i][j] = std::max(dp[i][j - 1],  dp[i - 1][j]) + amounts[i][j];
			else if (i > 0)
				dp[i][j] = dp[i - 1][j] + amounts[i][j];
			else if (j > 0)
				dp[i][j] = dp[i][j - 1] + amounts[i][j];
			else dp[i][j] = 1;
		}
	}

	return dp[m - 1][n - 1];

}
int main()
{
	std::vector<std::vector<int>> amounts{ {1, 2, 2, 1}, {3, 1, 1, 1}, {4, 4, 2, 1} };
	matrixMax(3, 4, amounts);
	return 0;
}

#else if // TESTING

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#endif // TESTING