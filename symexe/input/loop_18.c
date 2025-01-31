void foo(int n)
/*@  Require emp
     Ensure emp
*/ {

  int x = n;
  
  
  while (x > 1) {
    
     x  = x - 1;

  }

  if(n >= 0 ){
    /*@ (x == 1) */
  }
}