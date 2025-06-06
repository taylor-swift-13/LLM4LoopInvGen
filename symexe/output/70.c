void foo(int n,int y,int v1,int v2,int v3)  
/*@ Require emp 
   Ensure emp
*/ 
    {
    
    int x = 1;

    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (x <= n) {
        y = n - x;
        x = x + 1;
    }

    /*@  (n > 0) => (y <= n) */


}