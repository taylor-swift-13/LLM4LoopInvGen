
void foo(int size,int v1,int v2,int v3)
/*@  Require size >= 1
     Ensure emp
*/ {
 
  int i = 1;
  int sn = 0;
  
   
 
  /*@ Print user assertion at number LoopEntry_0*/ 

/*@ Inv   
    v3 == v3@pre 
    && v2 == v2@pre 
    && v1 == v1@pre 
    && size == size@pre 
    && i >= 1 
    && i <= size + 1 
    && sn == i - 1 
    && sn <= size
*/ 
while (i <= size) {

    i  = (i + 1);
    sn  = (sn + 1);

}


  if(sn!=size){
  /*@ (sn == 0)*/
  }

}
