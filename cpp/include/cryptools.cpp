#include "cryptools.h"

std::string base10Numbers = "0123456789",
lowercaseAlphabet = "abcdefghijklmnopqrstuvwxyz",
uppercaseAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
alphabet = lowercaseAlphabet + uppercaseAlphabet;

CrypTools::CrypTools(std::string text):
    std::string(text)
{

}

bool CrypTools::isNumber() const
{
    std::string temp = *this;
    for (unsigned int i=0; i<temp.length(); ++i)
        if (containsWhat(base10Numbers, temp[i]) == false)
            return false;
    return true;
}

bool CrypTools::isAlphabet() const
{
    std::string temp = *this;
    for (unsigned int i=0; i<temp.length(); ++i)
        if (containsWhat(alphabet, temp[i]) == false)
            return false;
    return true;
}

bool CrypTools::isAlphaNumerical() const
{
    std::string temp = *this;
    for (unsigned int i=0; i<temp.length(); ++i)
        if (containsWhat(alphabet+base10Numbers, temp[i]) == false)
            return false;
    return true;
}

CrypTools CrypTools::binValueAt(unsigned int index) const
{
    return CrypTools(toBin((*this)[index]));
}

bool CrypTools::contains(char character) const
{
    return containsWhat(*this, character);
}

bool CrypTools::containsWhat(const std::string text, char character) const
{
    for (unsigned int i=0; i<text.length(); ++i)
        if (text[i] == character)
            return true;
    return false;
}

std::string CrypTools::toBin(int n)
{
    std::string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}

std::string CrypTools::valueInRange(std::string text, unsigned int lower, unsigned int upper)
{
    std::string r;
    if (upper == 0)
        upper = text.length();
    for (unsigned int i=lower; i < upper; i++)
        r += text[i];
    return r;
}

std::string CrypTools::charMultiple(int times, char character)
{
    std::string r;
    for (int i=0; i<times; ++i){
        r[i] = character;
    }
    return r;
}

long CrypTools::fromBin(long n)
{
    long factor = 1;
    long total = 0;

    while (n != 0)
    {
        total += (n%10) * factor;
        n /= 10;
        factor *= 2;
    }

    return total;
}

unsigned int CrypTools::indexOfFirst(char character) const
{
    unsigned int i;
    for (i=0; i<this->length(); ++i)
        if ((*this)[i] == character)
            return i;
    throw;
}

//========================================================================
//                        Public useful functions
//========================================================================

std::string CrypTools::decToBin(unsigned int value)
{
    return toBin(value);
}

//========================================================================
//                      Public encryption functions
//========================================================================

std::string CrypTools::toBase64() const
{
    return base64Encrypt(*this);
}

std::string CrypTools::toBase64(std::string plaintext)
{
    return base64Encrypt(plaintext);
}

//========================================================================
//                      Public decryption functions
//========================================================================

std::string CrypTools::fromBase64() const
{
    return base64Decrypt(*this);
}

std::string CrypTools::fromBase64(std::string cipher)
{
    return base64Decrypt(cipher);
}

//========================================================================
//                          Base64 functions
//========================================================================

std::string CrypTools::base64Encrypt(std::string plaintext)
{
    std::string out;

    int val=0, valb=-6;
    for (u_char c : plaintext) {
        val = (val<<8) + c;
        valb += 8;
        while (valb>=0) {
            out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(val>>valb)&0x3F]);
            valb-=6;
        }
    }
    if (valb>-6) out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[((val<<8)>>(valb+8))&0x3F]);
    while (out.size()%4) out.push_back('=');
    return out;
}

std::string CrypTools::base64Decrypt(std::string cipher)
{
    std::string out;

    std::vector<int> T(256,-1);
    for (int i=0; i<64; i++) T["ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[i]] = i;

    int val=0, valb=-8;
    for (u_char c : cipher) {
        if (T[c] == -1) break;
        val = (val<<6) + T[c];
        valb += 6;
        if (valb>=0) {
            out.push_back(char((val>>valb)&0xFF));
            valb-=8;
        }
    }
    return out;
}












