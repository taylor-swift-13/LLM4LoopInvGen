#include "verification_stdlib.h"
#include "verification_list.h"
#include "int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */


void foo(int tmp,int * A,int *B,int n) 
/*@
With A_l B_l
Require n == 2048 && store_int_array(A,n,A_l) * store_int_array(B,n,B_l) 
Ensure emp
*/
{

  int i =0;
  for (i = 0; i < 2048; i++) {
    tmp = A[i];
    B[i] = tmp;
  }

 /*@ A[1024] == B[1024]*/

}