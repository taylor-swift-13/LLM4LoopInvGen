

int unknown()
/*@
Require emp 
Ensure __return >= 0
*/
;




void foo(int n, int flag)  
/*@ Require n > 0
   Ensure emp
*/ 
    {
  int k = 1;
  if (flag) {
    k = unknown();
  }
  int i = 0, j = 0;
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((flag@pre == 0 && n@pre > 0) => (flag == flag@pre)) &&
((flag@pre == 0 && n@pre > 0) => (n == n@pre)) &&
((k >= 0 && flag@pre != 0 && n@pre > 0) => (flag == flag@pre)) &&
((k >= 0 && flag@pre != 0 && n@pre > 0) => (n == n@pre))
    */
  while (i <= n) {
    i++;
    j += i;
  }
  int z = k + i + j;
  /*@  z > 2 * n */
}