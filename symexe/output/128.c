
/*@Inv
  !(1 < y@pre) ==> ((x == 1) && (y == y@pre)) &&
  y == y@pre &&
  x >= 1
*/
while (x < y) {
    x = x + x;
}

/*@ assert x >= 1;*/
