void foo() {
  int c = 0;

   
  while (1) {
      if ( c != 40 )
        {
        c  = c + 1;
        }
      else if ( c == 40 )
        {
        c = 1;
        }
    /*@ assert (c >= 0) && (c <= 40);*/
  }

 

}