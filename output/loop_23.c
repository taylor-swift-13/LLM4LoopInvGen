void foo()
/*@  Require emp
     Ensure emp
*/ {
  int c = 0;

   
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv
    (c >= 0) && (c <= 40)
*/
while (1) {
    if (c != 40) {
        c = c + 1;
    } else if (c == 40) {
        c = 1;
    }

    /*@ (c >= 0) && (c <= 40) */
}


  

}
