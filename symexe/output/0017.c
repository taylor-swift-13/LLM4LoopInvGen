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
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (((i == 0)&&(B == B@pre)&&(A == A@pre)&&(tmp == tmp@pre)) || ((i > 0) && (tmp == A_l[i-1])) ) &&
(((i == 0)&&(B == B@pre)&&(A == A@pre)&&(tmp == tmp@pre)) || ((i > 0) && (0 < i && i <= 2048) && (forall (j:Z), 0 <= j && j < i => B_l[j] == A_l[j])) ) &&
(B == B@pre) &&
(A == A@pre)
    */
  for (i = 0; i < 2048; i++) {
    tmp = A[i];
    B[i] = tmp;
  }

 /*@ A[1024] == B[1024]*/

}