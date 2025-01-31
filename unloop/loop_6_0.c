void poo( int x ,  int z ,  int y ,  int size ,  int v3 ,  int v2 ,  int v1 )
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