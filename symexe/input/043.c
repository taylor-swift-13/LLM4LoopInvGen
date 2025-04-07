int unknown();

void foo(int x, int y)
 
/*@ Require x!=y
   Ensure emp
*/ 
    {
  int i=0;
  int t=y;
   
  

  while (unknown()){
    if (x > 0)   
      y = y + x;
  }
   
  /*@  y >= t*/
 
}

