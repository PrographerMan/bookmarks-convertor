#include "header.h"

int main(int argc, char* argv[]) {
    if (!outFile.good()) return 0;

    inFile >> js;
    parse(js["roots"]["bookmark_bar"]);
    return 0;
}
