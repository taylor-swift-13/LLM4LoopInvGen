void poo( int x ,  int z ,  int y ,  int size )
        /*@
            Require emp
            Ensure emp
        */
        {
       x += 1;
       if( z <= y) {
          y = z;
       }
    /*@ Print user assertion at number End*/ 
 }