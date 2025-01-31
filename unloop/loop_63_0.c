void poo( int x1 ,  int d3 ,  int d2 ,  int d1 ,  int x3 ,  int x2 )
        /*@
            Require emp
            Ensure emp
        */
        {
        if(x2 > 0) {
            if(x3 > 0) {
                x1 = x1 - d1;
                x2 = x2 - d2;
                x3 = x3 - d3;
            }
        }
    /*@ Print user assertion at number End*/ 
 }