void foo()
/*@  Require emp
     Ensure emp
*/ {
  
  int i=1;
  int j=10;
 
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv
    (j == 10 - (i - 1) / 2) 
    && (i >= 1) 
    && (j >= 6) 
    && (i % 2 == 1) 
    && (j >= i)
*/
while (j >= i) {
    i = i + 2;
    j = j - 1;
}


  /*@ j == 6 */

}