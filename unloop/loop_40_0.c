void poo( int y ,  int x ,  int i ,  int n )
        /*@
            Require emp
            Ensure emp
        */
        {
    
    i  = i + 1;
      if ( i % 2 == 0) {
        
        x  = x + 1;
        y  = y + 2;
        
      } else {
        
        x  = x + 2;
        y  = y + 1;
        
      }


  /*@ Print user assertion at number End*/ 
 }