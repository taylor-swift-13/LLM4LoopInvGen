
void foo(int n)  
/*@ Require n >= 0 
   Ensure emp
*/ 
    {
  int i =0;
  int sum = 0;
 
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((n@pre >= 0) => ((0 < n@pre) => (((sum == 0)&&(i == 0)&&(n == n@pre)) || (i >= 0 && i <= n))) ) &&
((n@pre >= 0) => ((0 < n@pre) => (((sum == 0)&&(i == 0)&&(n == n@pre)) || (sum == i * (i - 1) / 2))) ) &&
((n@pre >= 0) => ((!(0 < n@pre)) => ((sum == 0)&&(i == 0)&&(n == n@pre)))) &&
((n@pre >= 0) => (n == n@pre))
    */
    
  for (i = 0; i < n; ++i){
    sum = sum + i;
  }

  /*@  sum >= 0 */
}