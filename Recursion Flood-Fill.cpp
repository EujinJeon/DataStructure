#include <iostream>
using namespace std;

int WBconvert(char block[][10], int x, int y, int count) {
    if (block[x][y] == 'b') return count;
    
    count++;
    block[x][y] = 'b';
    count = WBconvert(block, x + 1, y,count);
    count = WBconvert(block, x - 1, y,count);
    count = WBconvert(block, x, y + 1,count);
    count = WBconvert(block, x, y - 1,count);
    return count;
}

int main()
{
    char block[10][10];
    int count = 0;
    int size[10];
    int array_s = 0;
    int white_area = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            block[i][j] = 'b';
        }
    }

    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (rand() % 2 == 0) block[i][j] = 'b';
            else block[i][j] = 'w';
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << block[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (block[i][j] == 'w') {
                size[array_s] = WBconvert(block, i, j, count);
                array_s++;
                white_area++;
            }
        }
    }

    cout << white_area << " white areas of ";
    int i = 0;
    while (i < white_area) {
        cout << size[i] << " ";
        i++;
    }
    return 0;
}