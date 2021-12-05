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
    const char *key = "verycoolhmackey";
    const char *hmac_test[3] = {
        "PoS make the rich even richer.",
        "abc",
        "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"
    };
    const char *sha_test[3] = {
        "Proof-Of-Work requires pre-image resistance of the hash function, "
        "not the collision resistance.",
        "abc",
        "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"
    };

    uint8_t i, j;
    uint8_t d[SHA1_DIGEST_SIZE];

    /* Print HMAC SHA1 digest */
    printf("Testing SHA1:\n");
    for (i = 0; i < 3; i++) {
        SHA1_Buf(sha_test[i], strlen(sha_test[i]), d);

        printf("SHA1('%s') = ", sha_test[i]);
        for (j = 0; j < SHA1_DIGEST_SIZE; j++) {
            printf("%02X", d[j]);
        }

        printf("\n");
    }

    /* Print HMAC SHA1 digest */
    printf("\nTesting HMAC SHA1 (key = '%s'):\n", key);
    for (i = 0; i < 3; i++) {
        HMAC_SHA1_Buf(key, strlen(key), hmac_test[i], strlen(hmac_test[i]), d);

        printf("HMAC_SHA1('%s') = ", hmac_test[i]);
        for (j = 0; j < SHA1_DIGEST_SIZE; j++) {
            printf("%02X", d[j]);
        }
    
        printf("\n");
    }

    return 0;
}