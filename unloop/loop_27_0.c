void poo( int y ,  int x )
        /*@
            Require emp
            Ensure emp
        */
        {
        y = 10 - x;
        x = x +1;
    /*@ Print user assertion at number End*/ 
 }