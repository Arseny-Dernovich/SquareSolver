

#include <stdio.h>

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
    roots root ;       // test->roots.x1
    refer roots_ref ;   // test->roots_ref.x1
    int num_test;
};


