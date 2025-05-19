
int unknown1();


void foo(int n, int l) 
/*@
Require l > 0 && l < INT_MAX &&  n < INT_MAX
Ensure emp
*/{
  int i,k;

  k = 1;
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (k = 1; k < n; k++){

    i = 1;
   
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 for (i = l; i < n; i++){  
      /*@ 1 <= i*/
    }
    if(unknown1()) {
      l = l + 1;
    }
  }
}