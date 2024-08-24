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


enum n_roots {
 line_roots = 1 , // one_root_linear_
 no_roots , // no_roots_linear_...
 infinit_roots ,
 bool_pos_discr = 13, // two_roots
 bool_neg_discr , // no_root_square_...
 bool_zero_discr // one_root_square_
};


struct refer {
    double x1_refer , x2_refer;
};

struct roots {
    double x1 , x2;
};


struct coeffs {
    double a, b, c;
};


struct test {
    int num_test;
    coeffs coef ;
    refer roots_ref;
};


