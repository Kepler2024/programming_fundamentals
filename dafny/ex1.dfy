/* file     : exercise8.dfy */
/* author   : Harry (qilin2603379191@gmail.com) */
/* date     : 2025/10/22 */
/* version  : 1.0 */
/* description:
 * Dafny exercise 8
 */



method exercise8(ghost x: nat, y: int) returns (z: int)
  requires 2 * x - y == 3 || 4 * x + y == 42
  ensures  z == x
{
  // If y is odd, then equation (1) must hold: 2*x - y == 3
  // From this equation, we can solve x = (y + 3) / 2
  if y % 2 == 1
  {
    z := (y + 3) / 2;
  }
  // Otherwise y is even, so equation (2) must hold: 4*x + y == 42
  // From this equation, we can solve x = (42 - y) / 4
  else
  {
    z := (42 - y) / 4;
  }
}