/* English locale */

#pragma once

#define TITLE           "Discrete math colloquium project"

#define USAGE           "Print L to get list of available modules.\n" \
                        "Print E to exit.\n" \
                        "\n" \
                        "To call module, print it name in [BLOCK][NUMBER] or [BLOCK]-[NUMBER] format.\n" \
                        "Examples: N-12, P3.\n"
                        
#define CMD_WAIT        "Command: "

#define UNEXP_SYMBOL    "Error: unexpected symbol"
#define UNEXP_EOF       "Error: unexpected end of input"
#define UNKN_CMD        "Error: unknown command or block"

#define FIRST_ARG_LN    "First argument (long natural): "
#define SECOND_ARG_LN   "Second argument (long natural): "

#define FIRST_ARG_LI    "First argument (long integer): "
#define SECOND_ARG_LI   "Second argument (long integer): "

#define FIRST_ARG_INT   "First argument (int): "
#define SECOND_ARG_INT  "Second argument (int): "

#define RESULT          "Result: "

#define TRUE            "True"
#define FALSE           "False"


/* LIST */

#define LIST_TITLE      "                           List of available modules"
#define BLOCK_N         "                           Natural numbers with zero"
#define BLOCK_Z         "                                    Integers"
#define BLOCK_Q         "                                Rational numbers"
#define BLOCK_P         "                                   Polynomials"


/* Block N */

#define N_1_DESCR   "    N-1      COMM_NN_D      Compare numbers"
#define N_2_DESCR   "    N-2      NZER_N_B       Check for zero equality"
#define N_3_DESCR   "    N-3      ADD_1N_N       Add 1"
#define N_4_DESCR   "    N-4      ADD_NN_N       Addition of numbers"
#define N_5_DESCR   "    N-5      SUB_NN_N       Subtraction second from first"
#define N_6_DESCR   "    N-6      MUL_ND_N       Multiplying number by a digit"
#define N_7_DESCR   "    N-7      MUL_Nk_N       Multiplying by 10^k"
#define N_8_DESCR   "    N-8      MUL_NN_N       Product of two numbers"
#define N_9_DESCR   "    N-9      SUB_NDN_N      Subtraction second multiplied by digit from first"
#define N_10_DESCR  "    N-10     DIV_NN_Dk      First number of division"
#define N_11_DESCR  "    N-11     DIV_NN_N       Quotient from division"
#define N_12_DESCR  "    N-12     MOD_NN_N       Remainder from division"
#define N_13_DESCR  "    N-13     GCF_NN_N       Greatest common factor"
#define N_14_DESCR  "    N-14     LCM_NN_N       Least common multiple"


/* Block Z */

#define Z_1_DESCR   "    Z-1      ABS_Z_N        Absolute value"
#define Z_2_DESCR   "    Z-2      POZ_Z_D        Check if positive"
#define Z_3_DESCR   "    Z-3      MUL_ZM_Z       Multiple by (-1)"
#define Z_4_DESCR   "    Z-4      TRANS_N_Z      Transform from natural to integer"
#define Z_5_DESCR   "    Z-5      TRANS_Z_N      Transform from integer to natural"
#define Z_6_DESCR   "    Z-6      ADD_ZZ_Z       Addition of numbers"
#define Z_7_DESCR   "    Z-7      SUB_ZZ_Z       Subtraction of numbers"
#define Z_8_DESCR   "    Z-8      MUL_ZZ_Z       Product of numbers"
#define Z_9_DESCR   "    Z-9      DIV_ZZ_Z       Quotient of dividing"
#define Z_10_DESCR  "    Z-10     MOD_ZZ_Z       Remainder of dividing"
