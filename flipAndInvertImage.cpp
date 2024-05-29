//
// Created by L1584 on 2024/2/20.
//

#include "iostream"
#include "vector"
using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
    for (int count = 0; count < image.size(); count++) {
        vector<int> temp;   // 存放反转后的image[0]
        for (int i = image[0].size() - 1; i >= 0; i--) {   // 每次对image的第一个对象处理
            if (image[0][i] == 0)      // 反转temp中的每个值
                image[0][i] = 1;
            else if (image[0][i] == 1)
                image[0][i] = 0;
            temp.push_back(image[0][i]);
        }
        image.erase(image.begin());
        image.push_back(temp);
    }
    return image;
}

//int main() {
//    vector<vector<int>> image = {{1,1,0},{1,0,1},{0,0,0}};
//    image = flipAndInvertImage(image);
//    for (vector<int> row: image)
//        for (int item: row)
//            cout << item << " ";
//    return 0;
//}