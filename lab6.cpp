#include <iostream>
#include <string>

std::string encRLE(const std::string& source) {
    std::string encoded = "";
    int count = 1;

    for (int i = 1; i < source.length(); i++) {
        if (source[i] == source[i - 1]) {
            count++;
        } else {
            while (count > 255) {
                encoded += source[i - 1];
                encoded += "255";
                count -= 255;
            }
            encoded += source[i - 1];
            encoded += std::to_string(count);
            count = 1;
        }
    }

    while (count > 255) {
        encoded += source[source.length() - 1];
        encoded += "255";
        count -= 255;
    }
    encoded += source[source.length() - 1];
    encoded += std::to_string(count);

    return encoded;
}

std::string decRLE(const std::string& encoded) {
    std::string decoded = "";
    int i = 0;

    while (i < encoded.length()) {
        char character = encoded[i++];
        int count = 0;

        while (i < encoded.length() && isdigit(encoded[i])) {
            count = count * 10 + (encoded[i] - '0');
            i++;
        }

        for (int j = 0; j < count; j++) {
            decoded += character;
        }
    }

    return decoded;
}

int main() {
    std::string source;
    std::cout << "Enter a string: ";
    std::cin >> source;

    std::string encoded = encRLE(source);
    std::string decoded = decRLE(encoded);

    std::cout << "Encoded: " << encoded << std::endl;
    std::cout << "Decoded: " << decoded << std::endl;

    return 0;
}
