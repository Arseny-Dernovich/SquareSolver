#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>


#include "header.h"


void input_coeff(double* a , double* b , double* c);
n_roots calculate_roots (coeffs coeff , double* x1 , double* x2);
void output (coeffs coeff , roots* root , n_roots check);
_Bool continue_entering (void);



enum type_equation {
 incomp_equat = 6 ,
 full_equat
};

const double EPS = 1e-12;



void SolveSquare (coeffs coeff , roots* root)
{
    bool flag = true;

    while (flag) {

        input_coeff (&coeff.a , &coeff.b , &coeff.c);

        n_roots check = calculate_roots (coeff , &(root->x1) , &(root->x2));

        output (coeff , root , check);

        flag = continue_entering ();
    }

    printf ("Программа завершенна\n");
}


void input_coeff (double* a , double* b , double* c)
{
    char ch = 0;

    printf ("Эта программа решает квадратное уравнение\n");


    while (true) {

        printf ("Введите значения коэффицентов \nквадратного уравнения ax^2 + bx + c (a,b,c):");

        if ((scanf ("%lf %lf %lf", a , b , c)) != 3) {

            my_assert (isnan(*a));
            my_assert (isnan(*b));
            my_assert (isnan(*c));


            printf ("Неверные входные значения коэффицентов\n(коэффиценты могут являться только числами)\n");
            while (ch = getchar() != '\n');
        }

        else {

            my_assert (isnan(*a));
            my_assert (isnan(*b));
            my_assert (isnan(*c));

            while (ch = getchar() != '\n');


            return ;
        }
    }
}


_Bool is_zero (double coeff)
{
    return (fabs(coeff) <=  EPS);
}


n_roots check_discriminant (coeffs coeff)
{
    double discriminant = (coeff.b * coeff.b) - (4 * coeff.a * coeff.c);

    if (is_zero (discriminant))

        return bool_zero_discr;

    else if (discriminant > 0)

        return bool_pos_discr;

    else /* (discriminant < 0) */

        return bool_neg_discr;
}


n_roots choose_type_equation (coeffs coeff)
{
    if (is_zero (coeff.a)) {

        if (!is_zero (coeff.b) /*&& !is_zero (coeff.c)*/)

            return line_roots;

        else if (is_zero (coeff.b) && is_zero (coeff.c))

            return infinit_roots;

        else /* if (is_zero (coeff.b) && !is_zero (coeff.c)) */

            return no_roots;
    }

    else

        return check_discriminant (coeff);
}


n_roots calculate_roots (coeffs coeff , double* x1 , double* x2)
{
    my_assert (coeff.a == NAN);

    double discriminant = (coeff.b * coeff.b) - (4 * coeff.a * coeff.c);

    n_roots check = choose_type_equation (coeff);

    *x1 = check;
    *x2 = check;

    switch (check) {

        case line_roots:

            if (coeff.c !=0 )

                *x1 = (-coeff.c) / coeff.b;

            else if (coeff.c == 0)

                *x1 = (coeff.c) / coeff.b;


            break;

        case bool_pos_discr:
        {
            double sqrt_discriminant = sqrt (discriminant);

            *x1 = (-coeff.b - sqrt_discriminant) / (2 * coeff.a);
            *x2 = (-coeff.b + sqrt_discriminant) / (2 * coeff.a);

            break;
        }

        case bool_zero_discr:

            *x1 = (-coeff.b) / (2 * coeff.a);

            break;

        case bool_neg_discr:
        case infinit_roots:
        case no_roots:

        default :

            break;
    }

    return check;
}


void output (coeffs coeff , roots* root , n_roots check)
{
    switch (check) {

    case line_roots:

        printf ("Корень линейного уравнения %.1lfx + %.1lf = 0   x = %.2lf\n", coeff.b, coeff.c, root->x1);

        break;

    case infinit_roots:

        printf ("Уравнение имеет бесконечно много решений (все коэффициенты равны нулю).\n");

        break;

    case no_roots:

        printf ("Уравнение не имеет решений (c != 0, а старшие коэффициенты равны нулю).\n");

        break;

    case incomp_equat:

        printf ("Корень квадратного уравнения %.1lfx^2 + %.1lfx + %.1lf = 0 !!!   x = %.2lf\n", coeff.a, coeff.b, coeff.c, root->x2);

        break;

    case bool_pos_discr:

        printf ("Корни квадратного уравнения %.1lfx^2 + %.1lfx + %.1lf = 0  -  x1 = %.2lf и x2 = %.2lf\n", coeff.a, coeff.b, coeff.c, root->x1, root->x2);

        break;

    case bool_neg_discr:

        printf ("Корни квадратного уравнения %.1lfx^2 + %.1lfx + %.1lf = 0  -  x1 = nan и x2 = nan\n", coeff.a, coeff.b, coeff.c);

        printf ("Корней нет (дискриминант отрицательный).\n");

        break;

    case bool_zero_discr:

        printf ("Корень квадратного уравнения %.1lfx^2 + %.1lfx + %.1lf = 0  -  x1 = %.2lf \n", coeff.a, coeff.b, coeff.c, root->x1);

        break;

    }
}


_Bool continue_entering (void)
{
    while (true)
    {
        char choose = 0;

        printf ("Если хотите продолжить нажмите y/Y , если хотите закончить нажмите n/N\n");

        scanf (" %c" , &choose);

        while (getchar() != '\n');

        switch (choose) {

            case 'y':
            case 'Y':

                return true;

            case 'n':
            case 'N':

                return false;

            default:

                continue;
        }


    }
}



