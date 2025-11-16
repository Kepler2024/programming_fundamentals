/* file     : termination.dfy */
/* author   : Harry (qilin2603379191@gmail.com) */
/* date     : 2025/11/10 */
/* version  : 1.0 */
/* description:
 * lab7ex7
 */

include "io.dfy"

ghost function f(n: nat): int
{
  if n == 0 then 1
  else if n == 1 then 1
  else if n % 2 == 0 then f(n/2) - f(n/2 - 1)
  else f(n/2) + n/2
}

method computeF(m: nat) returns (x: int)
  ensures x == f(m)
  decreases m
{
  if m == 0 {
    x := 1;
  } else if m == 1 {
    x := 1;
  } else if m % 2 == 0 {
    var k := m / 2;
    var fk := computeF(k);          
    var fkPrev := computeF(k - 1);  
    x := fk - fkPrev;               
  } else {
    var k := m / 2;
    var fk := computeF(k);          
    x := fk + k;                   
  }
}


method Main()
{
  var n: int := 0;
  while n < 20 
  {
    var fn := computeF(n);
    print "fusc(", n, ")=", fn, ".\n";
    n := n + 1;
  }
}

