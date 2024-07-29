#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <sstream>
using namespace std;

regex nameRegex("^[A-Z][a-z]*");
    regex ageRegex("\\d{2}");
    regex n1(R"(\+7\(\d{3}\)\d{3}-\d{4})");
    regex n2(R"(\+7\d{3}\d{3}\d{4})");
    regex n3(R"([7]{1}\d{10})");
    regex n4(R"([78]\d{3}\d{3}\d{4})");
    regex n5(R"(\+7\(\d{3}\)\-\d{3}-\d{2}-\d{2})");
    regex G(R"(g\.[A-Z]{3},)");
    regex Ul(R"(ul\.[A-Z]{1}\w*,)");
    regex D(R"(d\.\d{2,})");

bool isTrue (vector<string>& data) {
    size_t pos = 0;
    if (data.size() != 8) {
        return false;
    }

    if (regex_match(data[0], nameRegex) and regex_match(data[1], nameRegex) and regex_match(data[2], nameRegex) and
        regex_match(data[3], ageRegex) and (regex_match(data[4], n1) or regex_match(data[4], n2) or
                                              regex_match(data[4], n3) or regex_match(data[4], n4) or
                                              regex_match(data[4], n5)) and regex_match(data[5], G) and
        regex_match(data[6], Ul) and regex_match(data[7], D)) {
        return true;
    } 
    return false;
}

int main() {
    int M;
    cin >> M;
    cin.ignore();
    vector<bool> res(M);
    
    for (int i = 0; i < M; ++i) {
        vector<string> input;
        string str;
        getline(cin, str);
        string tmp;
        stringstream ss(str);

        while (getline(ss,tmp, ' ')) {
            input.emplace_back(tmp);
        }
        res[i]=isTrue(input);
    }
    for (int i = 0; i < M; ++i) {
        if (res[i])
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
}
