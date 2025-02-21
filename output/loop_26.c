
void foo(int n,int v1,int v2,int v3)
/*@  Require n > 0
     Ensure emp
*/ {

    int c = 0;

    
   
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv   
    v3 == v3@pre 
    && v2 == v2@pre 
    && v1 == v1@pre 
    && n == n@pre 
    && c >= 0 
    && c <= n 
    && (c == 0 || (c > 0 && c <= n))
*/
while (1){
    if(c == n) {
        c = 1;
    }
    else {
        c = c + 1;
    }
    /*@ (c >= 0) && (c <= n) */
}


   

}