int unknown();
int main(int y)  
/*@ Require emp 
   Ensure emp
*/ 
    {

    int lock = 1;
    int x = y;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (x != y) {
        if ( unknown() ) {
          
          lock  = 1;
          x  = y;
          
        } else {
          
          lock  = 0;
          x  = y;
          y  = y + 1;
          
        }
 
    }
    /*@  lock == 1*/
  }