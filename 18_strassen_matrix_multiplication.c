#include <stdio.h>

#define MAX_ORDER 8

void addMatrix(int first[MAX_ORDER][MAX_ORDER], int second[MAX_ORDER][MAX_ORDER],
               int result[MAX_ORDER][MAX_ORDER], int size, int sign)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result[i][j] = first[i][j] + sign * second[i][j];
}

void strassen(int first[MAX_ORDER][MAX_ORDER], int second[MAX_ORDER][MAX_ORDER],
              int result[MAX_ORDER][MAX_ORDER], int size)
{
    if (size == 1)
    {
        result[0][0] = first[0][0] * second[0][0];
        return;
    }

    int half = size / 2;
    int a11[MAX_ORDER][MAX_ORDER] = {0}, a12[MAX_ORDER][MAX_ORDER] = {0};
    int a21[MAX_ORDER][MAX_ORDER] = {0}, a22[MAX_ORDER][MAX_ORDER] = {0};
    int b11[MAX_ORDER][MAX_ORDER] = {0}, b12[MAX_ORDER][MAX_ORDER] = {0};
    int b21[MAX_ORDER][MAX_ORDER] = {0}, b22[MAX_ORDER][MAX_ORDER] = {0};
    int p1[MAX_ORDER][MAX_ORDER] = {0}, p2[MAX_ORDER][MAX_ORDER] = {0};
    int p3[MAX_ORDER][MAX_ORDER] = {0}, p4[MAX_ORDER][MAX_ORDER] = {0};
    int p5[MAX_ORDER][MAX_ORDER] = {0}, p6[MAX_ORDER][MAX_ORDER] = {0};
    int p7[MAX_ORDER][MAX_ORDER] = {0};
    int firstTemp[MAX_ORDER][MAX_ORDER] = {0}, secondTemp[MAX_ORDER][MAX_ORDER] = {0};

    for (int i = 0; i < half; i++)
        for (int j = 0; j < half; j++)
        {
            a11[i][j] = first[i][j];
            a12[i][j] = first[i][j + half];
            a21[i][j] = first[i + half][j];
            a22[i][j] = first[i + half][j + half];
            b11[i][j] = second[i][j];
            b12[i][j] = second[i][j + half];
            b21[i][j] = second[i + half][j];
            b22[i][j] = second[i + half][j + half];
        }

    addMatrix(a11, a22, firstTemp, half, 1);
    addMatrix(b11, b22, secondTemp, half, 1);
    strassen(firstTemp, secondTemp, p1, half);
    addMatrix(a21, a22, firstTemp, half, 1);
    strassen(firstTemp, b11, p2, half);
    addMatrix(b12, b22, secondTemp, half, -1);
    strassen(a11, secondTemp, p3, half);
    addMatrix(b21, b11, secondTemp, half, -1);
    strassen(a22, secondTemp, p4, half);
    addMatrix(a11, a12, firstTemp, half, 1);
    strassen(firstTemp, b22, p5, half);
    addMatrix(a21, a11, firstTemp, half, -1);
    addMatrix(b11, b12, secondTemp, half, 1);
    strassen(firstTemp, secondTemp, p6, half);
    addMatrix(a12, a22, firstTemp, half, -1);
    addMatrix(b21, b22, secondTemp, half, 1);
    strassen(firstTemp, secondTemp, p7, half);

    for (int i = 0; i < half; i++)
        for (int j = 0; j < half; j++)
        {
            result[i][j] = p1[i][j] + p4[i][j] - p5[i][j] + p7[i][j];
            result[i][j + half] = p3[i][j] + p5[i][j];
            result[i + half][j] = p2[i][j] + p4[i][j];
            result[i + half][j + half] = p1[i][j] - p2[i][j] + p3[i][j] + p6[i][j];
        }
}

int isPowerOfTwo(int number)
{
    return number > 0 && (number & (number - 1)) == 0;
}

int main()
{
    int first[MAX_ORDER][MAX_ORDER] = {0};
    int second[MAX_ORDER][MAX_ORDER] = {0};
    int result[MAX_ORDER][MAX_ORDER] = {0};
    int size;

    printf("LAB TASK 6 - STRASSEN'S MATRIX MULTIPLICATION\n");
    printf("Enter the order of the square matrices (power of 2, up to %d): ", MAX_ORDER);
    scanf("%d", &size);

    if (!isPowerOfTwo(size) || size > MAX_ORDER)
    {
        printf("Invalid order. Use 1, 2, 4, or 8.\n");
        return 1;
    }

    printf("Enter the first matrix:\n");
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            scanf("%d", &first[i][j]);

    printf("Enter the second matrix:\n");
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            scanf("%d", &second[i][j]);

    strassen(first, second, result, size);
    printf("Product matrix:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }

    printf("Strassen complexity: O(n^2.81), using 7 recursive multiplications instead of 8.\n");
    printf("Normal multiplication takes O(n^3) time, so Strassen is advantageous for large matrices.\n");
    return 0;
}