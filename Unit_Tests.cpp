#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#include "header.h"


enum check_Error {
 No_Error ,
 Error
};

const int nTests = 20;


const double EPS = 1e-12;


int choose_type_equation (coeffs coef);
int calculate_roots (coeffs coef , double* x1 , double* x2);




_Bool compare_roots (double x , double x_verief)
{
    if (fabs (x - x_verief) <= EPS)
        return true;

    else
        return false;
}


void output_Error (coeffs coef , int num_test)
{
    printf ("\nError test %d :\nкорни уравнения %.1lfx^2 + %.1lfx + %.1lf  не совпадают\n", num_test , coef.a , coef.b , coef.c);
}


void output_line_zeroDis (refer ref , roots root)
{
    printf ("Эталонный корень : x_refer = %.2lf" , ref.x1_refer);
    printf ("        Вычисленный корень : x = %.2lf\n" , root.x1);
}


void output_posDis (refer ref, roots root)
{
    printf ("Эталонные корни : data.x1_refer = %.2lf и data.x2_refer = %.2lf" , ref.x1_refer , ref.x2_refer);
    printf ("        Вычисленные корни : x1 = %.2lf и x2 = %.2lf\n" , root.x1 , root.x2);
}


void output_posDis_zeroDis_line (coeffs coef , int num_test)
{
    printf ("\nTest %d :\nОшибок нет , корни уравнения %.1lfx^2 + %.1lfx + %.1lf совпадают\n", num_test , coef.a , coef.b , coef.c);
}



int Find_Error_Zero_discr (coeffs coef , refer ref ,  roots root , int num_test)
{
    if (compare_roots (root.x1 , ref.x1_refer) && compare_roots (root.x2 , ref.x2_refer)) {
        output_posDis_zeroDis_line (coef , num_test);
        output_line_zeroDis (ref , root);
        return No_Error;
    }

    else {
        output_Error (coef , num_test);
        output_line_zeroDis (ref , root);

        return Error;
    }


}

int Find_Error_Pos_discr (coeffs coef , refer ref ,  roots root , int num_test)
{
    if (compare_roots (root.x1 , ref.x1_refer) && compare_roots (root.x2 , ref.x2_refer)) {
        output_posDis_zeroDis_line (coef , num_test);
        output_posDis (ref , root);

        return No_Error;
    }

    else {
        output_Error (coef , num_test);
        output_posDis (ref , root);

        return Error;
    }


}


int Find_Error_Neg_discr (coeffs coef , refer ref ,  roots root , int num_test)
{
    if (compare_roots (root.x1 , ref.x1_refer) && compare_roots (root.x2 , ref.x2_refer)) {
        printf ("\nTest %d :\nОшибок нет , корни уравнения %.1lfx^2 + %.1lfx + %.1lf совпадают и являются мнимыми\n", num_test , coef.a , coef.b , coef.c);

        return No_Error;
    }

    else {
        output_Error (coef , num_test);

        return Error;
    }


}


int Find_Error_Line_roots (coeffs coef , refer ref ,  roots root , int num_test)
{
    if (compare_roots (root.x1 , ref.x1_refer) && compare_roots (root.x2 , ref.x2_refer)) {
        output_posDis_zeroDis_line (coef , num_test);
        output_line_zeroDis (ref , root);

        return No_Error;
    }

    else {
        output_Error (coef , num_test);
        output_line_zeroDis (ref , root);

        return Error;
    }
}


int Find_Error_Infinit_roots (coeffs  coef , refer ref ,  roots root , int num_test)
{
    if (compare_roots (root.x1 , ref.x1_refer) && compare_roots (root.x2 , ref.x2_refer)) {
        printf ("\nTest %d :\nОшибок нет , в уравнении %.1lfx^2 + %.1lfx + %.1lf\nв обоих случаях бесконечное кол-во корней\n", num_test , coef.a , coef.b , coef.c);

        return No_Error;
    }

    else {
        output_Error (coef , num_test);

        return Error;
    }

}


int Find_Error_No_roots (coeffs coef , refer ref ,  roots root , int num_test)
{
    if (compare_roots (root.x1 , ref.x1_refer) && compare_roots (root.x2 , ref.x2_refer)) {
        printf ("\nTest %d :\nОшибок нет , в уравнении %.1lfx^2 + %.1lfx + %.1lf\nв обоих случаях нет корней\n", num_test , coef.a , coef.b , coef.c);

        return No_Error;
    }

    else {
        output_Error (coef , num_test);

        return Error;
    }

}






int unit_test (test tests)
{
    int choose = 0;

    calculate_roots (tests.coef , &tests.root.x1 , &tests.root.x2);

    choose = choose_type_equation (tests.coef);

    switch (choose) {

        case line_roots:

            return Find_Error_Line_roots (tests.coef , tests.roots_ref , tests.root , tests.num_test );

        case bool_pos_discr:

            return Find_Error_Pos_discr (tests.coef , tests.roots_ref , tests.root , tests.num_test);

        case bool_zero_discr:

            return Find_Error_Zero_discr (tests.coef , tests.roots_ref , tests.root , tests.num_test);

        case infinit_roots:

            return Find_Error_Infinit_roots (tests.coef , tests.roots_ref , tests.root , tests.num_test);

        case no_roots:
            return Find_Error_No_roots (tests.coef , tests.roots_ref , tests.root , tests.num_test);

        case bool_neg_discr:

            return Find_Error_Neg_discr (tests.coef , tests.roots_ref , tests.root , tests.num_test);

        default :

            return 0;
    }


}


int count_number_Errors (const test* data)
{
    int amount_Errors = 0;
    for (int i = 0 ; i < nTests ; i++)
        amount_Errors += unit_test (data[i]);

    return amount_Errors;
}


void output_number_Errors (const test* data)
{
    printf ("\nКоличество ошибок - %d\n" , count_number_Errors (data));
}


void Unit_tests (const test* data)
{
    output_number_Errors (data);
}
