

void foo(int n0, int n1) 
/*@
Require INT_MIN < n0 && n0 < INT_MAX && INT_MIN < n1 && n1 < INT_MAX
Ensure emp
*/{
 
  int i0 = 0;
  int k = 0;
 

 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while( i0 < n0 ) {
    i0++;
    k++;
  }

  int i1 = 0;
 
 
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 while( i1 < n1 ) {
    i1++;
    k++;
  }

  int j1 = 0;
  
 
  /*@ Print user assertion at number LoopEntry_2*/ 
/*@ Inv emp */ /*2*/ 
 while( j1 < n0 + n1 ) {
    /*@  k>0*/
      j1++;
      k--;
  }
}