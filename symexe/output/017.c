

void foo(int n)
 
/*@ Require emp 
   Ensure emp
*/ 
    {
 int k=1;
 int i=1;
 int j=0;
 

  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while(i < n) {
  j = 0;
 
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 while(j < i) {
      k += (i-j);
      j++;
  }
  i++;
 }
 /*@  k >= n */
 
}
