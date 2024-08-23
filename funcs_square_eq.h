void Unit_tests (test_values* data);
int unit_test (test_values data);
int choose_type_equation(test_values data);
int check_discriminant (test_values data);
int calculate_roots (test_values data , double* x1 , double* x2 );
int Find_Error_Line_roots (test_values data , double x1 , double x2);
int Find_Error_Infinit_roots (test_values data , double x1 , double x2);
int Find_Error_No_roots (test_values data , double x1 , double x2);
int Find_Error_Zero_discr (test_values data , double x1 , double x2);
int Find_Error_Pos_discr (test_values data , double x1 , double x2);
int Find_Error_Neg_discr (test_values data , double x1 , double x2);
_Bool compare_roots (double x , double x_verief);
_Bool is_zero (double coeff);
void output_Error (test_values data);
void output_line_zeroDis (test_values data , double x1);
void output_posDis (test_values data , double x1 , double x2);
void output_posDis_zeroDis_line ();
int count_number_Errors (test_values* data);
void output_number_Errors (test_values* data);

void  my_assert (bool condition)
{
        if (condition == false) {
            printf ("Assertaion Error : file  %s , line %d" , __FILE__ , __LINE__);
            abort ();
        }

        else
            return;
}




_Bool is_zero (double coeff)
{
    if (fabs(coeff) <=  EPS)
        return true;

    else
        return false;
}


int check_discriminant (test_values data)
{
    double discriminant = (data.b * data.b) - (4 * data.a * data.c);

    if (is_zero (discriminant))
        return bool_zero_discr;

    else if (discriminant > 0)
        return bool_pos_discr;

    else if (discriminant < 0)
        return bool_neg_discr;

    return 0;
}


int choose_type_equation (test_values data)
{
    if (is_zero (data.a)) {
        if (!is_zero (data.b) && !is_zero (data.c))
            return line_roots;

        else if (is_zero (data.b) && is_zero (data.c))
            return infinit_roots;

        else if (is_zero (data.b) && !is_zero (data.c))
            return no_roots;

        return 0;
    }

    else
        return check_discriminant (data);

}


int calculate_roots (test_values data , double* x1 , double* x2)
{
    double discriminant = (data.b * data.b) - (4 * data.a * data.c);

    int check = choose_type_equation (data);

    *x1 = check;
    *x2 = check;

    switch (check) {

        case line_roots:
            *x1 = (-data.c) / data.b;

            break;

        case bool_pos_discr:
        {
            double sqrt_discriminant = sqrt (discriminant);
            *x1 = (-data.b - sqrt_discriminant) / (2 * data.a);
            *x2 = (-data.b + sqrt_discriminant) / (2 * data.a);

            break;
        }

        case bool_zero_discr:
            *x1 = (-data.b) / (2 * data.a);

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


void output_Error (test_values data)
{
    printf ("\nError test %d :\nкорни уравнения %.1lfx^2 + %.1lfx + %.1lf  не совпадают\n",data.num_test , data.a , data.b , data.c);
}


void output_line_zeroDis (test_values data , double x1)
{
    printf ("Эталонный корень : x_refer = %.2lf" , data.x1_refer);
    printf ("        Вычисленный корень : x = %.2lf\n" , x1);
}


void output_posDis (test_values data , double x1 , double x2)
{
    printf ("Эталонные корни : data.x1_refer = %.2lf и data.x2_refer = %.2lf" , data.x1_refer , data.x2_refer);
    printf ("        Вычисленные корни : x1 = %.2lf и x2 = %.2lf\n" , x1 , x2);
}


void output_posDis_zeroDis_line (test_values data)
{
    printf ("\nTest %d :\nОшибок нет , корни уравнения %.1lfx^2 + %.1lfx + %.1lf совпадают\n", data.num_test , data.a , data.b , data.c);
}



int Find_Error_Zero_discr (test_values data , double x1 , double x2)
{
    if (compare_roots (x1 , data.x1_refer) && compare_roots (x2 , data.x2_refer)) {
        output_posDis_zeroDis_line (data);
        output_line_zeroDis (data , x1);

        return No_Error;
    }

    else {
        output_Error (data);
        output_line_zeroDis (data , x1);

        return Error;
    }


}

int Find_Error_Pos_discr (test_values data , double x1 , double x2)
{
    if (compare_roots (x1 , data.x1_refer) && compare_roots (x2 , data.x2_refer)) {
        output_posDis_zeroDis_line (data);
        output_posDis (data , x1 , x2);

        return No_Error;
    }

    else {
        output_Error (data);
        output_posDis (data , x1 , x2);

        return Error;
    }


}


int Find_Error_Neg_discr (test_values data , double x1 , double x2)
{
    if (compare_roots (x1 , data.x1_refer) && compare_roots (x2 , data.x2_refer)) {
        printf ("\nTest %d :\nОшибок нет , корни уравнения %.1lfx^2 + %.1lfx + %.1lf совпадают и являются мнимыми\n", data.num_test , data.a , data.b , data.c);

        return No_Error;
    }

    else {
        output_Error (data);

        return Error;
    }


}


int Find_Error_Line_roots (test_values data , double x1 , double x2)
{
    if (compare_roots (x1 , data.x1_refer) && compare_roots (x2 , data.x2_refer)) {
        output_posDis_zeroDis_line (data);
        output_line_zeroDis (data , x1);

        return No_Error;
    }

    else {
        output_Error (data);
        output_line_zeroDis (data , x1);

        return Error;
    }
}


int Find_Error_Infinit_roots (test_values data , double x1 , double x2)
{
    if (compare_roots (x1 , data.x1_refer) && compare_roots (x2 , data.x2_refer)) {
        printf ("\nTest %d :\nОшибок нет , в уравнении %.1lfx^2 + %.1lfx + %.1lf\nв обоих случаях бесконечное кол-во корней\n", data.num_test , data.a , data.b , data.c);

        return No_Error;
    }

    else {
        output_Error (data);

        return Error;
    }

}


int Find_Error_No_roots (test_values data , double x1 , double x2)
{
    if (compare_roots (x1 , data.x1_refer) && compare_roots (x2 , data.x2_refer)) {
        printf ("\nTest %d :\nОшибок нет , в уравнении %.1lfx^2 + %.1lfx + %.1lf\nв обоих случаях нет корней\n", data.num_test , data.a , data.b , data.c);

        return No_Error;
    }

    else {
        output_Error (data);

        return Error;
    }

}






int unit_test (test_values data)
{
    int choose = 0;
    double x1 = 0 , x2 = 0;

    calculate_roots (data , &x1 , &x2);
    choose = choose_type_equation (data);

    switch (choose) {

        case line_roots:

            return Find_Error_Line_roots (data , x1 , x2);

        case bool_pos_discr:

            return Find_Error_Pos_discr (data , x1 , x2);

        case bool_zero_discr:

            return Find_Error_Zero_discr (data , x1 , x2);

        case infinit_roots:

            return Find_Error_Infinit_roots (data , x1 , x2);

        case no_roots:
            return Find_Error_No_roots (data , x1 , x2);

        case bool_neg_discr:

            return Find_Error_Neg_discr (data , x1 , x2);

        default :

            return 0;
    }


}


int count_number_Errors (test_values* data)
{
    int amount_Errors = 0;
    for (int i = 0 ; i < nTests ; i++)
        amount_Errors += unit_test (tests[i]);

    return amount_Errors;
}


void output_number_Errors (test_values* data)
{
    printf ("\nКоличество ошибок - %d" , count_number_Errors (tests));
}


void Unit_tests (test_values* data)
{
    for (int i = 0 ; i < nTests ; i++)
        unit_test (tests[i]);


    output_number_Errors (tests);
}
