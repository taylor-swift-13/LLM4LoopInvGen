


void foo()
 
/*@ Require emp 
   Ensure emp
*/ 
    {
  int j = 0;
  int i;
  int x = 100;
   
 
  for (i = 0; i < x ; i++){
    j = j + 2;
  }

  /*@  j == 2*x */
}
