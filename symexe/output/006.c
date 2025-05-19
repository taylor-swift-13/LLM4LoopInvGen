

void foo(int k)
/*@
Require 0 <= k && k <= 1
Ensure emp
*/ {
    int i,j;
    i = 1;
    j = 1;
   

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (i < 1000000) {
        i = i + 1;
        j = j + k;
        k = k - 1;
        /*@  1 <= i + k && i + k <= 2 && i >= 1*/
    }

}