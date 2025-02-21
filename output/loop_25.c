void foo(int v1,int v2,int v3)
/*@  Require emp
     Ensure emp
*/ {
  int c = 0;

   
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv   
    v3 == v3@pre && v2 == v2@pre && v1 == v1@pre 
    && c >= 0 && c <= 40
*/ 
while (1) {
    if (c != 40) {
        c = c + 1;
    }
    else if (c == 40) {
        c = 1;
    }
    /*@ (c >= 0) && (c <= 40) */
}


  

}