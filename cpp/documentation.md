# CryptoLib

The library consists in a set of functions inside the CrypTools class.

Most of them don't need an instance of the class to be used (they're `static`).

# Functions

## Base 64
### Encryption
#### From an instance
Encryption can be made from an instance with the function `CrypTools::toBase64()`.

No arguments are expected, and the cipher is returned as a std::string.

Example:

```cpp
CrypTools instance("Hello world");
std::string cipher = instance.toBase64();
std::cout << cipher << std::endl;
```
Result:

```
SGVsbG8gd29ybGQ=
```

#### Without an instance
Encryption can be made with no instance using the function `CrypTools::toBase64(std::string plaintext)`.

The plaintext must be passed as an std::string.

Example:

```cpp
std::cout << CrypTools::toBase64("Hello world") << std::endl;
```

### Decryption
The decryption is made the same way as the encryption with or without instance, 
except that the function's name is `CrypTools::fromBase64`.

Example without instance:

```cpp
std::cout << CrypTools::fromBase64("SGVsbG8gd29ybGQ=") << std::endl;
```
Result:

```
Hello world
```
