
int unknown();
void foo()  
/*@ Require emp
   Ensure emp
*/ 
    {

    int c = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (unknown()) {
        
          if (unknown()) {
            if ( c != 4 )
            {
            c  = c + 1;
            }
          } else {
            if (c == 4) 
            {
            c  = 1;
            }
          }
    
    }

    /*@   (c != 4 ) => (c <= 4) */
    
}