
void foo(int n)
/*@  Require n >= 0
     Ensure emp
*/ {

  int x = n;
  int y = 0;

 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv   
    n == n@pre 
    && x >= 0 
    && y >= 0 
    && x + y == n@pre 
*/
while (x > 0) {

    y = y + 1;
    x = x - 1;

}

 /*@  y == n  */
}