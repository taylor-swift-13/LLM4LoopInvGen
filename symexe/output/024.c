

void foo(int n)  
/*@ Require emp 
   Ensure emp
*/ 
    {
  int i,j,k;
  
  i=0;
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (i=0;i<n;i++){

    j=i;
   
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 for (j=i;j<n;j++){

      k=j;
     
  /*@ Print user assertion at number LoopEntry_2*/ 
/*@ Inv emp */ /*2*/ 
 for (k=j;k<n;k++){
	      /*@ k >= i*/
      }
    }
  }
}
