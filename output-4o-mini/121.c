
void foo() {
 
    int i = 1;
    int sn = 0;
    
     
    
/*@
  loop invariant  (i >= 1) && (i <= 9) ; // i starts at 1 and goes up to 9 (exclusive)
  loop invariant  sn == i - 1 ; // sn counts the number of increments, starting from 0
*/
while (i <= 8) {
    i  = (i + 1);
    sn  = (sn + 1);
}

  
    /*@ assert (sn != 0) ==> (sn == 8);*/
  
  }