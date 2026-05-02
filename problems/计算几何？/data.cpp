#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

void run_command(const string &cmd)
{
    int ret = system(cmd.c_str());
    if (ret != 0)
    {
        cerr << "命令执行失败: " << cmd << endl;
    }
}

int main()
{
    int num_tests = 20; // 生成 10 组数据

    // 1. 编译生成器和解题程序
    cout << "正在编译程序..." << endl;
    run_command("g++ gen.cpp -o gen -O2");
    run_command("g++ sol.cpp -o sol -O2");

    // 2. 循环生成数据
    for (int i = 1; i <= num_tests; ++i)
    {
        string id = to_string(i);
        string in_file = "data" + id + ".in";
        string out_file = "data" + id + ".out";

        cout << "正在生成测试点 #" << id << "..." << endl;

        // 生成输入文件: 运行 gen 并重定向到 .in
        // Linux/Docker 环境下使用 ./gen
        run_command("./gen > " + in_file);

        // 生成输出文件: 运行 sol 读取 .in 并重定向到 .out
        run_command("./sol < " + in_file + " > " + out_file);
    }

    cout << "\n所有测试点已生成完毕！" << endl;
    return 0;
}