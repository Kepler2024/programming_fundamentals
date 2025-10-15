/* file     : vigenere_cipher.c */
/* author   : Harry (qilin2603379191@gmail.com) */
/* date     : 2025/10/01 */
/* version  : 1.1 */
/* Description:
 * Implement the Vigenère cipher for uppercase letters.
 * Shift of 'A' is 0, 'B' is 1, ..., 'Z' is 25.
 * If the key is shorter than the word, repeat the key as needed.
 * Read: two integers (lengths), then word and key on two lines.
 * Print the encrypted word.
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
   int wordLen, keyLen;
   if (scanf("%d %d", &wordLen, &keyLen) != 2) {
      return 0;
   }

   /* Buffers: allow extra space for safety */
   char word[2505], key[2505];
   scanf("%s", word);
   scanf("%s", key);

   int n = (int)strlen(word);
   int m = (int)strlen(key);

   for (int i = 0; i < n; i++) {
      int shift = key[i % m] - 'A';      /* convert 'A'..'Z' to 0..25 */
      int base = word[i] - 'A';          /* convert 'A'..'Z' to 0..25 */
      int enc = (base + shift) % 26;     /* apply shift and wrap around */
      word[i] = (char)('A' + enc);
   }

   printf("%s\n", word);
   return 0;
}