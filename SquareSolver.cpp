#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

enum quantity_roots {
 line_roots = 1,
 no_roots ,
 infinit_roots ,
 same_roots ,
 two_roots
};

enum type_equation {
 incomp_equat = 6 ,
 full_equat
};
enum checking_roots {
 bool_line = 8,
 bool_infinit ,
 bool_same ,
 bool_two ,
 bool_no
};
enum checking_discr {
 bool_pos_discr = 13,
 bool_neg_discr ,
 bool_zero_discr
};






int odds_processing(double a, double b, double c);
int check_discriminant (double a, double b, double c);
int calculate_roots (double a, double b, double c , double* root , double* x1 , double* x2 );
_Bool continue_entering (void);
void input_coeff(double* a , double* b , double* c);
_Bool is_zero (double coeff);
void output (double a, double b, double c , double root , double x1 , double x2 );


int main (void)
{
    double a=0, b=0, c=0;
    double x1=0 , x2=0 , root=0;
    bool flag=true;
    while(flag) {
        input_coeff(&a , &b , &c);
        odds_processing(a , b , c);
        output(a , b , c , root , x1 , x2);
        flag = continue_entering ();
    }
    printf ("Программа завершенна");

    return 0;
}




void input_coeff(double* a , double* b , double* c)
{
    char ch = 0;
    printf ("Эта программа решает квадратное уравнение\n");
    while (true)
    {
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
    double eps=1e-12;
    if (fabs(coeff) <= eps)
        return true;
    else
        return false;
}

int check_discriminant (double a, double b, double c)
{
    double eps = 1e-12;
    double discriminant = (b * b) - (4 * a * c);
    if (is_zero (discriminant))
        return bool_zero_discr;
    else if (discriminant > eps) {
        return bool_pos_discr;
    }
    else if (discriminant < -eps) {
        return bool_neg_discr;
    }
}



int odds_processing (double a, double b, double c)
{
    if (is_zero (a)) {
        if (!is_zero (b) && !is_zero (c))
            return line_roots;
        else if (is_zero (b) && is_zero (c))
            return infinit_roots;
        else if (is_zero (b) && !is_zero (c))
            return no_roots;
    }
    else
        return check_discriminant (a , b , c);
}

int calculate_roots (double a, double b, double c , double* root , double* x1 , double* x2)
{
    double eps = 1e-12;
    double discriminant = (b * b) - (4 * a * c);
    int check = odds_processing (a , b , c);
    switch (check) {
    case line_roots:
        *root==(-c)/b;
        return line_roots;
    case infinit_roots:
        return infinit_roots;
    case no_roots:
        return no_roots;
    case bool_pos_discr:
    {
        double sqrt_discriminant = sqrt(discriminant);
        *x1 = (-b - sqrt_discriminant) / (2 * a);
        *x2 = (-b + sqrt_discriminant) / (2 * a);
        return bool_pos_discr;
    }
    case bool_neg_discr:
        *x1 = NAN;
        *x2 = NAN;
        return bool_neg_discr;
    case bool_zero_discr:
        *x1 = (-b)/(2 * a);
        return bool_zero_discr;
    default :
        return 0;
    }





}


void output (double a, double b, double c , double root , double x1 , double x2)
{
    int check = calculate_roots (a , b , c , &root , &x1 , &x2);
    switch (check) {
    case line_roots:
        printf ("Корень линейного уравнения %.1lfx + %.1lf=0   x = %.2lf\n", b, c, root);
        break;
    case infinit_roots:
        printf ("Уравнение имеет бесконечно много решений (все коэффициенты равны нулю).\n");
        break;
    case no_roots:
        printf ("Уравнение не имеет решений (c != 0, а старшие коэффициенты равны нулю).\n");
        break;
    case incomp_equat:
            printf ("Корень квадратного уравнения %.1lfx^2 + %.1lfx + %.1lf = 0 111   x = %.2lf\n", a, b, c, x2);
            break;
    case full_equat:
        printf ("Корни квадратного уравнения %.1lfx^2 + %.1lfx + %.1lf = 0  -  x1 = %.2lf и x2 = %.2lf\n", a, b, c, x1, x2);
        break;
    case bool_neg_discr:
        printf ("Корни квадратного уравнения %.1lfx^2 + %.1lfx + %.1lf = 0  -  x1 = %.2lf и x2 = %.2lf\n", a, b, c, x1, x2);
        printf ("Корней нет (дискриминант отрицательный).\n");
        break;
    case bool_zero_discr:
        printf ("Корень квадратного уравнения %.1lfx^2 + %.1lfx + %.1lf = 0  -  x1 = %.2lf \n", a, b, c, x1);
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
        else if ( choose == 'n' || choose == 'N'){
            return false;
        }

    }
}





