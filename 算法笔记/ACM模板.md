# Ubuntu ICPCOS

创建run.sh

```shell
#!/bin/bash 或者 #!/bin/sh
target=$1
src="${target}.cpp"
g++ -std=gnu++20 -O2 -Wall -Wextra "$src" -o "$target" && \
./"$target" 2>&1 | tee "${target}.txt"
```

随后chmod +x ./run.sh

./run.sh A

# 位运算

```c
popcount()//1的个数
countl_zero()//前导零
countr_zero()//后缀零
countl_one()//前导1
countr_one()//后缀1
has_single_bit()//是否只有一个1
bit_floor()	//向下取整到最近的2的幂
bit_ceil()	//向上取整到最近的2的幂
    
__builtin_popcount();//1的个数
__builtin_popcountll();
__builtin_clz();//前导零
__builtin_clzll();//ull
__builtin_ctz()//后缀零
__builtin_ctzll();//ull
```

# 向上向下取整

```c
int Ceil(int n1,int n2) {
    if (n2 == 0) return 0;
    int x=n1/n2;
    int r=n1%n2;
    if (r != 0 and !((n1 < 0)^(n2 < 0))) x++;
    return x;
}

int Floor(int n1,int n2) {
    if (n2 == 0) return 0;
    int x=n1/n2;
    int r=n1%n2;
    if (r != 0 and ((n1 < 0)^(n2 < 0))) x--;
    return x;
}
```

# 随机数

```c
int randINT(int l, int r) {
    static mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> distrib(l, r);
    return distrib(gen);
}
```

# 三分查找

```c
	//查找区间最大值,要求f是严格单峰
	auto f=[&](int x) {
		
	};

	int lo,hi,res; 
    while (hi-lo > 3) {
        int m1=lo+(hi-lo)/3;
        int m2=hi-(hi-lo)/3;
        if (f(m1) < f(m2)) lo=m1+1;
        else hi=m2-1;
    }
    res=f(lo);
    for (int i=lo+1;i<=hi;i++){
        res=max(res,f(i));
    }
```
