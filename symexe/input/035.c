
void foo(int n)  
/*@ Require n > 0
   Ensure emp
*/ 
    {
  int x= 0;
  
  while(x<n) {
    x++;
  } 
  /*@  (n > 0) => (x == n) */
 
}
