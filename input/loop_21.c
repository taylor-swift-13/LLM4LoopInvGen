void foo(int n, int v1,int v2,int v3)
/*@  Require emp
     Ensure emp
*/ {

  int x = n;
  
  
  while (x > 1) {
    
     x  = x - 1;

  }

   if( n >= 1 ){
    /*@ (x == 1) */
  }
}