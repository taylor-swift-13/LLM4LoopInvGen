
int unknown1();
int unknown2();
int unknown3();


void main()  
/*@ Require emp 
   Ensure emp
*/ 
    {
  int w = 1, z = 0, x = 0, y = 0;
 
  while (unknown1()) {
   
    while (unknown2()) {
      if (w % 2 == 1)
        x++;
      if (z % 2 == 0)
        y++;
    }
   
    while (unknown3()) {
      z = x + y;
      w = z + 1;
    }
  }
  /*@  x == y*/
}