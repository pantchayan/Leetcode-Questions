#include <vector>
using namespace std;
class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        if (grid.size() == 0)
            return 0;

        int tr = grid.size();
        int tc = grid[0].size();

        int maxSize = 0;
        for (int i = 0; i < tr; i++)
        {
            for (int j = 0; j < tc; j++)
            {
                if (grid[i][j] == 1)
                {

                    int size = dfs_numsIslands(i, j, tr, tc, grid);
                    if (maxSize < size)
                    {
                        maxSize = size;
                    }
                }
            }
        }

        return maxSize;
    }

    int dfs_numsIslands(int r, int c, int tr, int tc, vector<vector<int>> &grid)
    {
        if (grid[r][c] == 0)
        {
            return 0;
        }

        //DFS body
        grid[r][c] = 0;
        int size = 0;
        if (c + 1 < tc)
        {
            size += dfs_numsIslands(r, c + 1, tr, tc, grid);
        }
        if (r + 1 < tr)
        {
            size += dfs_numsIslands(r + 1, c, tr, tc, grid);
        }
        if (c - 1 >= 0)
        {
            size += dfs_numsIslands(r, c - 1, tr, tc, grid);
        }
        if (r - 1 >= 0)
        {
            size += dfs_numsIslands(r - 1, c, tr, tc, grid);
        }

        return size + 1;
    }
};