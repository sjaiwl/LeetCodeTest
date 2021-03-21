/**
读取日志文件, 日志文件中记录有每个URL的响应时间, 取出每一行的响应时间, 计算90线. 
URL后面的数字为响应时间(ms)。
即: 找出所有请求当中, 按照响应时间从短到长排序, 响应时间最短的排名在90%位置的请求的耗时.
要求：实现一个可以运行的类.
输入：日志文件路径. 文件路径从命令行输入, 文件内容格式如下:
2019-06-25 00:00:04,636|2310204|10936386|/phone/query_unread_list.json|11|limit=500&offset=0&corpid=19d30468566deffd|0|ok|0b0b05cc15613920046219000e07f0
2019-06-25 00:00:05,104|2310204|44783105|/phone/query_unread_list.json|19|limit=500&offset=0&corpid=19d30468566deffd|0|ok|0b0f849315613920050816363e06f2
2019-06-25 00:00:05,226|23665830|364278091|/v3/user/list|18|corpid=bc52122d6249fde335c2f4657eb6378f&offset=70&limit=10&title=%E8%80%83%E6%A0%B8|0|ok|0bb6452915613920051322908e0691
2019-06-25 00:00:05,422|2310204|347476672|/phone/query_unread_blackboard_list.json|23|limit=500&offset=0&corpid=19d30468566deffd|0|ok|0b0f7e9915613920053966743e0668

输出：90线的响应时间（即90%的用户感知到的页面响应时间）
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class LogRsqInfo
{
public:
    LogRsqInfo() {}
    ~LogRsqInfo() {}

    static LogRsqInfo &GetInstance()
    {
        static LogRsqInfo instance;
        return instance;
    }

    int GetRspTimeFromStr(const string &infoStr, int &output)
    {
        size_t firstSize = infoStr.find("/");
        if (firstSize == string::npos)
        {
            return 1;
        }

        string tmpStr = infoStr.substr(firstSize);
        size_t secondIndex = tmpStr.find("|");
        if (secondIndex == string::npos)
        {
            return 1;
        }

        tmpStr = tmpStr.substr(secondIndex + 1);
        secondIndex = tmpStr.find("|");
        if (secondIndex == string::npos)
        {
            return 1;
        }

        tmpStr = tmpStr.substr(0, secondIndex);
        output = stoi(tmpStr);
        return 0;
    }

    int GetResultNumWithFilePath(const string &filePath)
    {
        // 打开文件路径，获取文件内容
        ifstream readFile(filePath, std::ios::in);
        if (!readFile.is_open())
        {
            cout << "open file failed" << endl;
            return 1;
        }

        vector<int> rspTimeVec;
        string tmpStr;
        int tmpRsp;
        while (!readFile.eof() && getline(readFile, tmpStr))
        {
            // 解析响应时间
            if (GetRspTimeFromStr(tmpStr, tmpRsp) == 0)
            {
                rspTimeVec.push_back(tmpRsp);
            }
        }
        readFile.close();

        // 根据响应时间排序
        sort(rspTimeVec.begin(), rspTimeVec.end());

        // 获取90线响应时间
        int index = 0.9 * rspTimeVec.size();
        return rspTimeVec[index];
    }
};

int main()
{
    // /Users/wanglin/Downloads/test1/test.log
    // 从命令行读取文件路径
    string strFilePath;
    cin >> strFilePath;

    int num = LogRsqInfo::GetInstance().GetResultNumWithFilePath(strFilePath);
    cout << num << endl;

    return 0;
}