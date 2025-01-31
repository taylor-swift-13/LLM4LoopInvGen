/*@ requires x >= 0 && x <= 2 && y <= 2 && y >= 0; */
void foo(int x,int y,int z1,int z2,int z3) {

  
  
/*@
  loop invariant (1) ==> (y == 2 * (\at(y, Pre) / 2 + \at(x, Pre) / 2 + \at(z3, Pre) / 2 + \at(z2, Pre) / 2 + \at(z1, Pre) / 2));
  loop invariant (1) ==> (x == 2 * (\at(x, Pre) / 2 + \at(y, Pre) / 2 + \at(z3, Pre) / 2 + \at(z2, Pre) / 2 + \at(z1, Pre) / 2));
  loop invariant z3 == \at(z3, Pre);
  loop invariant z2 == \at(z2, Pre);
  loop invariant z1 == \at(z1, Pre);
*/
while (1) {
    
    x  = x + 2;
    y  = y + 2;

  if(x == 4){
    /*@ (y != 0) */
  }

}


 
}