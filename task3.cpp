// Copyright 2018 Your Name <your_email>
#include <iostream>
#include "json.hpp"

using json = nlohmann::json;

int main() {
    nlohmann::json outputJson;
    auto j3 = json::parse("[\n"
                          "    [\"Si-9.15\", \"RTS-9.15\", \"GAZP-9.15\"],\n"
                          "    [100024, 100027, 100050],\n"
                          "    [\"Futures contract for USD/RUB\", "
                          "\"Futures contract for index RTS\", "
                          "\"Futures contract for Gazprom shares\"]\n"
                          "]");
    int tmp;

    for (int i = 0; i < j3[0].size(); ++i) {
        tmp = 0;
        while (tmp < j3.size()) {
            outputJson.push_back(
                    nlohmann::json
                            {
                                    {"ticker",      j3[tmp++][i]},
                                    {"id",          j3[tmp++][i]},
                                    {"description", j3[tmp++][i]},
                            }
            )
        }
    }
    std::cout << outputJson;
    return 0;
}
