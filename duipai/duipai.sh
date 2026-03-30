#!/bin/bash

# 1. 编译三个 C++ 文件
echo "Compiling..."
g++ rand.cpp -o rand -O2 -std=c++20
g++ sta.cpp -o sta -O2 -std=c++20
g++ test.cpp -o test -O2 -std=c++20

if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

echo "Compilation successful. Starting stress test..."

# 2. 循环对拍
i=1
while true; do
    # 生成随机数据
    ./rand > data.in
    
    # 分别运行两个程序
    ./sta < data.in > sta.out
    ./test < data.in > test.out
    
    # 比较输出文件 ( -w 参数表示忽略行末空格等空白字符的差异，防止误判)
    # 比较长度可以用 awk，但因为这题正确代码和贪心代码输出的字符串可能不一样，但长度必须一样
    # 如果输出具体字符串不同算错，就直接 diff。
    # 针对这道题，我们最好比较它们的 **输出字符串长度** 是否一致：
    
    len_std=$(awk '{print length($0)}' sta.out)
    len_test=$(awk '{print length($0)}' test.out)
    
    if [ "$len_std" == "$len_test" ]; then
        echo "Test $i: AC (Length: $len_std)"
    else
        echo -e "\033[31mTest $i: WA! Hack data found!\033[0m"
        echo "Input data:"
        cat data.in
        echo "-------------------"
        echo "Correct Output (Length: $len_std):"
        cat std.out
        echo "Your Output (Length: $len_test):"
        cat test.out
        echo "-------------------"
        break # 找到错误数据，跳出循环
    fi
    ((i++))
done