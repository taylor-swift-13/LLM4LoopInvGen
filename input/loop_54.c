void foo() {

  int sn = 0;
  int x = 0;
  
  
  while (1) {

    x  = (x + 1);
    sn  = (sn + 1);

     /*@ assert (sn != x) ==> (sn == -1);*/
    
  }

}