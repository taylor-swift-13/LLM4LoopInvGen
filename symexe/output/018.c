
void foo(int flag, int a)  
/*@ Require flag > 0
   Ensure emp
*/ 
{
   int b = 0;
   int j = 0;
 
  
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((flag@pre > 0) => (((j == 0)&&(b == 0)&&(a == a@pre)&&(flag == flag@pre)) || (b <= j && j <= b + 1)) ) &&
((flag@pre > 0) => (((j == 0)&&(b == 0)&&(a == a@pre)&&(flag == flag@pre)) || (b <= 100)) ) &&
((flag@pre > 0) => (a == a@pre)) &&
((flag@pre > 0) => (flag == flag@pre))
    */
    
                for (b = 0; b < 100 ; ++b){
      if (flag)
         j = j + 1;
   }

   /*@  (flag!=0) => (j == 100) */
}