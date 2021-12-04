/* gcc -std=c89 test.c sha1.c -o test */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "sha1.h"

/*
Test Vectors (from FIPS PUB 180-1)
"abc"
  A9993E364706816ABA3E25717850C26C9CD0D89D
"abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"
  84983E441C3BD26EBAAE4AA1F95129E5E54670F1
*/

int main() {
    const char *test[3] = {
        "Proof-Of-Work requires pre-image resistance of the hash function, "
        "not the collision resistance.",
        "abc",
        "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"
    };

    uint8_t i;
    for (i = 0; i < 3; i++) {
        uint8_t digest[SHA1_DIGEST_SIZE];
        SHA1_Buf(test[i], strlen(test[i]), digest);

        /* Print digest */
        uint8_t j;
        for (j = 0; j < SHA1_DIGEST_SIZE; j++) {
            printf("%02X", digest[j]);
        }

        printf("\n");
    }

    return 0;
}