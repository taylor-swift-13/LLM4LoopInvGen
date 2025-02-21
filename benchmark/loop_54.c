void foo()
/*@  Require emp
     Ensure emp
*/ {

  int sn = 0;
  int x = 0;
  
  
  while (unkown()) {

    x  = (x + 1);
    sn  = (sn + 1);
    
  }

  if(sn != x){
    /*@  (sn == -1) */
  }
}