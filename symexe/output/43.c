int unknown();
void foo(int n)  
/*@ Require n >0
   Ensure emp
*/ 
    {

    int c = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (unknown()) {
        {
          if (unknown()) {
            if ( c > n )
            {
            c  = c + 1;
            }
          } else {
            if (c == n) 
            {
            c  = 1;
            }
          }
    
        }
    
    }            
    /*@  (c == n) => (n > - 1) */
    

  

}