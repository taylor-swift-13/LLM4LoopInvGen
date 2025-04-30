int unknown1()
/*@ Require emp 
Ensure __return <= INT_MAX && __return > INT_MIN
*/ ;
int unknown2()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/ ;


int main(int flag)
 
/*@ Require emp 
   Ensure emp
*/ 
    {
  int t = 0;
  int s = 0;
  int a = 0;
  int b = 0;

 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while(unknown1()) {
    a++;
    b++;
    s += a;
    t += b;
    if(flag) {
      t += a;
    }
  } 
 
  int x = 1;

  if(flag) {
    x = t - 2*s + 2;
  }
  
  int y = 0;
  
 
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 while(y <= x){
    if(unknown2()) 
       y++;
    else 
       y += 2;
  }
  /*@  y <= 4 */
}

