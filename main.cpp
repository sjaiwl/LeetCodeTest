#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<list>

using namespace std;

int main() {

    queue<int> tmpQueue;
    tmpQueue.push(1);
    tmpQueue.push(2);
    tmpQueue.push(3);
    // tmpQueue.pop();
    int x = tmpQueue.front();
    int y = tmpQueue.back();

    list<int> tmpList;
    tmpList.push_back(1);
    tmpList.push_back(2);
    tmpList.push_back(3);


    cout << "test" << endl;
    system("pause");
    return 0;
}