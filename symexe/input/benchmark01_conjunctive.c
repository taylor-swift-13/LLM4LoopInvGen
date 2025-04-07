void foo() {
    int x = 1;
    int y = 1;
    
    
    while (1) {
      x=x+y;
      y=x;

      /*@ y >= 1; */
    }
    return 0;
  }
  