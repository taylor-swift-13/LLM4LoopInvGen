void poo( int i ,  int t ,  int c ,  int j )
        /*@
            Require emp
            Ensure emp
        */
        {
        if(c > 48) {
            if (c < 57) {
                j = i + i;
                t = c - 48;
                i = j + t;
            }
        }

        
    /*@ Print user assertion at number End*/ 
 }