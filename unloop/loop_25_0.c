void poo( int c ,  int v3 ,  int v2 ,  int v1 )
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