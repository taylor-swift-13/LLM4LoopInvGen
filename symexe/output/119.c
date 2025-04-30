
/*@Inv
  (1 <= size@pre) ==> (((sn == 0) && (i == 1) && (size@pre)) || (i <= size)) &&
  (1 <= size@pre) ==> (((sn == 0) && (i == 1) && (size@pre)) || (sn == i - 1)) &&
  !(1 <= size@pre) ==> ((sn == 0) && (i == 1) && (size@pre)) &&
  size == size@pre
*/
while (i <= size) {
    i  = (i + 1);
    sn  = (sn + 1);
}
