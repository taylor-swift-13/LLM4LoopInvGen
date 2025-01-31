/*@ requires size >= 1; */
void foo(int size) {
 
  int i = 1;
  int sn = 0;
  
   
  
    /*@
      loop invariant (1 <= \at(size, Pre)) ==> (sn == i - 1);
      loop invariant (1 <= \at(size, Pre)) ==> (1 <= i <= size + 1);
      loop invariant size == \at(size, Pre);
    */
    while (i <= size) {

        i  = (i + 1);
        sn  = (sn + 1);
        
    }


  /*@ assert (sn != size) ==> (sn == 0);*/

}