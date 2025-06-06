
void foo(int n)  
/*@ Require n >= 0 
   Ensure emp
*/ 
    {
  int i =0;
  int sum = 0;
 
  for (i = 0; i < n; ++i){
    sum = sum + i;
  }

  /*@  sum >= 0 */
}