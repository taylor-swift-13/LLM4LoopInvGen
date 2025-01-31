/*@ requires size >= 1; */
void foo(int size,int v1,int v2,int v3) {
 
  int i = 1;
  int sn = 0;
  
   
  
/*@
  loop invariant (1 <= \at(size, Pre)) ==> (sn == i - 1);
  loop invariant (1 <= \at(size, Pre)) ==> (1 <= i && i <= size + 1);
  loop invariant v3 == \at(v3, Pre);
  loop invariant v2 == \at(v2, Pre);
  loop invariant v1 == \at(v1, Pre);
  loop invariant size == \at(size, Pre);
*/
while (i <= size) {
    i  = (i + 1);
    sn  = (sn + 1);
}


  /*@ assert (sn != size) ==> (sn == 0);*/

}