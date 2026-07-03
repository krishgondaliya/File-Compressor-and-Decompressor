#include <iostream>
#include <string_view>

namespace {

void print_usage()
{
    std::cout
        << "huffzip - C++20 Huffman compressor/decompressor\n\n"
        << "Usage:\n"
        << "  huffzip --help\n"
        << "  huffzip compress <input> <output>\n"
        << "  huffzip decompress <input> <output>\n\n"
        << "Status:\n"
        << "  Day 1 skeleton only. Compression and decompression arrive in later steps.\n";
}

}  // namespace

int main(int argc, char* argv[])
{
    if (argc == 1 || std::string_view{argv[1]} == "--help" || std::string_view{argv[1]} == "-h") {
        print_usage();
        return 0;
    }

    std::cerr << "Unsupported command for Day 1 skeleton. Run `huffzip --help`.\n";
    return 1;
}
