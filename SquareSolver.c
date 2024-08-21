#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// define?
// enum
#define line_roots -5
#define no_roots -1
#define infinit_roots -2
#define same_roots -3
#define two_roots -4
#define bool_line 1
#define bool_infinit 2
#define bool_same 3
#define bool_two 4
#define bool_no 5
#define bool_pos_discr 6
#define bool_neg_discr 7



/// Хочу сделать очистку буфера
int odds_processing(double a, double b, double c);
int solve_square_equation (double a, double b, double c);
void output (double* root , double* x1 , double* x2 ,double a, double b, double c );
_Bool continue_entering (void);
void input_coeff(double* a , double* b , double* c);
int is_zero (double a , double b , double c);


int main (void)
{
    double a=0, b=0, c=0;
    double x1=0 , x2=0 , root=0;
    bool flag=true;
    while(flag) {
        input_coeff(&a , &b , &c);
        odds_processing(a , b , c);
        output(&root , &x1 , &x2 , a , b , c);
        flag = continue_entering ();
    }
    printf ("Программа завершенна");

    return 0;
}




void input_coeff(double* a , double* b , double* c)
{
    printf ("Эта программа решает квадратное уравнение\n");
    while (true)
    {
        printf ("Введите значения коэффицентов \nквадратного уравнения ax^2 + bx + c (a,b,c):");
        if (scanf ("%lf %lf %lf", a, b, c) != 3) {
            printf ("Неверные входные значения коэффицентов\n(коэффиценты могут являться только числами)\n");
            while (getchar() != '\n');
            continue;
        }
        else
            return ;
    }
}

int is_zero (double a , double b , double c)
{
    double eps=1e-12;
    if (fabs(a) <= eps) {
        if (fabs(b) > 0 )
            return bool_line;
        else if (fabs(b) <= eps && fabs(c) <= eps)
            return bool_infinit;
        else if (fabs(b) <= eps && fabs(c) > eps)
            return bool_no;
    }
    return 0;
}

int solve_square_equation (double a, double b, double c)
{
    double eps = 1e-12;
    double discriminant = (b * b) - (4 * a * c);
    if (discriminant >= -eps) {
        return bool_pos_discr;
    }
    else {
        return bool_neg_discr;
    }
}



int odds_processing (double a, double b, double c)
{
    if (is_zero (a , b , c) == bool_line)
        return line_roots;
    else if (is_zero (a , b , c) == bool_infinit)
        return infinit_roots;
    else if (is_zero (a , b , c)== bool_no)
        return no_roots;
    else if (solve_square_equation (a , b , c) == bool_pos_discr)
        return  bool_pos_discr;
    else if (solve_square_equation (a , b , c) == bool_pos_discr)
        return bool_pos_discr;

}


void output (double* root , double* x1 , double* x2 , double a , double b , double c)
{
    double eps = 1e-12;
    double discriminant = (b * b) - (4 * a * c);
    int check = odds_processing (a , b , c);
    switch (check) {
    case line_roots:
        *root==(-c)/b;
        printf ("Корень линейного уравнения %.1lfx + %.1lf=0   x = %.2lf\n", b, c, *root);
        break;
    case infinit_roots:
        printf ("Уравнение имеет бесконечно много решений (все коэффициенты равны нулю).\n");
        break;
    case no_roots:
        printf ("Уравнение не имеет решений (c != 0, а старшие коэффициенты равны нулю).\n");
        break;
    case bool_pos_discr:
        double sqrt_discriminant = sqrt(discriminant);
        *x1 = (-b - sqrt_discriminant) / (2 * a);
        *x2 = (-b + sqrt_discriminant) / (2 * a);
        if (fabs(x1 - x2) <= eps)
            printf ("Корень квадратного уравнения %.1lfx^2 + %.1lfx + %.1lf = 0   x = %.2lf\n", a, b, c, *x2);
        else
            printf ("Корни квадратного уравнения %.1lfx^2 + %.1lfx + %.1lf = 0  -  x1 = %.2lf и x2 = %.2lf\n", a, b, c, *x1, *x2);
        break;
    case bool_neg_discr:
        *x1 = NAN;
        *x2 = NAN;
        printf ("Корни квадратного уравнения %.1lfx^2 + %.1lfx + %.1lf = 0  -  x1 = %.2lf и x2 = %.2lf\n", a, b, c, *x1, *x2);
        printf ("Корней нет (дискриминант отрицательный).\n");
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





