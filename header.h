#include <stdio.h>
#include <assert.h>

#ifndef NDEBUG

    #define my_assert(condition)                                                                    \
        if (condition == false) {                                                                   \
            printf ("Assertaion Error : "#condition" , file  %s , line %d" , __FILE__ , __LINE__);  \
            abort ();                                                                               \
        }                                                                                           \
        else;
#else

    #define my_assert(condition)

#endif


enum quantity_roots {
 line_roots = 1 ,
 no_roots ,
 infinit_roots ,
 same_roots ,
 two_roots
};


enum checking_discr {
 bool_pos_discr = 13,
 bool_neg_discr ,
 bool_zero_discr
};


struct refer {
    double x1_refer , x2_refer;
};

struct roots {
    double x1 , x2; };


//void Unit_tests (const test_values* data);
//void SolveSquare ();



struct coeffs {
    double a, b, c;
};

struct test {
    coeffs coef ;       // test->coef.a
    refer roots_ref ;   // test->roots_ref.x1
    int num_test;
};


