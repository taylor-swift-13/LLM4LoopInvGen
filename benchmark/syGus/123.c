void foo(int size,int v1,int v2,int v3) {
 
    int i = 1;
    int sn = 0;
    
     
    while (i <= size) {
  
      i  = (i + 1);
      sn  = (sn + 1);
      
    }
  
    /*@ assert (sn != 0) ==> (sn == size);*/
  
  }