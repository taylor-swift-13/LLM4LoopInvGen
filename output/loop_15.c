void foo() {
  
  int i=1;
  int j=20;
 
  
  
/*@
  loop invariant (20 >= 1) ==> (j == 20 - \at(i, Pre) + i - 1);
  loop invariant (20 >= 1) ==> (i == \at(i, Pre) + 2 * (\at(j, Pre) - j));
*/
while (j >= i) {
  
  i = i + 2;
  j = j - 1;

}


  /*@ assert j == 13;*/

}