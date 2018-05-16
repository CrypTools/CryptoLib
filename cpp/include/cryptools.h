#ifndef CRYPTOOLS_H
#define CRYPTOOLS_H

#include <string>
#include <iostream>
#include <vector>

class Types
{
public:
    enum Text {
        Numbers,
        LowercaseAlphabet,
        UppercaseAlphabet,
        Alphabet,
        AlphaNum,
        Base64,
        Unicode
    };
    enum Case {
        Lowercase = Text::LowercaseAlphabet,
        Uppercase = Text::UppercaseAlphabet
    };
};

class CrypTools: public std::string
{
public:
    explicit CrypTools(std::string text);
//========================================================================
//                        Static public functions
//========================================================================
    static std::string toBase64(std::string plaintext);
    static std::string fromBase64(std::string cipher);
//========================================================================
    static std::string caesarEncrypt(int shift, std::string plaintext, Types::Text type = Types::Alphabet);
    static std::string caesarDecrypt(int shift, std::string cipher, Types::Text type = Types::Alphabet);
//========================================================================
    static std::string rot13(std::string input, Types::Case type = Types::Lowercase);
//========================================================================

    bool isNumber() const;
    bool isAlphabet() const;
    bool isAlphaNumerical() const;
    CrypTools binValueAt(unsigned int index) const;
    bool contains(char character) const;

    static unsigned int indexOfFirst(std::string array, char character);
    unsigned int indexOfFirst(char character) const;

    static std::string decToBin(unsigned int value);
//========================================================================
//                     Non-static public functions
//========================================================================
    std::string toBase64() const;
    std::string fromBase64() const;
//========================================================================
    std::string caesarEncrypt(int shift, Types::Text type = Types::Alphabet) const;
    std::string caesarDecrypt(int shift, Types::Text type = Types::Alphabet) const;
//========================================================================
    std::string rot13(Types::Case type = Types::Lowercase) const;
//========================================================================

private:

    bool containsWhat(const std::string text, char character) const;

    static long fromBin(long n);

    static std::string stringShift(std::string text, int shift = 0);
    static std::string stringShiftInArray(std::string array, std::string text, int shift = 0);
    static std::string toBin(int n);
    static std::string valueInRange(std::string text, unsigned int lower, unsigned int upper);
    static std::string base64Encrypt(std::string plaintext);
    static std::string base64Decrypt(std::string cipher);
    static std::string charMultiple(int times, char character);

};

#endif // CRYPTOOLS_H
