#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include "json.hpp"

using json = nlohmann::json;

std::ofstream outFile("bookmarks.json");
std::ifstream inFile("bookmarks");
json js;

void parse(json obj) {
    for (json::iterator it = obj["children"].begin();it != obj["children"].end(); ++it) {
        json child = (json)*it;
        if (child["type"] == "url") {
            outFile << "<bookmark href=" << child["url"].erise() << ">" << std::endl
                        << "\t<title>"
                            << child["name"]
                        << "</title>" << std::endl
                    << "</bookmark>" << std::endl ;
        } else if (child["type"] == "folder") {
            outFile << "<folder folded=\"yes\">" << std::endl
                        << "\t<title>"
                            << child["name"]
                        << "</title>" << std::endl;
            parse(child);
            outFile << "</folder>" << std::endl;
        };
    };
};

#endif // HEADER_H_INCLUDED
