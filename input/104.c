
void foo(int n,int v1,int v2,int v3) {
  
    int x = 0;
    
    
    while (x < n) {
      
      x  = (x + 1);
      
    }
    /*@ assert (x != n) ==> (n < 0); */
    
  }