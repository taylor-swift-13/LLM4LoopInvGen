
void foo() {
  
    int i=1;
    int j=10;
   
    /*@
      Inv
      ((j == 10) && (i == 1)) ||
      (i >= 1 && i <= 21) &&
      (j == 10 - (i - 1) / 2)
    */
    while (j >= i) {
        i  = i + 2;
        j  = j - 1;
    }
  
    /*@ assert j == 6;*/
}
