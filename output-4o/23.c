void foo() {
  
    int i=1;
    int j=20;
   
    
    
/*@
  loop invariant j == 20 - (i - 1) / 2;
  loop invariant i >= 1 && i % 2 == 1;
*/
while (j >= i) {
  i = i + 2;
  j = j - 1;
}

/*@ assert j == 13; */

  
    /*@ assert j == 13;*/
  
  }