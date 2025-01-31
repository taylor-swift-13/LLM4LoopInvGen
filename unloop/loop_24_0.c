void poo( int c ,  int n )
        /*@
            Require emp
            Ensure emp
        */
        {
        if(c == n) {
            c = 1;
        }
        else {
            c = c + 1;
        }

        
    /*@ Print user assertion at number End*/ 
 }