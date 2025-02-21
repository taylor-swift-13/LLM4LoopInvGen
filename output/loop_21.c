void foo(int n, int v1,int v2,int v3)
/*@  Require emp
     Ensure emp
*/ {

  int x = n;
  
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv   
    v3 == v3@pre 
    && v2 == v2@pre 
    && v1 == v1@pre 
    && n == n@pre 
    && x >= 1 
    && x <= n@pre
 */ 
while (x > 1) {
    
     x = x - 1;

}


   if( n >= 1 ){
    /*@ (x == 1) */
  }
}