
void foo(int n)
/*@  Require emp
     Ensure emp
*/ {

  int i = 1;
  int sn = 0;
  
  
  while (i <= n) {
    
    i  = (i + 1);
    sn  = (sn + 1);

  }
  
  if(sn != 0){
  /*@  (sn ==n)*/
  }

}