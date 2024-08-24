#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#include "header.h"


enum type_equation {
 incomp_equat = 6 ,
 full_equat
};





const double EPS = 1e-12;

void input_coeff(double* a , double* b , double* c)
{
    char ch = 0;

    printf ("Эта программа решает квадратное уравнение\n");

    while (true) {

        printf ("Введите значения коэффицентов \nквадратного уравнения ax^2 + bx + c (a,b,c):");

        if ((scanf ("%lf %lf %lf", a, b, c)) != 3) {

            printf ("Неверные входные значения коэффицентов\n(коэффиценты могут являться только числами)\n");
            while (ch = getchar() != '\n');
        }

        else {

            while (ch = getchar() != '\n');
        }

            return ;
    }
}


_Bool is_zero (double coeff)
{
    if (fabs(coeff) <=  EPS)

        return true;

    else

        return false;
}


n_roots check_discriminant (coeffs coef)
{
    double discriminant = (coef.b * coef.b) - (4 * coef.a * coef.c);

    if (is_zero (discriminant))

        return bool_zero_discr;

    else if (discriminant > 0)

        return bool_pos_discr;

    else /* (discriminant < 0) */

        return bool_neg_discr;
}


n_roots choose_type_equation (coeffs coef)
{
    if (is_zero (coef.a)) {
        if (!is_zero (coef.b) /*&& !is_zero (coef.c)*/)

            return line_roots;

        else if (is_zero (coef.b) && is_zero (coef.c))

            return infinit_roots;

        else /* if (is_zero (coef.b) && !is_zero (coef.c)) */

            return no_roots;
    }

    else

        return check_discriminant (coef);

}


n_roots calculate_roots (coeffs coef , double* x1 , double* x2)
{
    double discriminant = (coef.b * coef.b) - (4 * coef.a * coef.c);

    n_roots check = choose_type_equation (coef);

    *x1 = check;
    *x2 = check;

    switch (check) {

        case line_roots:

            if (coef.c !=0 )

                *x1 = (-coef.c) / coef.b;

            else if (coef.c == 0)

                *x1 = (coef.c) / coef.b;


            break;

        case bool_pos_discr:
        {
            double sqrt_discriminant = sqrt (discriminant);

            *x1 = (-coef.b - sqrt_discriminant) / (2 * coef.a);
            *x2 = (-coef.b + sqrt_discriminant) / (2 * coef.a);

            break;
        }

        case bool_zero_discr:

            *x1 = (-coef.b) / (2 * coef.a);

            break;

        case bool_neg_discr:
        case infinit_roots:
        case no_roots:

        default :

            break;
    }

    return check;
}



void output (coeffs coef , roots* root , n_roots check)
{


    switch (check) {

    case line_roots:

        printf ("Корень линейного уравнения %.1lfx + %.1lf=0   x = %.2lf\n", coef.b, coef.c, root->x1);

        break;

    case infinit_roots:

        printf ("Уравнение имеет бесконечно много решений (все коэффициенты равны нулю).\n");

        break;

    case no_roots:

        printf ("Уравнение не имеет решений (c != 0, а старшие коэффициенты равны нулю).\n");

        break;

    case incomp_equat:

        printf ("Корень квадратного уравнения %.1lfx^2 + %.1lfx + %.1lf = 0 111   x = %.2lf\n", coef.a, coef.b, coef.c, root->x2);

        break;

    case bool_pos_discr:

        printf ("Корни квадратного уравнения %.1lfx^2 + %.1lfx + %.1lf = 0  -  x1 = %.2lf и x2 = %.2lf\n", coef.a, coef.b, coef.c, root->x1, root->x2);

        break;

    case bool_neg_discr:

        printf ("Корни квадратного уравнения %.1lfx^2 + %.1lfx + %.1lf = 0  -  x1 = nan и x2 = nan\n", coef.a, coef.b, coef.c);

        printf ("Корней нет (дискриминант отрицательный).\n");

        break;

    case bool_zero_discr:

        printf ("Корень квадратного уравнения %.1lfx^2 + %.1lfx + %.1lf = 0  -  x1 = %.2lf \n", coef.a, coef.b, coef.c, root->x1);

        break;

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

        else if ( choose == 'n' || choose == 'N') {

            return false;
        }

    }
}


void SolveSquare (coeffs coef , roots* root)
{
    bool flag = true;

    while (flag) {

        input_coeff (&coef.a , &coef.b , &coef.c);
        n_roots check = calculate_roots (coef , &root->x1 , &root->x2);
        output (coef , root , check);
        flag = continue_entering ();
    }

    printf ("Программа завершенна\n");

}
