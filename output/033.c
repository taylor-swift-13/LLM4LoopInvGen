
    /*@ loop invariant
    (((y == 0)&&(x == 0)&&(z == k@pre)&&(k == k@pre)) || (z == k + y) ) &&
    (((y == 0)&&(x == 0)&&(z == k@pre)&&(k == k@pre)) || (x >= 0)) &&
    (((y == 0)&&(x == 0)&&(z == k@pre)&&(k == k@pre)) || (y >= 0)) &&
    (k == k@pre)
    */
                while(unknown1())
  {
    int c = 0;
    
    /*@ loop invariant
    \forall int i; 0 <= i && i <= c ==> (x >= 0 && y >= 0)
    */
    while(unknown2())
    {
      if(z==k+y-c)
      {
        x++;
        y++;
        c++;
      }else
      {
        x++;
        y--;
        c++;
      }
    }
    
    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@ loop invariant
    \forall int c; c >= 0 ==> (x >= 0 && y >= 0 && z == k + y)
    */
    while(unknown3())
    {
      x--;
      y--;
    }
                
    z=k+y;
  }
    