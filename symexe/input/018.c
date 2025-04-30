
void foo(int flag, int a)  
/*@ Require flag > 0
   Ensure emp
*/ 
{
   int b = 0;
   int j = 0;
 
   for (b = 0; b < 100 ; ++b){
      if (flag)
         j = j + 1;
   }

   /*@  (flag!=0) => (j == 100) */
}