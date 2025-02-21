
void foo()
/*@  Require emp
     Ensure emp
*/ {

  int sn = 0;
  int x = 0;
  
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv
    (x >= 0) 
    && (sn >= 0) 
    && (sn == x + 1) 
*/
while (1) {

    x  = (x + 1);
    sn  = (sn + 1);

    if(sn != x){
    /*@  (sn == -1) */
    }

}


  
}
