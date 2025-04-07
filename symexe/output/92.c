void foo(int z1,int z2,int z3)  
/*@ Require emp 
   Ensure emp
*/ 
    {

    int x = 0;
    int y = 0;

    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while(y >= 0) {
        y = y + x;
    }
    /*@  y >= 0*/

}