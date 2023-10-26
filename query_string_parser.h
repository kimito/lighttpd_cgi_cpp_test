#include<string>
#include<map>
#include<vector>

#include<iostream>

class QueryStringParser {
public:
    QueryStringParser(const std::string &query_string) {
        auto vec_attrs = split(query_string, "&");

        for(const auto &attr : vec_attrs) {
            auto kv = split(attr, "=");
            if(kv.size() == 2) {
                attrs[decodeURI(kv[0])] = decodeURI(kv[1]);
            }
        }
    }

    const std::string getAttribute(const std::string &key) {
        auto it = attrs.find(key);

        if(it == attrs.end()) {
            return "";
        }

        return it->second;
    }
private:
    std::map<std::string, std::string> attrs;

    
    std::vector<std::string> split(const std::string &str, const std::string &sep) {
        std::vector<std::string> ret;

        std::string::size_type current_pos = 0, next_pos;
        do {
            next_pos = str.find(sep, current_pos);
            auto elem = str.substr(current_pos, next_pos - current_pos);
            ret.push_back(elem);

            if(next_pos == std::string::npos) {
                break;
            }
            else {
                current_pos = next_pos + 1;
            }
        } while(true);

        return ret;
    }

    std::string decodeURI(const std::string &str) {
        std::string ret;

        std::string::size_type current_pos = 0, next_pos;
        do {
            next_pos = str.find("%", current_pos);
            ret.append(str.substr(current_pos, next_pos - current_pos));

            if(next_pos == std::string::npos) {
                break;
            }
            else {
                //parse HH of %HH of URL encode
                std::string str_code = str.substr(next_pos + 1, 2);
                char code = std::stoi(str_code, nullptr, 16);
                ret.push_back(code);

                current_pos += next_pos + 3;
            }
        } while( current_pos != std::string::npos );

        return ret;
    }
    
};