
void foo(int x,int y)
/*@  Require x >= 0 && x <= 10 && y <= 10 && y >= 0
     Ensure emp
*/ {

  
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (1) {
    
    x  = x + 2;
    y  = y + 2;

    if(x == 4){
    /*@ (y != 0) */
  }

  }


}