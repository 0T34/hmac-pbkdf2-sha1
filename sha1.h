#ifndef _SHA1_H_
#define _SHA1_H_

#include <stdint.h>

/* Public API for Steve Reid's public domain SHA-1 implementation */
/* This file is in the public domain */

/** SHA-1 Context */
typedef struct {
    uint32_t state[5];
    /**< Context state */
    uint32_t count[2];
    /**< Counter       */
    uint8_t buffer[64]; /**< SHA-1 buffer  */
} SHA1_CTX;

/** SHA-1 Digest size in bytes */
#define SHA1_DIGEST_SIZE 20

void SHA1_Init(SHA1_CTX *context);
void SHA1_Update(SHA1_CTX *context, const void *p, size_t len);
void SHA1_Final(uint8_t digest[SHA1_DIGEST_SIZE], SHA1_CTX *context);
void SHA1_Buf(const void *in, size_t len, uint8_t digest[SHA1_DIGEST_SIZE]);

#endif /* !_SHA1_H_ */