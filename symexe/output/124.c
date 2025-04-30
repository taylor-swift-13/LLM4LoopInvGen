
/*@Inv
  (\at(x, Pre) != 0 ==> (((j == y@pre) && (i == x@pre) && (y == y@pre) && (x == x@pre)) || (y == y@pre - (x@pre - x))) &&
  (\at(x, Pre) != 0 ==> (j + x == i + y)) &&
  (!(\at(x, Pre) != 0) ==> ((j == y@pre) && (i == x@pre) && (y == y@pre) && (x == x@pre))) &&
  (j == y@pre) &&
  (i == x@pre)
*/
while (x != 0) {
    x  = x - 1;
    y  = y - 1;
}

/*@ assert (i == j) ==> (y == 0); */
