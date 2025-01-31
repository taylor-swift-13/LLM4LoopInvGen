void poo( int i ,  int y ,  int x )
        /*@
            Require emp
            Ensure emp
        */
        {
    if ( i < y )
    {
    i  = (i + 1);
    
    }
  /*@ Print user assertion at number End*/ 
 }