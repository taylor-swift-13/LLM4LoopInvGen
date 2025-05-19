int unknown1()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/;
int unknown2()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/;

void foo()  
/*@ Require emp 
   Ensure emp
*/ 
    {
  int a = 1;
  int b = 1;
  int c = 2;
  int d = 2;
  int x = 3;
  int y = 3;
 
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (((y == 3) && (x == 3) && (d == 2) && (c == 2) && (b == 1) && (a == 1)) || (a + c == b + d))
    */
  while (unknown1()) {
    x = a + c;
    y = b + d;

    if ((x + y) % 2 == 0) {
      a++;
      d++;
    } else {
      a--;
    }

    /*@ Inv
    (a + c == b + d)
    */
    while (unknown2()) {
      c--;
      b--;
    }
  }
  /*@ a + c == b + d */
}