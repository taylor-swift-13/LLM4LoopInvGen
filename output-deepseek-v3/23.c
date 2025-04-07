void foo() {
  
    int i=1;
    int j=20;
   
    
    
void foo() {
    int i=1;
    int j=20;
    
    /*@
      loop invariant 1 <= i <= 41;
      loop invariant 0 <= j <= 20;
      loop invariant 2*j + i == 41;
      loop assigns i, j;
    */
    while (j >= i) {
        i = i + 2;
        j = j - 1;
    }
  
    /*@ assert j == 13;*/
}

  
    /*@ assert j == 13;*/
  
  }