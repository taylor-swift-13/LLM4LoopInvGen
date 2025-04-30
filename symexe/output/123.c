
/*@Inv
  (1 <= size@pre) => (((sn == 0) && (i == 1) && (v3 == v3@pre) && (v2 == v2@pre) && (v1 == v1@pre) && (size == size@pre)) || (sn == i - 1)) &&
  (1 <= size@pre) => (((sn == 0) && (i == 1) && (v3 == v3@pre) && (v2 == v2@pre) && (v1 == v1@pre) && (size == size@pre)) || (sn == i - 1)) &&
  !(1 <= size@pre) => ((sn == 0) && (i == 1) && (v3 == v3@pre) && (v2 == v2@pre) && (v1 == v1@pre) && (size == size@pre)) &&
  v3 == v3@pre &&
  v2 == v2@pre &&
  v1 == v1@pre &&
  size == size@pre
*/
while (i <= size) {
    i = (i + 1);
    sn = (sn + 1);
}
