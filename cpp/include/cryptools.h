#ifndef CRYPTOOLS_H
#define CRYPTOOLS_H

#include <string>
#include <iostream>
#include <vector>

class CrypTools: public std::string
{
public:
    explicit CrypTools(std::string text);

    bool isNumber() const;
    bool isAlphabet() const;
    bool isAlphaNumerical() const;
    CrypTools binValueAt(unsigned int index) const;
    bool contains(char character) const;

    unsigned int indexOfFirst(char character) const;

    static std::string decToBin(unsigned int value);

    std::string toBase64() const;
    std::string fromBase64() const;
    static std::string toBase64(std::string plaintext);
    static std::string fromBase64(std::string cipher);
private:

    bool containsWhat(const std::string text, char character) const;

    static long fromBin(long n);

    static std::string toBin(int n);
    static std::string valueInRange(std::string text, unsigned int lower, unsigned int upper);
    static std::string base64Encrypt(std::string plaintext);
    static std::string base64Decrypt(std::string cipher);
    static std::string charMultiple(int times, char character);

};

#endif // CRYPTOOLS_H
