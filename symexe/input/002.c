#include "verification_stdlib.h"
#include "verification_list.h"
#include "int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */
void foo(int A[2048]) 
/*@
With A_l
Require store_int_array(A,2048,A_l)
Ensure emp
*/{

  int i = 0;


  for (i = 0; i < 1024; i++) {
    A[i] = i;
  }


}