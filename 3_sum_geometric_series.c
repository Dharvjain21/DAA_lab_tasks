#include <stdio.h>
#include <math.h>

double method1(double first, double ratio, int terms)
{
    if (ratio == 1)
        return first * terms;

    return first * (pow(ratio, terms) - 1) / (ratio - 1);
}

double method2(double first, double ratio, int terms)
{
    double sum = 0;
    int i;

    for (i = 1; i <= terms; i++)
    {
        sum = sum + first;
        first = first * ratio;
    }

    return sum;
}

int main()
{
    double first, ratio;
    int terms;

    printf("Enter first term, common ratio and number of terms: ");
    scanf("%lf %lf %d", &first, &ratio, &terms);

    printf("Method 1 sum = %.2lf\n", method1(first, ratio, terms));
    printf("Method 2 sum = %.2lf", method2(first, ratio, terms));

    return 0;
}
