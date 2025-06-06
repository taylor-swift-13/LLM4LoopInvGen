void foo(int size,int v1,int v2,int v3)  
/*@ Require emp 
   Ensure emp
*/ 
    {
 
    int i = 1;
    int sn = 0;
    
     
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((1 <= size@pre) => (((sn == 0)&&(i == 1)&&(v3 == v3@pre)&&(v2 == v2@pre)&&(v1 == v1@pre)&&(size == size@pre)) || (1 <= i && i <= size + 1 && sn == i - 1))) &&
((1 <= size@pre) => (((sn == 0)&&(i == 1)&&(v3 == v3@pre)&&(v2 == v2@pre)&&(v1 == v1@pre)&&(size == size@pre)) || (sn == i - 1))) &&
((!(1 <= size@pre)) => ((sn == 0)&&(i == 1)&&(v3 == v3@pre)&&(v2 == v2@pre)&&(v1 == v1@pre)&&(size == size@pre))) &&
(v3 == v3@pre) &&
(v2 == v2@pre) &&
(v1 == v1@pre) &&
(size == size@pre)
    */
    
    while (i <= size) {
        i = (i + 1);
        sn = (sn + 1);
    }
  
    /*@  (sn != 0) => (sn == size)*/
  
  }