
void foo(int size)
/*@  Require emp
     Ensure emp
*/ {
 
  int i = 1;
  int sn = 0;
  
   
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv
    size == size@pre 
    && sn == i - 1
    && i >= 1
    && i <= 9
    && sn >= 0
*/ 
while (i <= 8) {
    i  = (i + 1);
    sn  = (sn + 1);
}


  if(sn != 8){
  /*@ (sn == 0)*/
  }

}
