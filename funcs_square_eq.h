void Unit_tests (void);
int unit_test (test_values data);
int choose_type_equation(double a, double b, double c);
int check_discriminant (double a, double b, double c);
int calculate_roots (double a, double b, double c , double* x1 , double* x2 );
int Line_roots (int num_test , double a , double b , double c , double x1_refer , double x2_refer , double x1 , double x2);
int Infinit_roots (int num_test , double a , double b , double c , double x1_refer , double x2_refer , double x1 , double x2);
int No_roots (int num_test , double a , double b , double c , double x1_refer , double x2_refer , double x1 , double x2);
int Zero_discr (int num_test , double a , double b , double c , double x1_refer , double x2_refer , double x1 , double x2);
int Pos_discr (int num_test , double a , double b , double c , double x1_refer , double x2_refer , double x1 , double x2);
int Neg_discr (int num_test , double a , double b , double c , double x1_refer , double x2_refer , double x1 , double x2);
_Bool compare_roots (double x , double x_verief);
_Bool is_zero (double coeff);
void output_Error (int num_test , double a , double b , double c);
void output_line_zeroDis (double x1_refer , double x1);
void output_posDis (double x1_refer , double x2_refer , double x1 , double x2);
void output_posDis_zeroDis_line (int num_test , double a , double b , double c);
int count_number_Errors (void);
void output_number_Errors (void);




_Bool is_zero (double coeff)
{
    if (fabs(coeff) <=  EPS)
        return true;

    else
        return false;
}


int check_discriminant (double a, double b, double c)
{
    double discriminant = (b * b) - (4 * a * c);

    if (is_zero (discriminant))
        return bool_zero_discr;

    else if (discriminant > 0)
        return bool_pos_discr;

    else if (discriminant < 0)
        return bool_neg_discr;

    return 0;
}


int choose_type_equation (double a, double b, double c)
{
    if (is_zero (a)) {
        if (!is_zero (b) && !is_zero (c))
            return line_roots;

        else if (is_zero (b) && is_zero (c))
            return infinit_roots;

        else if (is_zero (b) && !is_zero (c))
            return no_roots;

        return 0;
    }

    else
        return check_discriminant (a , b , c);

}


int calculate_roots (double a, double b, double c , double* x1 , double* x2)
{
    double discriminant = (b * b) - (4 * a * c);

    int check = choose_type_equation (a , b , c);

    *x1 = check;
    *x2 = check;

    switch (check) {

        case line_roots:
            *x1 = (-c) / b;

            break;

        case bool_pos_discr:
        {
            double sqrt_discriminant = sqrt (discriminant);
            *x1 = (-b - sqrt_discriminant) / (2 * a);
            *x2 = (-b + sqrt_discriminant) / (2 * a);

            break;
        }

        case bool_zero_discr:
            *x1 = (-b) / (2 * a);

            break;

        case infinit_roots:
        case no_roots:
        case bool_neg_discr:

        default :

            break;
    }

    return check;
}


_Bool compare_roots (double x , double x_verief)
{
    if (fabs (x - x_verief) <= EPS)
        return true;

    else
        return false;
}


void output_Error (int num_test , double a , double b , double c)
{
    printf ("\nError test %d :\nкорни уравнения %.1lfx^2 + %.1lfx + %.1lf  не совпадают\n",num_test , a , b , c);
}


void output_line_zeroDis (double x1_refer , double x1)
{
    printf ("Эталонный корень : x_refer = %.2lf" , x1_refer);
    printf ("        Вычисленный корень : x = %.2lf\n" , x1);
}


void output_posDis (double x1_refer , double x2_refer , double x1 , double x2)
{
    printf ("Эталонные корни : x1_refer = %.2lf и x2_refer = %.2lf" , x1_refer , x2_refer);
    printf ("        Вычисленные корни : x1 = %.2lf и x2 = %.2lf\n" , x1 , x2);
}


void output_posDis_zeroDis_line (int num_test , double a , double b , double c)
{
    printf ("\nTest %d :\nОшибок нет , корни уравнения %.1lfx^2 + %.1lfx + %.1lf совпадают\n", num_test , a , b , c);
}



int Zero_discr (int num_test , double a , double b , double c , double x1_refer , double x2_refer , double x1 , double x2)
{
    if (compare_roots (x1 , x1_refer) && compare_roots (x2 , x2_refer)) {
        output_posDis_zeroDis_line (num_test , a , b , c);
        output_line_zeroDis (x1_refer , x1);

        return No_Error;
    }

    else {
        output_Error (num_test , a , b , c);
        output_line_zeroDis (x1_refer , x1);

        return Error;
    }


}

int Pos_discr (int num_test , double a , double b , double c , double x1_refer , double x2_refer , double x1 , double x2)
{
    if (compare_roots (x1 , x1_refer) && compare_roots (x2 , x2_refer)) {
        output_posDis_zeroDis_line (num_test , a , b , c);
        output_posDis (x1_refer , x2_refer , x1 , x2);

        return No_Error;
    }

    else {
        output_Error (num_test , a , b , c);
        output_posDis (x1_refer , x2_refer , x1 , x2);

        return Error;
    }


}


int Neg_discr (int num_test , double a , double b , double c , double x1_refer , double x2_refer , double x1 , double x2)
{
    if (compare_roots (x1 , x1_refer) && compare_roots (x2 , x2_refer)) {
        printf ("\nTest %d :\nОшибок нет , корни уравнения %.1lfx^2 + %.1lfx + %.1lf совпадают и являются мнимыми\n", num_test , a , b , c);

        return No_Error;
    }

    else {
        output_Error (num_test , a , b , c);

        return Error;
    }


}


int Line_roots (int num_test , double a , double b , double c , double x1_refer , double x2_refer , double x1 , double x2)
{
    if (compare_roots (x1 , x1_refer) && compare_roots (x2 , x2_refer)) {
        output_posDis_zeroDis_line (num_test , a , b , c);
        output_line_zeroDis (x1_refer , x1);

        return No_Error;
    }

    else {
        output_Error (num_test , a , b , c);
        output_line_zeroDis (x1_refer , x1);

        return Error;
    }
}


int Infinit_roots (int num_test , double a , double b , double c , double x1_refer , double x2_refer , double x1 , double x2)
{
    if (compare_roots (x1 , x1_refer) && compare_roots (x2 , x2_refer)) {
        printf ("\nTest %d :\nОшибок нет , в уравнении %.1lfx^2 + %.1lfx + %.1lf\nв обоих случаях бесконечное кол-во корней\n", num_test , a , b , c);

        return No_Error;
    }

    else {
        output_Error (num_test , a , b , c);

        return Error;
    }

}


int No_roots (int num_test , double a , double b , double c , double x1_refer , double x2_refer , double x1 , double x2)
{
    if (compare_roots (x1 , x1_refer) && compare_roots (x2 , x2_refer)) {
        printf ("\nTest %d :\nОшибок нет , в уравнении %.1lfx^2 + %.1lfx + %.1lf\nв обоих случаях нет корней\n", num_test , a , b , c);

        return No_Error;
    }

    else {
        output_Error (num_test , a , b , c);

        return Error;
    }

}






int unit_test (test_values data)
{
    int choose = 0;
    double x1 = 0 , x2 = 0;

    calculate_roots ( data.a , data.b , data.c , &x1 , &x2);
    choose = choose_type_equation (data.a , data.b , data.c);

    switch (choose) {

        case line_roots:

            return Line_roots (data.num_test , data.a , data.b , data.c , data.x1_refer , data.x2_refer , x1 , x2);

        case bool_pos_discr:

            return Pos_discr (data.num_test , data.a , data.b , data.c ,data. x1_refer , data.x2_refer , x1 , x2);

        case bool_zero_discr:

            return Zero_discr (data.num_test , data.a , data.b , data.c , data.x1_refer , data.x2_refer , x1 , x2);

        case infinit_roots:

            return Infinit_roots (data.num_test , data.a , data.b , data.c , data.x1_refer , data.x2_refer , x1 , x2);

        case no_roots:
            return No_roots (data.num_test , data.a , data.b , data.c , data.x1_refer , data.x2_refer , x1 , x2);

        case bool_neg_discr:

            return Neg_discr (data.num_test , data.a , data.b , data.c , data.x1_refer , data.x2_refer , x1 , x2);

        default :

            return 0;
    }


}


int count_number_Errors (void)
{
    int amount_Errors = unit_test (test1)
                        +
                        unit_test (test2)
                        +
                        unit_test (test3)
                        +
                        unit_test (test4)
                        +
                        unit_test (test5)
                        +
                        unit_test (test6)
                        +
                        unit_test (test7)
                        +
                        unit_test (test8)
                        +
                        unit_test (test9)
                        +
                        unit_test (test10)
                        +
                        unit_test (test11)
                        +
                        unit_test (test12)
                        +
                        unit_test (test13)
                        +
                        unit_test (test14)
                        +
                        unit_test (test15)
                        +
                        unit_test (test16)
                        +
                        unit_test (test17)
                        +
                        unit_test (test18)
                        +
                        unit_test (test19)
                        +
                        unit_test (test20);

    return amount_Errors;
}


void output_number_Errors (void)
{
    printf ("\nКоличество ошибок - %d" , count_number_Errors ());
}


void Unit_tests (void)
{
    unit_test (test1);
    unit_test (test2);
    unit_test (test3);
    unit_test (test4);
    unit_test (test5);
    unit_test (test6);
    unit_test (test7);
    unit_test (test8);
    unit_test (test9);
    unit_test (test10);
    unit_test (test11);
    unit_test (test12);
    unit_test (test13);
    unit_test (test14);
    unit_test (test15);
    unit_test (test16);
    unit_test (test17);
    unit_test (test18);
    unit_test (test19);
    unit_test (test20);

    output_number_Errors ();
}
