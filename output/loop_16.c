void foo() {
  
  int i=1;
  int j=10;
 
  
  
        /*@
          loop invariant (j >= i) ==> (j == 10 - (i - 1)/2);
          loop invariant (j >= i) ==> (i == 1 + 2 * ((10 - j)/2));
        */
        while (j >= i) {
    
    i  = i + 2;
    j  = j - 1;
    

  }


  /*@ assert j == 6;*/

}