void foo(int x2,int x3)  
/*@ Require emp 
   Ensure emp
*/ 
    {

    int d1 = 1;
    int d2 = 1;
    int d3 = 1;
    int x1 = 1;

    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while(x1 > 0) {
        if(x2 > 0) {
            if(x3 > 0) {
                x1 = x1 - d1;
                x2 = x2 - d2;
                x3 = x3 - d3;
            }
        }
    }

    /*@  x3 >= 0*/


}