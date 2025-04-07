int unknown1();
int unknown2();

void foo()  
/*@ Require emp 
   Ensure emp
*/ 
    {
  int a = 1;
  int b = 1;
  int c = 2;
  int d = 2;
  int x = 3;
  int y = 3;
 
  while (unknown1()) {
    x = a + c;
    y = b + d;

    if ((x + y) % 2 == 0) {
      a++;
      d++;
    } else {
      a--;
    }

   
    while (unknown2()) {
      c--;
      b--;
    }
  }
  /*@ a + c == b + d */
}