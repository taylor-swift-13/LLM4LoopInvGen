
void foo(int size) {
 
  int i = 1;
  int sn = 0;
  
   
  
/*@
  loop invariant (1 <= 8) ==> (sn == i - 1);
  loop invariant (1 <= 8) ==> (i >= 1 && i <= 9);
  loop invariant size == \at(size, Pre);
*/
while (i <= 8) {
  i  = (i + 1);
  sn  = (sn + 1);
}


  /*@ assert (sn != 8) ==> (sn == 0);*/

}