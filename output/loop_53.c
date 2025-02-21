
void foo(int n)
/*@  Require emp
     Ensure emp
*/ {

  int i = 1;
  int sn = 0;
  
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv   
    n == n@pre 
    && sn == (i - 1) 
    && i >= 1 
    && i <= n + 1
*/ 
while (i <= n) {
    i = (i + 1);
    sn = (sn + 1);
}

  
  if(sn != 0){
  /*@  (sn ==n)*/
  }

}