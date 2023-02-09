#include <iostream>
#include <vector>
#include <string>

typedef unsigned char uchar;

static std::string base64_decode(const std::string &in) {

    std::string out;

    std::vector<int> T(256,-1);
    for (int i=0; i<64; i++) T["ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[i]] = i;

    int val=0, valb=-8;
    for (uchar c : in) {
        if (T[c] == -1) break;
        val = (val << 6) + T[c];
        valb += 6;
        if (valb >= 0) {
            out.push_back(char((val>>valb)&0xFF));
            valb -= 8;
        }
    }
    return out;
}

int main(void)
{
    const std::string encoded = "d2VsY29tZSB0byB0aGUgUEdHQSE=";

    std::string decoded = base64_decode(encoded);

    std::cout << decoded << std::endl;

    return 0;
}