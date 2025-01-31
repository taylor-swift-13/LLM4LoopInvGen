void poo( int x ,  int y )
        /*@
            Require emp
            Ensure emp
        */
        {
        y = 100 - x;
        x = x +1;
    /*@ Print user assertion at number End*/ 
 }