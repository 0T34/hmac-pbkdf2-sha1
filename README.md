hmac-pbkdf2-sha1
=========

Implementation of the SHA1 hash + HMAC + PBKDF2

## API

```
#include "sha1.h"

void SHA1_Buf(const void *in, size_t len, uint8_t d[SHA1_DIGEST_SIZE]);
void HMAC_SHA1_Buf(const void *k, size_t klen, const void *in, size_t inlen, uint8_t d[SHA1_DIGEST_SIZE]);
void PBKDF2_SHA1(const uint8_t *passwd, size_t passwdlen, const uint8_t *salt, size_t saltlen, uint64_t count, uint8_t *buf, size_t dkLen);
```
