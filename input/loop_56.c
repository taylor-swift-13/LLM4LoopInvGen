/*@ requires size >= 1; */
void foo(int size) {
 
  int i = 1;
  int sn = 0;
  
   
  while (i <= size) {

    i  = (i + 1);
    sn  = (sn + 1);
    
  }

  /*@ assert (sn != size) ==> (sn == 0);*/

}