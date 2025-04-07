void foo(int y,int z1,int z2,int z3) {

    int x = -50;
  
    
    
/*@  loop invariant  (x == -50) && (z3 == \at(z3, Pre)) && (z2 == \at(z2, Pre)) && (z1 == \at(z1, Pre)) ==> (x >= -50);
  loop invariant  z3 == \at(z3, Pre);
  loop invariant  z2 == \at(z2, Pre);
  loop invariant  z1 == \at(z1, Pre);
    y = y + 1;
}

/*@ assert y > 0; */

    /*@ assert y > 0; */
  
  }