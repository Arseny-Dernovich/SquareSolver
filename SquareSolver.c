#include <stdio.h>
#include <stdbool.h>
#include <math.h>
double solution_linear_equation (double b, double c);
void solution_square_equation (double a, double b, double c, double *x1, double *x2);
void comparison_coefficients_with_zero_and_output (double a , double b , double c);
void solve_equation (void);
_Bool continue_entering (void);


int main (void)
{
    solve_equation ();
    printf ("Программа завершенна");

    return 0;
}




void solution_square_equation (double a, double b, double c, double *x1, double *x2)
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


double solution_linear_equation (double b, double c)
{
    return (-c) / b;
}


void comparison_coefficients_with_zero_and_output (double a , double b , double c)
{
    double eps = 1e-12;  // коэффиценты квадратного кравнения , a-старший коэффицент , b-средний , c-свободный.
    double x1, x2, root;
    if (fabs(a) <= eps && fabs(b) >= eps) {
            if (fabs(c) < eps)
                root = 0;
            else
                root = solution_linear_equation (b, c);
                printf ("Корень линейного уравнения %.1lfx + %.1lf=0   x = %.2lf\n", b, c, root);
    }
    else if (fabs(a) <= eps && fabs(b) <= eps && fabs(c) <= eps) {
        printf ("Уравнение имеет бесконечно много решений (все коэффициенты равны нулю).\n");
    }
    else if (fabs(a) <= eps && fabs(b) <= eps && fabs(c) >= eps) {
        printf ("Уравнение не имеет решений (c != 0, а старшие коэффициенты равны нулю).\n");
    }
    else {
            solution_square_equation (a, b, c, &x1, &x2);
        if (fabs(x1 - x2) <= eps)
            printf ("Корень квадратного уравнения %.1lfx^2 + %.1lfx + %.1lf = 0   x = %.2lf\n", a, b, c, x2);
        else
            printf ("Корни квадратного уравнения %.1lfx^2 + %.1lfx + %.1lf = 0  -  x1 = %.2lf и x2 = %.2lf\n", a, b, c, x1, x2);
    }
}

_Bool continue_entering (void)
{
    while (true)
    {
        char choose;
        printf ("Если хотите продолжить нажмите y/Y , если хотите закончить нажмите n/N\n");
        scanf (" %c" , &choose);
        while (getchar() != '\n')
                continue;

        if (choose == 'y' || choose == 'Y') {
            return true;
        }
        else if ( choose == 'n' || choose == 'N'){
            return false;
        }

    }
}


void solve_equation (void)
{
    double a, b, c;
    bool flag = true;
    printf ("Эта программа решает квадратное уравнение\n");
    while (flag)
        {
            printf ("Введите значения коэффицентов \nквадратного уравнения ax^2 + bx + c (a,b,c):");
            if (scanf ("%lf %lf %lf", &a, &b, &c) != 3) {
                printf ("Неверные входные значения коэффицентов\n(коэффиценты могут являться только числами)\n");
                while (getchar() != '\n');
                continue;
            }

            comparison_coefficients_with_zero_and_output (a , b , c);

            flag = continue_entering ();

        }
}


