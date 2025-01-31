void foo(){
  
  int x = 1;
  int y = 0;
  
  
  
        /*@
          loop invariant (0 <= y <= 100000);
          loop invariant (x == y * (y - 1) / 2 + 1);
        */
        while (y < 100000) {
    
     x  = x + y;
     y  = y + 1;
    

  }


  /*@ assert x >= y; */
}