#include <stdio.h>
#include <stdbool.h>
#include <math.h>
double square_solver_one_root (double b, double c);                              // Функция для нахождения корня линейного уравнения (когда a=0)
void square_solver_roots (double a, double b, double c, double *x1, double *x2); // Функция для нахождения корней квадаратного уравнения

int main(void)
{
    printf("Эта программа решает квадратное уравнение\n");
    double a, b, c;
    double eps = 1e-12;  // коэффиценты квадратного кравнения , a-старший коэффицент , b-средний , c-свободный.
    double x1, x2, root; // корни нашего квадартного уравнения.
    bool flag = true;
    while (flag)
    {
        printf ("Введите значения коэффицентов \nквадратного уравнения ax^2 + bx + c (a,b,c):");
        if (scanf ("%lf %lf %lf", &a, &b, &c) != 3) {
            printf ("Неверные входные значения коэффицентов\n(коэффиценты могут являться только числами)\n");
            while (getchar() != '\n');
            continue;
        }
        if (fabs(a) < eps && fabs(b) > eps) {
            if (fabs(c) < eps)
                root = 0;
            else
                root = square_solver_one_root (b, c);
                printf ("Корень линейного уравнения %.1lfx + %.1lf=0   x = %.2lf\n", b, c, root);
        }
        else if (fabs(a) < eps && fabs(b) < eps && fabs(c) < eps) {
            printf ("Уравнение имеет бесконечно много решений (все коэффициенты равны нулю).\n");
        }
        else if (fabs(a) < eps && fabs(b) < eps && fabs(c) > eps) {
            printf ("Уравнение не имеет решений (c != 0, а старшие коэффициенты равны нулю).\n");
        }
        else {
            square_solver_roots (a, b, c, &x1, &x2);
            if (fabs(x1 - x2) < eps)
                printf ("Корень квадратного уравнения %.1lfx^2 + %.1lfx + %.1lf = 0   x = %.2lf\n", a, b, c, x2);
            else
                printf ("Корни квадратного уравнения %.1lfx^2 + %.1lfx + %.1lf = 0  -  x1 = %.2lf и x2 = %.2lf\n", a, b, c, x1, x2);
        }
        char choose;
        printf ("Если хотите продолжить нажмите y/Y , если хотите закончить нажмите n/N\n");
        scanf (" %c", &choose);
        if (choose == 'n' || choose == 'N') {
            flag = false;
        }
    }
    printf ("Программа завершенна");

    return 0;
}
void square_solver_roots(double a, double b, double c, double *x1, double *x2)
{
    double eps = 1e-12;
    double discriminant = (b * b) - (4 * a * c);
    if (discriminant >= -eps) {
        double sqrt_discriminant = sqrt(discriminant);
        *x1 = (-b - sqrt_discriminant) / (2 * a);
        *x2 = (-b + sqrt_discriminant) / (2 * a);
    }
    else {
        printf ("Корней нет (дискриминант отрицательный).\n");
        *x1 = *x2 = NAN;
    }
}

double square_solver_one_root(double b, double c)
{
    return (-c) / b;
}
