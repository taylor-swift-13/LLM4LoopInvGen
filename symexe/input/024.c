

void foo(int n)  
/*@ Require emp 
   Ensure emp
*/ 
    {
  int i,j,k;
  
  i=0;
  for (i=0;i<n;i++){

    j=i;
    for (j=i;j<n;j++){

      k=j;
      for (k=j;k<n;k++){
	      /*@ k >= i*/
      }
    }
  }
}
