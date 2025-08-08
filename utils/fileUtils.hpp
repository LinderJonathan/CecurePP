#include <fstream>
#include <vector>

std::vector<unsigned char> readFileData(const std::string &filePath) {

    std::ifstream f(filePath, std::ios::binary);
    if (!f.is_open()) {
        throw std::runtime_error("Failed to open file for reading \n");
    }

    f.seekg(0, std::ios::end);
    std::streamsize bufSize = f.tellg();
    f.seekg(0, std::ios::beg);
    if (bufSize <= 0) {
        throw std::runtime_error("The read file is empty \n");
    }

    std::vector<unsigned char> buf(bufSize);
    f.read(reinterpret_cast<char *>(buf.data()), bufSize);

    f.close();
    return buf;
}