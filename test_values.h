enum quantity_roots {
 line_roots = 1 ,
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

enum check_Error {
 No_Error ,
 Error
};


const double EPS = 1e-12;

const int nTests = 20;


struct test_values {
    double a , b , c;
    double x1_refer , x2_refer;
    int num_test;
};

struct test_values tests[nTests] = {
    {.a = 1 , .b = 2 , .c = 3 , .x1_refer = 1 , .x2_refer = 1 , .num_test = 1},
    {.a = 0 , .b = 0 , .c = 0 , .x1_refer = infinit_roots , .x2_refer = infinit_roots , .num_test = 2},
    {.a = 0 , .b = 0 , .c = 1 , .x1_refer = no_roots , .x2_refer = no_roots , .num_test = 3},
    {.a = 2 , .b = 3 , .c = 0 , .x1_refer = -1.5 , .x2_refer = 0 , .num_test = 4},
    {.a = 1 , .b = 1 , .c = 1 , .x1_refer = bool_neg_discr , .x2_refer = bool_neg_discr , .num_test = 5},
    {.a = 1 , .b = 2 , .c = 1 , .x1_refer = -1 , .x2_refer = bool_zero_discr , .num_test = 6},
    {.a = 2 , .b = 0 , .c = -1 , .x1_refer = (-sqrt(0.5)) , .x2_refer = sqrt(0.5) , .num_test = 7},
    {.a = 0 , .b = 1 , .c = 0 , .x1_refer = line_roots , .x2_refer = line_roots , .num_test = 8},
    {.a = 2 , .b = -1 ,.c =  -1 , .x1_refer = -0.5 , .x2_refer = 1 , .num_test = 9},

    {.a = 1 , .b = 2 , .c = -5 , .x1_refer = (((-2) - sqrt(24))/(2*1)) , .x2_refer = (((-2) + sqrt(24))/(2*1)) , .num_test = 10},



    {.a = 1.0 , .b = 2.0 , .c = 3.0 , .x1_refer = 1 , .x2_refer = 1 , .num_test = 11},

    {.a = 0.0 , .b = 0.0 , .c = 0.0 , .x1_refer = 3 , .x2_refer = 3 , .num_test = 12},

    {.a = 0.0 , .b = 0.0 , .c = 1.0 , .x1_refer = no_roots , .x2_refer = no_roots , .num_test = 13},

    {.a = 2.0 , .b = 3.0 , .c = 0.0 , .x1_refer = -1.5 , .x2_refer = 0 , .num_test = 14},

    {.a = 1.0 , .b = 1.0 , .c = 1.0 , .x1_refer = bool_neg_discr , .x2_refer = bool_neg_discr , .num_test = 15},

    {.a = 1.0 , .b = 2.0 , .c = 1.0, .x1_refer = -1 , .x2_refer = bool_zero_discr , .num_test = 16},

    {.a = 2.0 , .b = 0.0 , .c = -1.0 , .x1_refer = 3 , .x2_refer = sqrt(0.5) , .num_test = 17},

    {.a = 0.0 , .b = 1.0 , .c = 0.0 , .x1_refer = line_roots , .x2_refer = line_roots , .num_test = 18},

    {.a = 2.0 , .b = -1.0 , .c = -1.0 , .x1_refer = -0.5 , .x2_refer = 1 , .num_test = 19},

    {.a = 1.0 , .b = 2.0 , .c = -5.0 , .x1_refer = (((-2) - sqrt(24))/(2*1)) , .x2_refer = (((-2) + sqrt(24))/(2*1)) , .num_test = 20}
};

