

void foo(int b,int j)  
/*@ Require emp 
   Ensure emp
*/ 
    {
  int k = 100;
  int i = j;
  int n = 0;
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (((n == 0)&&(i == j@pre)&&(k == 100)&&(j == j@pre)&&(b == b@pre)) || 
                     ((n >= 0 && n <= 2*k) &&
                      ((b == 0 && i == j@pre + (n+1)/2 && j == j@pre + n/2) ||
                       (b == 1 && i == j@pre + n/2 && j == j@pre + (n+1)/2))) ) &&
(k == 100)
    */
  for( n = 0 ; n < 2*k ; n++ ) {
    if(b) {
      i++;
    } else {
      j++;
    }
    b = !b;
  }
  /*@  i ==j*/
}
