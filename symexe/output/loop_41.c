
void foo(int n,int k)
/*@  Require n >= 0 && k >= 0
     Ensure emp
*/ {
  
  int i = 0;
  int j = 0;
  
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (i <= n) {
    
     i  = i + 1;
     j  = j + i;
    

  }
  /*@ i + j + k > (2 * n) */;

}