

void foo(int n)
 
/*@ Require emp 
   Ensure emp
*/ 
    {
 int k=1;
 int i=1;
 int j=0;
 

  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((1 < n@pre) => (((j == 0)&&(i == 1)&&(k == 1)&&(n == n@pre)) || (i >= 1))) &&
((1 < n@pre) => (((j == 0)&&(i == 1)&&(k == 1)&&(n == n@pre)) || (0 <= j && j <= i))) &&
((!(1 < n@pre)) => ((j == 0)&&(i == 1)&&(k == 1)&&(n == n@pre)))
    */
                while(i < n) {
  j = 0;

  /* >>> LOOP INVARIANT TO FILL <<< */
  
  /*@ Inv
    (i >= 1) &&
(0 <= j && j <= i)
    */
  
  while(j < i) {
      k += (i-j);
      j++;
  }

  i++;
 }
 /*@  k >= n */
 
}
