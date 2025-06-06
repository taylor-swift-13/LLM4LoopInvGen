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
    (((y == 3)&&(x == 3)&&(d == 2)&&(c == 2)&&(b == 1)&&(a == 1)) || (a + c == b + d && x == a + c && y == b + d) ) &&
(((y == 3)&&(x == 3)&&(d == 2)&&(c == 2)&&(b == 1)&&(a == 1)) || (a + c == b + d && x == a + c && y == b + d) ) &&
(((y == 3)&&(x == 3)&&(d == 2)&&(c == 2)&&(b == 1)&&(a == 1)) || (a + c == b + d && x == a + c && y == b + d) ) &&
(((y == 3)&&(x == 3)&&(d == 2)&&(c == 2)&&(b == 1)&&(a == 1)) || (a + c == b + d && x == a + c && y == b + d) ) &&
(((y == 3)&&(x == 3)&&(d == 2)&&(c == 2)&&(b == 1)&&(a == 1)) || (a + c == b + d && x == a + c && y == b + d) ) &&
(((y == 3)&&(x == 3)&&(d == 2)&&(c == 2)&&(b == 1)&&(a == 1)) || (a + c == b + d && x == a + c && y == b + d) )
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
    
    /*@ 
      loop invariant a + c == b + d ;
      loop invariant a == 1 + 1 + (d - 2 + 1) + (1 + 1 - a) ;
      loop invariant b == 1 + (c - 2) - (1 - b) ;
      loop invariant c == 2 + (2 - c) - (b - 1) ;
      loop invariant d == 2 + 1 + (a - 1 + 1) - (2 + 1 - d) ;
      loop invariant x == a + c ;
      loop invariant y == b + d ;
    */
    while (unknown2()) {
      c--;
      b--;
    }
  }
  /*@ a + c == b + d */
}