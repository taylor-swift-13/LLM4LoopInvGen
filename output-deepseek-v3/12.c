int unknown();
/*@ requires x >= 0 && x <= 10 && y <= 10 && y >= 0; */
void foo(int x, int y,int z1,int z2,int z3) {
  
  
    
/*@
  loop invariant \at(x, Pre) >= 0 && \at(x, Pre) <= 10 && \at(y, Pre) <= 10 && \at(y, Pre) >= 0;
  loop invariant x == \at(x, Pre) + 10 * (x - \at(x, Pre)) / 10;
  loop invariant y == \at(y, Pre) + 10 * (y - \at(y, Pre)) / 10;
  loop invariant z3 == \at(z3, Pre);
  loop invariant z2 == \at(z2, Pre);
  loop invariant z1 == \at(z1, Pre);
*/
while (unknown()) {
    x = x + 10;
    y = y + 10;
}


    /*@ assert (y == 0) ==>  (x != 20); */
  
   
  }