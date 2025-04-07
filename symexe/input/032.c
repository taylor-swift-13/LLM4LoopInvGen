

void foo(int b,int n,int j)  
/*@ Require emp 
   Ensure emp
*/ 
    {
  int k = 100;
  int i = j;
 
  for( n = 0 ; n < 2*k ; n++ ) {
    if(b) {
      i++;
    } else {
      j++;
    }
    b = !b;
  }
  /*@  i ==j*/
}
