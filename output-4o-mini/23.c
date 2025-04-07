void foo() {
  
    int i=1;
    int j=20;
   
    
    
/*@
  loop invariant  ((j == 20)&&(i == 1)) || (i == 1 + 2 * (20 - j));
  loop invariant  ((j == 20)&&(i == 1)) || (j == 20 - (i - 1) / 2);
  loop invariant  j >= 13; // New invariant to ensure j will reach 13
*/
while (j >= i) {
    i  = i + 2;
    j  = j - 1;
}

  
    /*@ assert j == 13;*/
  
  }