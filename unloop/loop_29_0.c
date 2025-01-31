void poo( int x ,  int y ,  int n )
        /*@
            Require emp
            Ensure emp
        */
        {
        y = n - x;
        x = x + 1;
    /*@ Print user assertion at number End*/ 
 }