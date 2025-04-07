void foo() {
  
    int i=1;
    int j=10;
   
    
    
/*@
  loop invariant (j >= 6) && (i == 1 + 2 * (10 - j)) ;
*/
while (j >= i) {
  i  = i + 2;
  j  = j - 1;
}

  
    /*@ assert j == 6;*/
  
  }