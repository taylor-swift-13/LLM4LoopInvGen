
void foo(int size) {
 
    int i = 1;
    int sn = 0;
    
     
    while (i <= size) {
  
      i  = (i + 1);
      sn  = (sn + 1);
      
    }
  
    /*@ assert (sn != 0) ==> (sn == size);*/
  
  }