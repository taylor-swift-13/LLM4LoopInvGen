void poo( int c )
        /*@
            Require emp
            Ensure emp
        */
        {
      if ( c != 40 )
        {
        c  = c + 1;
        }
      else if ( c == 40 )
        {
        c = 1;
        }

      
  /*@ Print user assertion at number End*/ 
 }