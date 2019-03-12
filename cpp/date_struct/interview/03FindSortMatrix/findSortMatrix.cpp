/*************************************************************************
    > File Name: findSortMatrix.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月12日 星期二 21时31分48秒
 ************************************************************************/

#include<iostream>
using namespace std;

bool Find(int* matrix, int rows, int columns, int number)
{
    if (matrix == NULL || rows < 0 || columns < 0) 
    {
        return false;
    }

    bool isFind = false;
    int row = 0;
    int col = columns-1;

    while (row < rows && col < columns)
    {
        if (number == matrix[row*columns+col]) 
        {
            cout << "find" << endl;
            isFind = true;
            break;

        }
        else if(number < matrix[row*columns+col])
        {
            col--;
        } 
        else
        {
            row++;
        }
    }

    return isFind;
}


int main(void) {
    int arr[4][4] = {
        {1,2,8,9},
        {2,4,9,12},
        {4,7,10,13},
        {6,8,11,15},
    };

    bool isFind = Find((int*)arr, 4, 4, 5);
    cout << isFind << endl;


    return 0;
}
