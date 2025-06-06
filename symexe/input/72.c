int unknown();
void foo(int y)  
/*@ Require 0 <= y && y <= 127 
   Ensure emp
*/ 
    {
    int c = 0;
    int z = 36 * y;
  
    while (unknown()) {

      if ( c < 36 )
      {
      z  = z + 1;
      c  = c + 1;
      }
      
    }
  /*@   ( c < 36 ) => ( z >= 0 )  */
    
  



}