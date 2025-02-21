
void foo(int v1,int v2,int v3)
/*@  Require emp
     Ensure emp
*/ {

  int sn = 0;
  int x = 0;
  
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv   
    v3 == v3@pre && v2 == v2@pre && v1 == v1@pre 
    && x >= 0 && sn >= 0 && x == sn 
    && (sn == x)
*/ 
while (1) {

    x  = (x + 1);
    sn  = (sn + 1);

    if(sn != x){
    /*@  (sn == -1) */
    }
    
}

  
    
}
