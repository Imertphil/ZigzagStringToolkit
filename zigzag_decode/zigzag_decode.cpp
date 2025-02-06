#include <bits/stdc++.h>

using namespace std;

int main(){
    // anyone reading this can get this? XD (hint: character's name)
    // didn't put them under the variables so if you want to change it to receive input it's more convenient I guess :D
    string str = "Wuneozaglyhhfoeacegvnn";
    int numRows = 5;

    // variables
    int cycleLength = 2 * numRows - 2;
    int numCycle = str.size() / cycleLength;
    int numLeftChar = str.size() % cycleLength - 1;
    int numChar = 0;
    string result = "";
    bool aLotLeftHa = false;

    // SMH, sigh, good job numLeftchar, let me fix you, hehe...
    if (numLeftChar >= numRows){
        numLeftChar -= numRows - 1;
        aLotLeftHa = true;
    }

    // the list
    vector<vector<char>> v(numRows);
    
    // separate chars to different rows
    // it's torture
    while(numChar < str.size()){
        if (numChar <= numCycle){
            v[0].push_back(str[numChar]);
        }
        else if (numChar >= str.size() - numCycle - 2){
            v[(numRows - 1)].push_back(str[numChar]);
        }
        else{
            //cause the for loop below will make the numChar go wrong and I can't find an easy way to fix it so anyway I add this int temp
            int temp = numChar;
            for (int numMedianRow = 1; numMedianRow <= numRows - 2; numMedianRow++){
                int numMedianChar = 2 * numCycle - 1;
                if (aLotLeftHa){
                    numMedianChar++;
                    if (numLeftChar > 0 && numMedianRow >= numRows - 1 - numLeftChar){
                        numLeftChar--;
                        numMedianChar++;
                    }
                }
                else {
                    if (numLeftChar > 0){
                        numLeftChar--;
                        numMedianChar++;
                    }
                }
                for (; numMedianChar >= 0 && temp <= str.size() - numCycle - 1; numMedianChar--){
                    v[numMedianRow].push_back(str[temp]);
                    temp++;
                }
            }
            // debugging these is pure torture... It's 2 am now, why am I still coding, it's Wednesday already...
            numChar = temp - 1;
        }
        numChar++;
    }

/* examples & correct outputs
Weloveyouzhanchangfeng
W     y     n     f   
 e   e o   a c   g e
  l v   u h   h n   n
   o     z     a     g

W       u       n     
 e     o z     a g
  l   y   h   h   f
   o e     a c     e g
    v       n       n

daeaiisidhoaxhjiiniy
d     a     e     a 
 i   i s   i d   h o
  a x   h j   i i   
   n     i     y
*/

    // test
    for (auto row : v){
        for (char a : row){
            cout << a << " ";
        }
        cout << endl;
    }

    // read through the list and get the final result

    // column's values are different
    int colS = 0;
    int colM = -1;
    int row = 0;
    int d = -1;
    // I hate you colS
    //int countForColS = 0;
    // oh wait colM is simultaneously increasing, badbye annoying variable

    for (int i = 0; i < str.size(); i++){
        // means it's at the top/bottom row of the list so
        if (row == 0 || row == numRows - 1){
            colM++;
            if (colM % 2 == 0 && colM > 0){
                colS++;
            }
            result += v[row][colS];
            d *= -1;
        }
        // for rows in the middle
        else{
            result += v[row][colM];
        }
        row += d;
    }

    cout << result << endl;

    // I did it ohhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
    // 2/5/2025, 2:22 a.m.
    // lmao why so many 2
    // anyways have a gooooood day gn
}