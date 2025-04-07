

void foo()  
/*@ Require emp 
   Ensure emp
*/ 
    {
  int i,j,k,n;
  
  for (i=0;i<n;i++)
    for (j=i;j<n;j++)
      for (k=j;k<n;k++){
	      /*@ k >= i*/
      }
}
