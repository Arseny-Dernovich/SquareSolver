#include <stdio.h>
#include <stdbool.h>
#include <math.h>
double square_solver_one_root(double b, double c);                              // Функция для нахождения корня линейного уравнения (когда a=0)
void square_solver_roots(double a, double b, double c, double *x1, double *x2); // Функция для нахождения корней квадаратного уравнения

int main(void)
{
    printf("Эта программа решает квадратное уравнение\n");
    double a, b, c;      // коэффиценты квадратного кравнения , a-старший коэффицент , b-средний , c-свободный.
    double x1, x2, root; // корни нашего квадартного уравнения.
    printf("Введите значения коэффицентов \nквадратного уравнения ax^2 + bx + c (a,b,c):");
    while ((scanf("%lf %lf %lf", &a, &b, &c)) == 3)
    {
        if (a == 0 && b != 0)
        {
            if(c==0)
            root=0;
            else
            root = square_solver_one_root(b, c);
            printf("Корень линейного уравнения %.1lfx + %.1lf=0   x = %.2lf\n", b, c, root);
        }
        else if (a == 0 && b == 0 && c == 0)  
        {
            printf("Уравнение имеет бесконечно много решений (все коэффициенты равны нулю).\n");
        }
        else if (a == 0 && b == 0 && c != 0)
        {
            printf("Уравнение не имеет решений (c != 0, а старшие коэффициенты равны нулю).\n");
        }
        else
        {
            square_solver_roots(a, b, c, &x1, &x2);
            if (x1 == x2)
                printf("Корень квадратно уравнения %.1lfx^2 + %.1lfx + %.1lf = 0   x = %.2lf\n", a, b, c, x2);
            else
                printf("Корни квадратного уравнения %.1lfx^2 + %.1lfx + %.1lf = 0  -  x1 = %.2lf и x2 = %.2lf\n", a, b, c, x1, x2);
        }
        printf("Снова введите значения коэффицентов \nквадратного уравнения ax^2 + bx + c (a,b,c):");
    }
    printf("Программа завершенна");

    return 0;
}
void square_solver_roots(double a, double b, double c, double *x1, double *x2)
{
    double discriminant = (b * b) - (4 * a * c);
    if (discriminant >= 0)
    {
        double sqrt_discriminant = sqrt(discriminant);
        *x1 = (-b - sqrt_discriminant) / (2 * a);
        *x2 = (-b + sqrt_discriminant) / (2 * a);
    }
    else
    {
        printf("Корней нет (дискриминант отрицательный).\n");
        *x1 = *x2 = NAN;
    }
}

double square_solver_one_root(double b, double c)
{
    return (-c) / b;
}
