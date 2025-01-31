void poo( int c ,  int v3 ,  int v2 ,  int v1 ,  int n )
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