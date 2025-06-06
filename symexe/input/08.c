int unknown1()
/*@ Require emp 
Ensure __return <= INT_MAX && __return > INT_MIN
*/ ;
int unknown2()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/ ;
int unknown3()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/ ;


void foo()  
/*@ Require emp 
   Ensure emp
*/ 
   {
 int x = 0, y = 0;
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
