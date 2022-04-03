# PDE

***
>[pde.h](https://github.com/SekaiGao/PDE/blob/main/pde.h)
***

# [偏微分方程](https://github.com/SekaiGao/PDE)

>**说明:** Prdinary differential equations.
>
>注意所有pde求解函数被放置于命名空间pde中。
>
>**使用方法:** 你应该配置好cpp环境,然后将该头文件及matrix.h与.cpp文件置于同一个文件夹下。
>
>[一个例子。](https://github.com/SekaiGao/PDE/blob/main/example.cpp)

### 1.波动方程

```cpp
void wave_eq(F f,F diff,F flt,F frt,ls x,ls t,ld c,int M=10,int N=10,const char*file="wave.csv")
```

