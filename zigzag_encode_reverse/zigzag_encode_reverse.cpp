#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    string str = "Weloveyouzhanchangfeng";

    string s1 = "";
    string s2 = "";

    int numRows = 5;
    
    if (numRows <= 1) {
        cout << str << endl;
        return 0;
    }

    vector<vector<char>> rows(numRows, vector<char>(str.size(), ' '));
    int idx = 0, d = -1, col = 0;

    for (char c : str) {
        rows[idx][col++] = c;
        if (idx == 0 || idx == numRows - 1) {
            d *= -1;
        }
        idx += d;
    }

    for (const auto& row : rows) {
        for (char element : row) {
            cout << (element == ' ' ? ' ' : element);
            if (element != ' ') s1 += element;
        }
        cout << endl;
    }

    //reverse
    int pz = 0;
    for (auto& row : rows){
        for (char& element : row){
            if (element != ' '){
                element = str[pz];
                pz++;
            }
        }
    }

    //output reversed string
    for (const auto& row : rows) {
        for (char element : row) {
            cout << (element == ' ' ? ' ' : element);
        }
        cout << endl;
    }

    int currentRow = 0;
    d = -1;
    for(col = 0; col < str.size(); col++){
        s2 += rows[currentRow][col];

        if (currentRow == 0 || currentRow == numRows - 1){
            d *= -1;
        }
        currentRow += d;
    }

    cout << s1 << endl << s2 << endl;
    return 0;
}
