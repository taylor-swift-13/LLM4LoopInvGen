void foo() {
  
    int i=1;
    int j=20;
   
    
    
/*@
  loop invariant (i == 1 + 2 * (20 - j)) && (j >= 13);
  loop assigns i, j;
  loop variant j - i; // Ensure that the loop will terminate as j decreases
*/
while (j >= i) {
    i  = i + 2;
    j  = j - 1;
}

  
    /*@ assert j == 13;*/
  
  }