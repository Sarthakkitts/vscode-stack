
#include <stdio.h>

int main()
{
    int matrix[10][10];
    int sparse[100][3];
    int rows, cols;
    int i, j, k = 1;
    int nonzero = 0;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("Enter the matrix elements:\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);

            if (matrix[i][j] != 0)
                nonzero++;
        }
    }

    if (nonzero < (rows * cols) / 2)
    {
        printf("\nIt is a Sparse Matrix.\n");

        // First row contains rows, columns and non-zero count
        sparse[0][0] = rows;
        sparse[0][1] = cols;
        sparse[0][2] = nonzero;

        // Store non-zero elements
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < cols; j++)
            {
                if (matrix[i][j] != 0)
                {
                    sparse[k][0] = i;
                    sparse[k][1] = j;
                    sparse[k][2] = matrix[i][j];
                    k++;
                }
            }
        }

        printf("\n3-Tuple Representation:\n");
        printf("Row\tColumn\tValue\n");

        for (i = 0; i <= nonzero; i++)
        {
            printf("%d\t%d\t%d\n",
                   sparse[i][0],
                   sparse[i][1],
                   sparse[i][2]);
        }
    }
    else
    {
        printf("\nIt is NOT a Sparse Matrix.\n");
    }

    return 0;
}