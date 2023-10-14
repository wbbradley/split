#include <iostream>
#include <string>
#include <vector>
#include <cctype>

std::vector<std::string> breakString(const std::string& input) {
    std::vector<std::string> result;
    std::string temp = "";
    char lastType = 0;

    for (char c : input) {
        char thisType = std::isdigit(c) ? 'D' : (std::isspace(c) ? 'S' : ((c==' ' || c=='=') ? 'W' : 'O'));

        if (lastType != 0 && (thisType != lastType) && ((thisType == 'D' && lastType != 'O') || (lastType == 'D' && thisType != 'O'))) {
            result.push_back(temp);
            temp = "";
        }

        temp += c;
        lastType = thisType;
        std::cout << "(temp='"<<temp<<"', ";
        std::cout << "lastType='"<<lastType<<"')\n";
    }

    if (!temp.empty()) {
        result.push_back(temp);
    }

    return result;
}

int main(int argc, char *argv[]) {
  std::string str;
  const char *delim = "";
  for (auto i=1;i<argc;++i) {
    str += delim;
    str += argv[i];
    delim = " ";
  }
    std::vector<std::string> result = breakString(str);

    for (const auto& s : result) {
        std::cout << "'" << s << "' ";
    }
    std::cout << std::endl;
    for (const auto& s : result) {
        std::cout << s;
    }
    std::cout << std::endl;

    return 0;
}
