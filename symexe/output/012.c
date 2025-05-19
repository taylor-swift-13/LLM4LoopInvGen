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
/*@ Inv
    (((b == 0)&&(a == 0)&&(s == 0)&&(t == 0)&&(flag == flag@pre)) || (s == a * (a + 1) / 2) ) &&
(((b == 0)&&(a == 0)&&(s == 0)&&(t == 0)&&(flag == flag@pre)) || (a >= 0) ) &&
(((b == 0)&&(a == 0)&&(s == 0)&&(t == 0)&&(flag == flag@pre)) || (b >= 0) ) &&
(flag == flag@pre)
    */
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
/*@ Inv
    ((y >= 0) )
    */
                  while(y <= x){
        if(unknown2()) 
           y++;
        else 
           y += 2;
      }
  /*@  y <= 4 */
}

