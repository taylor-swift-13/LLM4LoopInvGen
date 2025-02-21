void foo(int n,int v1,int v2,int v3)
/*@  Require emp
     Ensure emp
*/ {
  
  int x = 0;
  
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv   
    v3 == v3@pre 
    && v2 == v2@pre 
    && v1 == v1@pre 
    && n == n@pre 
    && x >= 0 
    && x <= n
*/ 
while (x < n) {
    x  = (x + 1);
}

  
  if(n >= 0 ){
  /*@  (x == n) */
  }
  
}