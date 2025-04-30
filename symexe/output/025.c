
int unknown1();
int unknown2();


void foo()
{
  int x = 0;
  int y = 0;
  int i = 0;
  int j = 0;

 
  
            
            /*@
          loop invariant  ((j == 0)&&(i == 0)&&(y == 0)&&(x == 0)) || (x >= 0 && y >= x && (x == y ==> i >= j) && (i >= j ==> x == y)) ;
          loop invariant  ((j == 0)&&(i == 0)&&(y == 0)&&(x == 0)) || (y >= 0 && y >= x && (x == y ==> i >= j) && (i >= j ==> x == y)) ;
          loop invariant  ((j == 0)&&(i == 0)&&(y == 0)&&(x == 0)) || (i >= 0 && (x == y ==> i >= j) && (i >= j ==> x == y)) ;
          loop invariant  ((j == 0)&&(i == 0)&&(y == 0)&&(x == 0)) || (j >= 0 && (x == y ==> i >= j) && (i >= j ==> x == y)) ;
          loop invariant i >= j;
            */
            while(unknown1())
  {
    
    
            
            /*@
          loop invariant j >= 0 && i >= 0 && y >= 0 && x >= 0 ;
          loop invariant x == y ==> i >= j ;
          loop invariant x < y ==> i < j ;
          loop invariant y >= x ;
            */
            while(unknown2())
    {
       if(x == y){
          i++;
       }else{
          j++;
       }
    }
            

    if(i >= j)
    {
       x++;
       y++;
    }
    else{
       y++;
    }
  }
            

  /*@ assert i >= j; */
}
