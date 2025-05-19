void foo(int m,int j,int a,int c)  
/*@ Require emp 
   Ensure emp
*/ 
    {

    int k = 0;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while ( k < c) {

        if(m < a) {
            m = a;
        }
        
        k = k + 1;
    }

  /*@  (c > 0 ) => (a <= m) */
}