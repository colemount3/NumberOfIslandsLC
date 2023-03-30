// NumberOfIslandsLC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //finding grid size
        int rows = grid.size();
        if (rows == 0)
        {
            return 0;
        }
        int columns = grid[0].size();
        if (columns > 300)
        {
            return 0;
        }
       
        int islandCount = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
        

                markIslands(islandCount, grid, i, j);

            }
        }

        return islandCount;
    }

    void markIslands(int& islandCount, vector<vector<char>>& grid, int i, int j)
    {


        //using variables for adjascent numbers
        char right = '0';
        char left = '0';
        char up = '0';
        char down = '0';

        int x = i + 1;
        if (x >= grid.size())
        {
            x = 0;
            right = '0';
        }
        else
        {
            right = grid[x][j];
        }
        int y = j + 1;
        if (y >= grid[0].size())
        {
            y = 0;
            up = '0';

        }
        else
        {
            up = grid[i][y];
        }
        int z = i - 1;
        if (z < 0)
        {
            z = 0;
            left = '0';
        }
        else
        {
            left = grid[z][j];
        }
        int u = j - 1;
        if (u < 0)
        {
            down = '0';
            u = 0;

        }
        else
        {
            down = grid[i][u];
        }


        if (grid[i][j] == '1')
        {
            //markIslands(islandCount, grid, i + 1, j);

            islandCount++;
        }
        if (grid[i][j] == '1' || grid[i][j] == '2')
        {
            if (right == '1')
            {
                grid[x][j] = '2';
                markIslands(islandCount, grid, x, j);

            }
            if (up == '1')
            {

                grid[i][y] = '2';
                markIslands(islandCount, grid, i, y);
            }
            if (left == '1')
            {
                grid[z][j] = '2';

                markIslands(islandCount, grid, z, j);

            }
            if (down == '1')
            {
                grid[i][u] = '2';

                markIslands(islandCount, grid, i, u);

            }

            grid[i][j] = '2';
        }
    }





};



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
