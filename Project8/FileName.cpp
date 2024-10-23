#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

int main(void)
{
    string user_id;
    cout << "ID: ";
    cin >> user_id;

    vector<string> problem_nums;
    string problem_num;
    cout << "Problem Number(Input until 0): ";
    while (1)
    {
        cin >> problem_num;
        if (problem_num == "0") // 0 입력되면 종료
            break;
        problem_nums.push_back(problem_num);
    }

    string url, cmd;
    // 각 문제 번호에 대한 url 열기
    for (auto& num : problem_nums)
    {
        url = "https://www.acmicpc.net/status?from_mine=1&problem_id=" + num + "&user_id=" + user_id;
        cmd = "start chrome \"" + url + "\"";
        system(cmd.c_str());
        Sleep(4000);
    }
    return 0;
}
