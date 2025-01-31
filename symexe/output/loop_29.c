
void foo(int n,int y)
/*@  Require emp
     Ensure emp
*/ {
    int x = 1;

    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (x <= n) {
        y = n - x;
        x = x + 1;
    }
    
    if(n > 0){
    /*@ (y >= 0 && y <= n) */
    }


}