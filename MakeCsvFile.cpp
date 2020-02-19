#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <experimental\filesystem>

using namespace std;
namespace fs = std::experimental::filesystem::v1;


vector<string> a;
string in, tmp, text, route;
char c;
int main() {
    cout << "경로를 입력하면 해당 경로의 txt파일을 읽어들여 file명 : file 내용의 값을 갖는 csv 파일을 만드는 프로그램 입니다\n\n";

    while (1) {
        cout << "*** Enter The Path *** \n";

        cin >> in;

        if (in == "EOF") {
            cout << "Exit... \n";
            break;
        }

        ofstream writer;
        ifstream reader;

        writer.open(in + "\\path.csv");

        for (auto& p : fs::directory_iterator(in)) {
            tmp = p.path().filename().u8string();

            if (tmp.back() == 't') {
                a.push_back(tmp);
                reader.open(p.path());
                if (!reader.is_open()) {
                    cout << "error : file is not opened \n";
                    break;
                }
                
                cout << "current File : " << tmp << endl;
                
                writer << tmp << ',';

                // read until the end of file to text
                while (1) {
                    reader >> c;

                    if (reader.eof())
                        break;
                    
                    else if (c == ',' || c == '\"' || c == '\'' || c == '\n' || c == '\t') {
                        writer << ' ';
                        continue;
                    }
                    else {
                        writer << c;
                    }
                }
                writer << '\n';
                reader.close();

                cout << tmp << " finished \n\n";
            }
        }
    }
}
