#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<list>

using namespace std;

class MyClass {

public:
    static MyClass& instance() {
        static MyClass m_ins;
        return m_ins;
    }

    void Init() {
        cout << "Init" << endl;
    }

    void PrintStr() {
        cout << "PrintStr" << endl;
    }

private:
    MyClass() {

    }

    virtual ~MyClass() {

    }

private:
    string m_str;
};

class TestClass
{
private:
    string name;
    int id;
    string desc;

public:
    TestClass() {

    }

    ~TestClass() {

    }
};

void SplitString(const std::string &str, std::vector<std::string> &result, const std::string &pattern = ".")
{
    result.clear();
    if (str.empty()) {
        return;
    }

    string tmpStr = str + pattern;
    size_t tmpSize = tmpStr.size();

    size_t pos = tmpStr.find(pattern);
    while (pos != string::npos) {
        string subStr = tmpStr.substr(0,pos);
        result.push_back(subStr);
        tmpStr = tmpStr.substr(pos+1, tmpSize);
        pos = tmpStr.find(pattern);
    }
    return;
}

// 1比较两个版本号v1和v2，v1 > v2返回 -1， v1 < v2 返回1，其他返回0 ，例如输入：5.6.7.8  5.6.10  返回：1
int CompareVersion(const std::string& ver1, const std::string& ver2)
{
    // 版本号分割
    vector<string> ver1Vec;
    SplitString(ver1, ver1Vec);
    vector<string> ver2Vec;
    SplitString(ver2, ver2Vec);

    size_t ver1VecSize = ver1Vec.size();
    size_t ver2VecSize = ver2Vec.size();
    int num1 = 0;
    int num2 = 0;
    // 转化为整数逐个进行比较
    for (int i = 0; i < max(ver1VecSize, ver2VecSize); i++) {
        num1 = i < ver1VecSize ? stoi(ver1Vec[i]) : 0;
        num2 = i < ver2VecSize ? stoi(ver2Vec[i]) : 0;

        if (num1 != num2) {
            return num1 > num2 ? -1 : 1;
        }
    }

    return 0;
}

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

    MyClass::instance().Init();
    MyClass::instance().PrintStr();

    cout << CompareVersion("0.1", "1.1") << endl;

    cout << "test" << endl;
    system("pause");
    return 0;
}