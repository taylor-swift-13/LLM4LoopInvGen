
void foo(int n,int y,int v1,int v2,int v3)
/*@  Require emp
     Ensure emp
*/ {
    int x = 1;

    
   
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv   
        v3 == v3@pre 
    &&  v2 == v2@pre 
    &&  v1 == v1@pre 
    &&  n == n@pre 
    &&  x >= 1 
    &&  x <= n + 1 
    &&  y == n - x + 1
*/ 
while (x <= n) {
    y = n - x;
    x = x + 1;
}


    if(n > 0){
    /*@ (y >= 0 && y <= n) */
    }


}