#include "function.h"

int main()
{
    std::string html = ReadHTML(std::cin);

    std::string decodedHtml = DecodeHTML(html);

    PrintHTML(decodedHtml, std::cout);

    return 0;
}