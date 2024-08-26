#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#include "header.h"

void output_number_Errors (const test* data , roots* root);
n_roots choose_type_equation (coeffs coeff);
n_roots calculate_roots (coeffs coeff , double* x1 , double* x2);
int Find_Error_Zero_discr (coeffs coeff , refer ref ,  roots* root , int num_test);
int Find_Error_Pos_discr (coeffs coeff , refer ref ,  roots* root , int num_test);
int Find_Error_Neg_discr (coeffs coeff , refer ref ,  roots* root , int num_test);
int Find_Error_Line_roots (coeffs coeff , refer ref ,  roots* root , int num_test);
int Find_Error_Infinit_roots (coeffs  coeff , refer ref ,  roots* root , int num_test);
int Find_Error_No_roots (coeffs coeff , refer ref ,  roots* root , int num_test);
_Bool compare_roots (double* x , double x_verief);


enum check_Error {
 No_Error ,
 Error
};

const int nTests = 20;

const double EPS = 1e-12;






void Unit_tests (const test* data , roots* root)                                                     // функция тестирования квадратного уравнения
{
    output_number_Errors (data , root);
}
//=======================================================

int unit_test (test tests , roots* root)
{
    n_roots choose ;

    calculate_roots (tests.coeff , &root->x1 , &root->x2);

    choose = choose_type_equation (tests.coeff);

    switch (choose) {

        case line_roots:

            return Find_Error_Line_roots (tests.coeff , tests.roots_ref , root , tests.num_test );

        case bool_pos_discr:

            return Find_Error_Pos_discr (tests.coeff , tests.roots_ref , root , tests.num_test);

        case bool_zero_discr:

            return Find_Error_Zero_discr (tests.coeff , tests.roots_ref , root , tests.num_test);

        case infinit_roots:

            return Find_Error_Infinit_roots (tests.coeff , tests.roots_ref , root , tests.num_test);

        case no_roots:

            return Find_Error_No_roots (tests.coeff , tests.roots_ref , root , tests.num_test);

        case bool_neg_discr:

            return Find_Error_Neg_discr (tests.coeff , tests.roots_ref , root , tests.num_test);

        default :

            return 0;
    }
}
//----------------------------------------------------------------------------------------------------



void output_Error (coeffs coeff , int num_test)                                                        // функция вывода в случае неравнества эталонных корней с вычисленными
{
    printf ("\nError test %d :\nкорни уравнения %.1lfx^2 + %.1lfx + %.1lf  не совпадают\n", num_test , coeff.a , coeff.b , coeff.c);
}
//-----------------------------------------------------------------------------------------------------------------------------------

void output_line_zeroDis (refer ref , double* x1)                                                      // функция вывода в случае линейного уравнения и уравнения с нулевым дискриминантом
{
    printf ("Эталонный корень : x_refer = %.2lf" , ref.x1_refer);
    printf ("        Вычисленный корень : x = %.2lf\n" , *x1);
}
//----------------------------------------------------------------

void output_posDis (refer ref, double* x1 , double* x2)                                                // функция вывода в случае положительного уравнения
{
    printf ("Эталонные корни : data.x1_refer = %.2lf и data.x2_refer = %.2lf" , ref.x1_refer , ref.x2_refer);
    printf ("        Вычисленные корни : x1 = %.2lf и x2 = %.2lf\n" , *x1 , *x2);
}
//-------------------------------------------------------------------------------------------------------------

void output_posDis_zeroDis_line (coeffs coeff , int num_test)                                          // функция вывода в случае положительного и нулевого дискриминанта и линейного уравнения
{
    printf ("\nTest %d :\nОшибок нет , корни уравнения %.1lfx^2 + %.1lfx + %.1lf совпадают\n", num_test , coeff.a , coeff.b , coeff.c);
}
//---------------------------------------------------------------------------------------------------------------------------------------

int Find_Error_Zero_discr (coeffs coeff , refer ref ,  roots* root , int num_test)                     // функция сравнения эталонных корней с вычисленными для случая нулевого дискриминанта
{                                                                                                      // которая возвращает 0 (No_Error) , если корни совпадают и 1 (Error) в обратном случае
    my_assert (isnan(coeff.a));
    if (compare_roots (&root->x1 , ref.x1_refer) && compare_roots (&root->x2 , ref.x2_refer)) {

        output_posDis_zeroDis_line (coeff , num_test);

        output_line_zeroDis (ref , &root->x1);

        return No_Error;
    }

    else {

        output_Error (coeff , num_test);

        output_line_zeroDis (ref , &root->x1);

        return Error;
    }


}
//------------------------------------------------------------------------------------------------

int Find_Error_Pos_discr (coeffs coeff , refer ref ,  roots* root , int num_test)                     // функция сравнения эталонных корней с вычисленными для случая положительного дискрминанта
{                                                                                                     // которая возвращает 0 (No_Error) , если корни совпадают и 1 (Error) в обратном случае
    my_assert (isnan(coeff.a));
    my_assert (isnan(coeff.b));
    my_assert (isnan(coeff.c));

    if (compare_roots (&root->x1 , ref.x1_refer) && compare_roots (&root->x2 , ref.x2_refer)) {

        output_posDis_zeroDis_line (coeff , num_test);

        output_posDis (ref , &root->x1 , &root->x2);

        return No_Error;
    }

    else {

        output_Error (coeff , num_test);

        output_posDis (ref , &root->x1 , &root->x2);

        return Error;
    }


}
//------------------------------------------------------------------------------------------------

int Find_Error_Neg_discr (coeffs coeff , refer ref ,  roots* root , int num_test)                   // функция сравнения эталонных корней с вычисленными для случая отрицательного дискриминанта
{                                                                                                   // которая возвращает 0 (No_Error) , если корни совпадают и 1 (Error) в обратном случае
    my_assert (isnan(coeff.a));
    my_assert (isnan(coeff.a));
    my_assert (isnan(coeff.b));
    my_assert (isnan(coeff.c));

    if (compare_roots (&root->x1 , ref.x1_refer) && compare_roots (&root->x2 , ref.x2_refer)) {

        printf ("\nTest %d :\nОшибок нет , корни уравнения %.1lfx^2 + %.1lfx + %.1lf совпадают и являются мнимыми\n", num_test , coeff.a , coeff.b , coeff.c);

        return No_Error;
    }

    else {

        output_Error (coeff , num_test);

        return Error;
    }


}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------

int Find_Error_Line_roots (coeffs coeff , refer ref ,  roots* root , int num_test)                 // функция сравнения эталонных корней с вычисленными для случая линейного уравнения
{                                                                                                  // которая возвращает 0 (No_Error) , если корни совпадают и 1 (Error) в обратном случае
    my_assert (isnan(coeff.a));
    my_assert (isnan(coeff.a));
    my_assert (isnan(coeff.b));
    my_assert (isnan(coeff.c));

    if (compare_roots (&root->x1 , ref.x1_refer) && compare_roots (&root->x2 , ref.x2_refer)) {

        output_posDis_zeroDis_line (coeff , num_test);

        output_line_zeroDis (ref , &root->x1);

        return No_Error;
    }

    else {

        output_Error (coeff , num_test);

        output_line_zeroDis (ref , &root->x1);

        return Error;
    }
}
//--------------------------------------------------------------------------------------------------

int Find_Error_Infinit_roots (coeffs  coeff , refer ref ,  roots* root , int num_test)            // функция сравнения эталонных корней с вычисленными для случая линейного уравнения с бесконечным количестом решений
{                                                                                                 // которая возвращает 0 (No_Error) , если корни совпадают и 1 (Error) в обратном случае
    my_assert (isnan(coeff.a));
    my_assert (isnan(coeff.a));
    my_assert (isnan(coeff.b));
    my_assert (isnan(coeff.c));

    if (compare_roots (&root->x1 , ref.x1_refer) && compare_roots (&root->x2 , ref.x2_refer)) {

        printf ("\nTest %d :\nОшибок нет , в уравнении %.1lfx^2 + %.1lfx + %.1lf\nв обоих случаях бесконечное кол-во корней\n", num_test , coeff.a , coeff.b , coeff.c);

        return No_Error;
    }

    else {
        output_Error (coeff , num_test);

        return Error;
    }

}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int Find_Error_No_roots (coeffs coeff , refer ref ,  roots* root , int num_test)                // функция сравнения эталонных корней с вычисленными для случая линейного уравнения , неимеющего решений
{                                                                                               // которая возвращает 0 (No_Error) , если корни совпадают и 1 (Error) в обратном случае
    my_assert (isnan(coeff.a));
    my_assert (isnan(coeff.a));
    my_assert (isnan(coeff.b));
    my_assert (isnan(coeff.c));

    if (compare_roots (&root->x1 , ref.x1_refer) && compare_roots (&root->x2 , ref.x2_refer)) {

        printf ("\nTest %d :\nОшибок нет , в уравнении %.1lfx^2 + %.1lfx + %.1lf\nв обоих случаях нет корней\n", num_test , coeff.a , coeff.b , coeff.c);

        return No_Error;
    }

    else {
        output_Error (coeff , num_test);

        return Error;
    }

}
//------------------------------------------------------------------------------------------------------------------------------------------------------------

int count_number_Errors (const test* data , roots* root)                                         // функция подсчёта ошибочных тестов
{
    int amount_Errors = 0;

    for (int i = 0 ; i < nTests ; i++)

        amount_Errors += unit_test (data[i] , root);

    return amount_Errors;
}
//-------------------------------------------------------

void output_number_Errors (const test* data , roots* root)                                     // функция вывода количества ошибок
{
    printf ("\nКоличество ошибок - %d\n\n" , count_number_Errors (data , root));
}
//------------------------------------------------------------------------------

_Bool compare_roots (double* x , double x_verief)                                              // функция сравнения на равенство двух чисел с плавающей запятой
{
    return (fabs (*x - x_verief) <= EPS);
}
