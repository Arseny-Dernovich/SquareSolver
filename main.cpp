
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#include "header.h"

// assert
// argc argv - аргументы командной строки - K&R, Прата
// README markdown - google
// цветной вывод (TXlib)


const int nTests = 20;

void SolveSquare (coeffs coeff , roots* root);
void Unit_tests (const test* data , roots* root);
//------------------------------------------------------------------------------------------------------------------------------
const struct test Tests[nTests] = {                                                  // константый массив структур для номера теста , для коэффициентов квадратного уравнения
                                                                                     // и для эталонных корней

    {.num_test = 1 , {.a = 1 , .b = 2 , .c = 3} , {.x1_refer = bool_neg_discr , .x2_refer = bool_neg_discr}},

    {.num_test = 2 , {.a = 0 , .b = 0 , .c = 0} , {.x1_refer = infinit_roots , .x2_refer = infinit_roots}},

    {.num_test = 3 , {.a = 0 , .b = 0 , .c = 1} , {.x1_refer = no_roots , .x2_refer = no_roots}},

    {.num_test = 4 , {.a = 2 , .b = 3 , .c = 0} , {.x1_refer = -1.5 , .x2_refer = 0}},

    {.num_test = 5 , {.a = 1 , .b = 1 , .c = 1} , {.x1_refer = bool_neg_discr , .x2_refer = bool_neg_discr}},

    {.num_test = 6 , {.a = 1 , .b = 2 , .c = 1} , {.x1_refer = -1 , .x2_refer = bool_zero_discr}},

    {.num_test = 7 , {.a = 2 , .b = 0 , .c = -1} , {.x1_refer = (-sqrt(0.5)) , .x2_refer = sqrt(0.5)}},

    {.num_test = 8 , {.a = 0 , .b = 1 , .c = 0} , {.x1_refer = 0 , .x2_refer = line_roots}},

    {.num_test = 9 , {.a = 2 , .b = -1 ,.c =  -1} , {.x1_refer = -0.5 , .x2_refer = 1}},

    {.num_test = 10 , {.a = 1 , .b = 2 , .c = -5} , {.x1_refer = (((-2) - sqrt(24))/(2*1)) , .x2_refer = (((-2) + sqrt(24))/(2*1))}},

    {.num_test = 11 , {.a = 1.0 , .b = 2.0 , .c = 3.0} , {.x1_refer = bool_neg_discr , .x2_refer = bool_neg_discr}},

    {.num_test = 12 , {.a = 0.0 , .b = 0.0 , .c = 0.0} , {.x1_refer = 3 , .x2_refer = 3}},

    {.num_test = 13 , {.a = 0.0 , .b = 0.0 , .c = 1.0} , {.x1_refer = no_roots , .x2_refer = no_roots}},

    {.num_test = 14 , {.a = 2.0 , .b = 3.0 , .c = 0.0} , {.x1_refer = -1.5 , .x2_refer = 0}},

    {.num_test = 15 , {.a = 1.0 , .b = 1.0 , .c = 1.0} , {.x1_refer = bool_neg_discr , .x2_refer = bool_neg_discr}},

    {.num_test = 16 , {.a = 1.0 , .b = 2.0 , .c = 1.0},  {.x1_refer = -1 , .x2_refer = bool_zero_discr}},

    {.num_test = 17 , {.a = 2.0 , .b = 0.0 , .c = -1.0} , {.x1_refer = (-sqrt(0.5)) , .x2_refer = sqrt(0.5)}},

    {.num_test = 18 , {.a = 0.0 , .b = 1.0 , .c = 0.0} , {.x1_refer = 0 , .x2_refer = line_roots}},

    {.num_test = 19 , {.a = 2.0 , .b = -1.0 , .c = -1.0} , {.x1_refer = -0.5 , .x2_refer = 1}},

    {.num_test = 20 , {.a = 1.0 , .b = 2.0 , .c = -5.0} , {.x1_refer = (((-2) - sqrt(24))/(2*1)) , .x2_refer = (((-2) + sqrt(24))/(2*1))}}
};
//--------------------------------------------------------------------------------------------------------------------------------------------

int main (void)
{
    struct test tests = {};
    struct roots root = {};

    char num = 0;

    while (1) {

        printf ("Выберите , что хотите использовать\n");
        printf ("1) тестирование квадратного уравнения\n");
        printf ("2) Решение квадратного уравнения\n");
        printf ("3) Завершить\n");
        printf ("Номер : ");

        scanf (" %c" , &num);
        while (getchar() != '\n');

        if (num == '1')

            Unit_tests (Tests , &root);

        else if (num == '2')

            SolveSquare (tests.coeff , &root);

        else if (num =='3') {

            printf("Конец :(");

            return 0;
        }

        else

            printf("Неверное значение , выберите либо 1 либо 2 и 3 для завершения : ");
    }


    return 0;
}








