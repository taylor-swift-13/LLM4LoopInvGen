
void foo()  
/*@ Require emp 
   Ensure emp
*/ 
  {

  int i, c;
  i = 0;
  c = 0;
 
  while (i < 1000) {
    c = c + i;
    i = i + 1;
  }

  /*@  c >= 0 */
}

