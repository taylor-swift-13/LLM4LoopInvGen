

void foo(int m,int j,int a)  
/*@ Require a <= m && j < 1
   Ensure emp
*/ 
    {

    int k = 0;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while ( k < 1) {

        if(m < a) {
            m = a;
        }
        
        k = k + 1;
    }

  /*@  a <= m */

}