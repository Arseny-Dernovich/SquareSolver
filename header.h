#include <stdio.h>
#include <assert.h>

#ifndef NDEBUG

    #define my_assert(condition)                                                                    \
        if (condition == true) {                                                                    \
            printf ("Assertaion Error : "#condition" , file  %s , line %d" , __FILE__ , __LINE__);  \
            abort ();                                                                               \
        }                                                                                           \
        else;
#else

    #define my_assert(condition)

#endif

// __PRETTY_FUNCTION__ __func__

enum n_roots {
 zero ,
 line_roots = 1 ,     // 1 = one_root_linear_
 no_roots ,           // 2 = no_roots_linear_...
 infinit_roots ,      // 3 =
 bool_pos_discr = 13, // two_roots
 bool_neg_discr ,     // no_root_square_...
 bool_zero_discr      // one_root_square_
};


struct refer {
    double x1_refer , x2_refer;
};

struct roots {
    double x1 , x2;
};


struct coeffs {
    double a , b , c;
};


struct test {
    int num_test;
    coeffs coeff;
    refer  roots_ref;
};


