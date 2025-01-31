/*@ requires x >= y  && y >= 0; */
void foo(int x, int y,int z1,int z2,int z3) {

  int i = 0;
  

  
  
/*@
  loop invariant (i >= 0 && i <= y);
  loop invariant z3 == \at(z3, Pre);
  loop invariant z2 == \at(z2, Pre);
  loop invariant z1 == \at(z1, Pre);
  loop invariant y == \at(y, Pre);
  loop invariant x == \at(x, Pre);
*/
while (1) {
    if (i < y) {
        i = i + 1;
        /*@ assert (i >= 0 && i <= y); */
    }
}


  
}