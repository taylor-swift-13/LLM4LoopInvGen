/*@ requires x >= 0 && x <= 2 && y <= 2 && y >= 0; */
void foo(int x,int y) {

  
  
/*@
  loop invariant (1) ==> (y <= \at(y, Pre) + 2 * ((x - \at(x, Pre)) / 2));
  loop invariant (1) ==> (x <= \at(x, Pre) + 2 * ((x - \at(x, Pre)) / 2));
*/
while (1) {

  x  = x + 2;
  y  = y + 2;

  if(x == 4){
    /*@ assert (y != 0); */
  }

}


}