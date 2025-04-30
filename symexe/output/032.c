
void foo(int b,int j) {
  int k = 100;
  int i = j;
  int n = 0;
  
  /* >>> LOOP INVARIANT TO FILL <<< 
     >>> PRECONDITION OF THE LOOP : (n == 0) * (i == \at(j, Pre)) * (k == 100) * (j == \at(j, Pre)) * (b == \at(b, Pre)) <<< */
  
  /*@
    loop invariant  ((n == 0)&&(i == \at(j, Pre))&&(k == 100)&&(j == \at(j, Pre))&&(b == \at(b, Pre))) || (b == (\at(b, Pre) == (n % 2 == 0))) ;
    loop invariant  ((n == 0)&&(i == \at(j, Pre))&&(k == 100)&&(j == \at(j, Pre))&&(b == \at(b, Pre))) || (j == \at(j, Pre) + n/2 + (n % 2 == 1 && !\at(b, Pre) ? 1 : 0)) ;
    loop invariant  ((n == 0)&&(i == \at(j, Pre))&&(k == 100)&&(j == \at(j, Pre))&&(b == \at(b, Pre))) || (i == \at(j, Pre) + n/2 + (n % 2 == 1 && \at(b, Pre) ? 1 : 0)) ;
    loop invariant  ((n == 0)&&(i == \at(j, Pre))&&(k == 100)&&(j == \at(j, Pre))&&(b == \at(b, Pre))) || (0 <= n <= 2*k) ;
    loop invariant k == 100;
  */
  for( n = 0 ; n < 2*k ; n++ ) {
    if(b) {
      i++;
    } else {
      j++;
    }
    b = !b;
  }
            
  /*@ assert i ==j;*/
}
