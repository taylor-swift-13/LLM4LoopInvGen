int unknown1();
int unknown2();
int unknown3();


void foo()  
/*@ Require emp 
   Ensure emp
*/ 
    {
 int x = 0, y = 0;
\
 while(unknown1()) {
   if(unknown2()) { 
      x++; 
      y += 100; 
   }
   else if (unknown3()){ 
      if (x >= 4) { 
          x++; 
          y++; 
      } 
      if (x < 0) {
          y--;
      }
   }
  
 }
 /*@  x < 4 || y > 2 */
}
