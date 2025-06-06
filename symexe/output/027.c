
void foo(int l,int n)  
/*@ Require l>0
   Ensure emp
*/ 
    {
  int i, k;
 

  k =1;
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (k =1; k < n; k++) {
    i =l;
   
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 for (i=l; i < n; i++) {

    }

    /*@ (forall (i: Z), (l <= i && i < n) => (1 <= k)) */
  }

}