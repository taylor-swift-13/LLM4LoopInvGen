/*@ requires x >= 0 && x <= 2 && y <= 2 && y >= 0; */
void foo(int x,int y) {

  
  while (1) {
    
    x  = x + 2;
    y  = y + 2;

    /*@ assert (x == 4) ==> (y != 0);  */

  }

}