


void foo(int y,int x1,int x2,int x3)
/*@  Require 0 <= y && y <= 127
     Ensure emp
*/ {
  int c = 0;
  int z = 36 * y;
  



 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@Inv   
    x3 == x3@pre 
    && x2 == x2@pre 
    && x1 == x1@pre 
    && y == y@pre 
    && 0 <= y && y <= 127
    && z == (36 * y) + c 
    && 0 <= c && c <= 36
*/ 
while (1) {
    if ( c < 36 )
    {
    z  = z + 1;
    c  = c + 1;
  /*@  ( z >= 0 && z < 4608) */
    }

}




}