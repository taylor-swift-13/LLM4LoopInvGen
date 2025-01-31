
/*@ requires x >= 0 && x <= 10 && y <= 10 && y >= 0; */
void foo(int x, int y) {
  
  
  
/*@
  loop invariant (1) ==> (y - (\at(y, Pre)) == x - (\at(x, Pre)));
  loop invariant (1) ==> (x % 10 == \at(x, Pre) % 10);
*/
while (1) {
    
  x = x + 10;
  y = y + 10;

  if(x == 20){
    /*@ assert (y != 0); */
  }
}


 
}
 