int unknown()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/;





void foo()  
/*@ Require emp 
   Ensure emp
*/ 
    {
  int x = 0;
  int y = 0;
  int n = 0;
 
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (((n == 0)&&(y == 0)&&(x == 0)) || (x == y) ) &&
(((n == 0)&&(y == 0)&&(x == 0)) || (x == y) ) &&
(n == 0)
    */
    
                while(unknown()) {
      x++;
      y++;
  }
 
 
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    (((n == 0)&&(y == 0)&&(x == 0)) || (x == y) ) &&
(((n == 0)&&(y == 0)&&(x == 0)) || (x == y) ) &&
(n == 0)
    */
    
                while(x!=n) {
      x--;
      y--;
  }
  /*@  y == n */
}
