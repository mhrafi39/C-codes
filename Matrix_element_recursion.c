// WAP to display all array elements of a 2D array using recursion.

#include <stdio.h>

void display(int n, int m, int arry[n][m], int row, int col);

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int arry[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arry[i][j]);
        }
    }
    display(n, m, arry, 0, 0);
    return 0;
}

void display(int n, int m, int arry[n][m], int row, int col)
{
    if (row >= n)
    {
        return;
    }

    if (col >= m)
    {
        printf("\n");
        display(n, m, arry, row + 1, 0);
        return;
    }

    printf("%d ", arry[row][col]);
    display(n, m, arry, row, col + 1);
}
