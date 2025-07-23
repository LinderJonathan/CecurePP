#pragma once

// TODO: use cryptopp or openssl to generate RSA private and public key -> store private key in pkcs8?

class KeyHandler
{
private:
    /* data */
public:
    KeyHandler(/* args */);
    ~KeyHandler();

    int generateKeyPair(int bits);
    int storeKeyPair();
};


// For file signing and verification, the private key should be generated and stored securely and kept absolutely confidential. Here’s what I’d recommend:

// 1. Generate the private key securely, ideally using a well-established cryptographic library (e.g., OpenSSL, libsodium, or a language-specific crypto API) that uses a strong random number generator.

// 2. Store the private key encrypted at rest with a strong passphrase if it needs to be persisted on disk. Use a format like PKCS#8 with encryption.

// 3. If possible, store the private key in a hardware security module (HSM) or secure element, or use OS-level secure storage (Keychain on macOS, DPAPI on Windows, etc.) to minimize exposure.

// 4. Avoid hardcoding or embedding the private key in your source code or binaries.

// 5. Limit private key access strictly to processes or users that require it for signing.