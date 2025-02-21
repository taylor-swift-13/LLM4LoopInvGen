
void foo(int m,int j,int a,int c)
/*@  Require a <= m
     Ensure emp
*/ {

    int k = 0;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv
    c == c@pre 
    && a == a@pre 
    && j == j@pre 
    && a <= m 
    && k >= 0 
    && k <= c
    && (k == 0 || m >= a)
*/ 
while (k < c) {

    if (m < a) {
        m = a;
    }
    
    k = k + 1;
}

    
  if(c > 0){
  /*@  (a <= m) */
  }
}