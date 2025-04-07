
void foo() {
 
    int i = 1;
    int sn = 0;
    
     
    
/*@
  loop invariant  (i == sn + 1) && (sn <= 8);
  loop invariant  (sn == 0 && i == 1) || (i > 1);
*/
while (i <= 8) {
    i = (i + 1);
    sn = (sn + 1);
}

  
    /*@ assert (sn != 8) ==> (sn == 0);*/
  
  }