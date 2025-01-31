void foo(int v1,int v2,int v3)
/*@  Require emp
     Ensure emp
*/ {
  int c = 0;

   
  while (1) {
      if ( c != 40 )
        {
        c  = c + 1;
        }
      else if ( c == 40 )
        {
        c = 1;
        }
      /*@ (c >= 0) && (c <= 40) */
  }

  

}