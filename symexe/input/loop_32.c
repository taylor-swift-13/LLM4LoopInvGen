


void foo(int y,int x1,int x2,int x3)
/*@  Require 0 <= y && y <= 127
     Ensure emp
*/ {
  int c = 0;
  int z = 36 * y;
  



  while (1) {
    if ( c < 36 )
    {
    z  = z + 1;
    c  = c + 1;
  /*@  ( z >= 0 && z < 4608) */
    }

  }



}