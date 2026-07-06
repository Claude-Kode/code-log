# The essence of linear-algebra

感觉数学的本质上就就是抽象, 把我们要结局的问题抽象成式子,

然后根据一些数学上的规则, 然后就可以完全脱离问题的情景, 只用数学上的规则去解决问题, 这样解决问题的时候就不会因为一些情景里面的直觉影响思考从而乱套

## linear-space

有原点, 有向量集合, 向量之间有加法有数乘
每个向量都要有相反的向量
基于这样的规则产生的所有的向量都在空间内部
反例: 正实数轴 
符合这样的规则的空间就是线性空间

对于原点的定义我们必须有 v + oringin == v 

## linear-tranformation

the addition and multiplication between vectors

familiar to : input-vector-x  f(x) output-vector-x

这个过程中要遵循 2 rules : 
the oringin should be stay(原点不变)
原本是直线的地方在变换后依然是直线(比如坐标轴, 对角线)
另注 : 奇点是规则失效的点(类似算法的特判)

本质上线性变换就是满足
$$ 1. 零点不变: T(0) = 0 $$

$$ 2. 可加性: T(x + y) = T(x) + T(y) $$

$$ 3. 齐次性: T(k * x) = k * T(x) $$


## vector and matrix (extend to matrix multiplication)

我们用 row * col 来描述一个矩阵
所谓向量就是一个 row * 1 的一个矩阵, 我们可以这样理解
所谓矩阵就是一群 vector 的集合

实际上我们有一个
输入维度(定义域维度: domain dimension) : column
输出维度(值域维度: range dimension) : row 

给出个人的结论: 矩阵乘法本质上就是 a * b = c, 把 b 中的所有向量换成 a 的基后得到 c 

另特别注意, **矩阵乘法不满足交换律(Non-commutative)**


## linear dependence
举个例子 在一个二维 flat sheet 内部 两个共线 的 vector 就是线性相关的
所谓的线性相关就是 对于两个向量之间来说 他们之间有重叠的部分 
对于二维平面来说, 线性相关即为贡献, 此外互为线性无关
对于两个互相垂直的, 向量来说, 我们称他们是正交的

或者说新添加的向量可以用已有向量的 线性组合来表示

## basis 
the smallest set of vectors to generate the space 
the vectors must be linear independent

## rank
which is a concept in both matrix and vectors 
it symbols the decesive factors in the item 

in matrix, it means the numbers of dimensions of the matrix  
就是求 一个矩阵中的最大线性无关组的大小


![alt text](../Resources/image-3.png)

## Determinant
本质上是用来形容一个变换矩阵对原来的线性空间的影响
matrix multiplication : a * b == c
det(a) = |a| , |det(a)| = 变换后的基底对空间/平面的缩放大小, 也就是行列式的值
行列式值的绝对值形容的是对于线性空间的缩放大小
正负则是对手性的反转 : 比如常规的右手笛卡尔坐标系反转成左手系
笛卡尔系相当于由一组最大线性无关正交基构造的空间坐标系

那么我们再来理解一下为什么行列式就是把一个多元一次方程的系数抽出来
首先是这样的方程式子

|k11 * a1 + k12 * a2...| 
| 
|
|
这个过程相当于是我们对 a1 原本的基向量换了基
换成
|k11
 k12
 k13...

我们相当于是对每一个向量的基都换了, 抽出来得到的是一个转换矩阵
那么这个转换矩阵, 我们保证这个矩阵会保持原来的向量维度不变

![alt text](../Resources/image-1.png)
A就是转换矩阵, x 就是被转换的向量, v就是转换后的向量结果
一、从具体方程组到矩阵乘法

1. 标准形式

一个 m 个方程、n 个未知数的线性方程组：

$$\begin{cases}
a_{11}x_1 + a_{12}x_2 + \cdots + a_{1n}x_n = b_1 \\
a_{21}x_1 + a_{22}x_2 + \cdots + a_{2n}x_n = b_2 \\
\quad\vdots \\
a_{m1}x_1 + a_{m2}x_2 + \cdots + a_{mn}x_n = b_m
\end{cases}$$

2. 写成矩阵乘法形式

系数矩阵 A：

$$A = \begin{bmatrix}
a_{11} & a_{12} & \cdots & a_{1n} \\
a_{21} & a_{22} & \cdots & a_{2n} \\
\vdots & \vdots & \ddots & \vdots \\
a_{m1} & a_{m2} & \cdots & a_{mn}
\end{bmatrix}_{m \times n}$$

变元向量 $$\mathbf{x}：$$

$$\mathbf{x} = \begin{bmatrix} x_1 \\ x_2 \\ \vdots \\ x_n \end{bmatrix}_{n \times 1}$$

结果向量 $$\mathbf{b}：$$

$$\mathbf{b} = \begin{bmatrix} b_1 \\ b_2 \\ \vdots \\ b_m \end{bmatrix}_{m \times 1}$$

矩阵方程：

$$A \mathbf{x} = \mathbf{b}$$

二、具体例子（一步步对照）

例1：2个方程，2个未知数

方程组：

$$\begin{cases}
2x + 3y = 5 \\
x - y = 2
\end{cases}$$

写成 $$A\mathbf{x} = \mathbf{b}：$$

1. 提取系数矩阵 A：
• 第一个方程系数：$2, 3 → 第一行：[2, 3]$
• 第二个方程系数：$1, -1 → 第二行：[1, -1]$
$$   A = \begin{bmatrix} 2 & 3 \\ 1 & -1 \end{bmatrix}$$
   

2. 变元向量 $ \mathbf{x}：$
   
  $$ \mathbf{x} = \begin{bmatrix} x \\ y \end{bmatrix}$$

3. 结果向量 $\mathbf{b}：$
   
  $$ \mathbf{b} = \begin{bmatrix} 5 \\ 2 \end{bmatrix}$$
   

4. 验证矩阵乘法：
   
  $$ A\mathbf{x} = \begin{bmatrix} 2 & 3 \\ 1 & -1 \end{bmatrix} \begin{bmatrix} x \\ y \end{bmatrix} = \begin{bmatrix} 2x + 3y \\ 1x + (-1)y \end{bmatrix} = \begin{bmatrix} 5 \\ 2 \end{bmatrix}$$
   
   这正好对应原方程组。

例2：3个方程，2个未知数（超定方程组）

方程组：

$\begin{cases}
x + 2y = 1 \\
3x + 4y = 2 \\
5x + 6y = 3
\end{cases}$

矩阵形式：

$$ \begin{bmatrix} 1 & 2 \\ 3 & 4 \\ 5 & 6 \end{bmatrix}  $$

$\underbrace{\begin{bmatrix} 1 & 2 \\ 3 & 4 \\ 5 & 6 \end{bmatrix}}_{A} 
\underbrace{\begin{bmatrix} x \\ y \end{bmatrix}}_{\mathbf{x}} = \underbrace{\begin{bmatrix} 1 \\ 2 \\ 3 \end{bmatrix}}_{\mathbf{b}}$

这里 A 是 $3 \times 2$ 矩阵（不是方阵，没有行列式）。

PS : 我们备注这样的可以转化过去的方程叫做线性方程组

三、连接你的"线性变换"视角

你之前理解的"矩阵是换基"，在这里体现为：

$A\mathbf{x} = \mathbf{b}$ 的几何解释：
• 矩阵 A 的每一列是一个向量（新基向量）。

• $ \mathbf{x} $ 是这些基向量的线性组合系数（在新基下的坐标）。

• $ \mathbf{b} $ 是在标准基下这个线性组合的结果。

用你的话说：
矩阵 A 定义了"新基"，$\mathbf{x}$ 是"在新基下的坐标"，$\mathbf{b}$ 是"在标准基下的位置"。

解方程：已知 A（新基）和 \mathbf{b}（目标位置），求 $\mathbf{x}$（在新基下的坐标）。

四、为什么这是"线性变换"？

因为映射 $f: \mathbb{R}^n \to \mathbb{R}^m 定义为 f(\mathbf{x}) = A\mathbf{x}$ 是一个线性变换：
1.$f(\mathbf{u} + \mathbf{v}) = A(\mathbf{u}+\mathbf{v}) = A\mathbf{u} + A\mathbf{v}$
2. $f(k\mathbf{u}) = A(k\mathbf{u}) = kA\mathbf{u}$

这正是你最初理解的"线性变换"的代数实现。

五、总结：你的框架的完美对应

你的概念 对应矩阵方程 $$ A\mathbf{x} = \mathbf{b}$$

线性变换 矩阵 A 代表的映射

输入向量 变元向量 $\mathbf{x}$

输出向量 结果向量 $\mathbf{b}$

解方程 寻找 $\mathbf{x}$ 使得变换后得到 $\mathbf{b}$

奇点 $(\det=0)$ 当 A 是方阵且 $\det(A)=0$ 时，变换不可逆

最终形式：

$$\boxed{A_{m \times n} \ \mathbf{x}_{n \times 1} = \mathbf{b}_{m \times 1}}$$

这就是多元一次方程组的矩阵乘法标准形式，也是你所有几何直觉的代数基石。


我们是可以这样说的
![alt text](../Resources/image.png) 如图所示 这样很容易看出为什么行列式的值为 0 的时候方程无解了 
这意味着 det(a) == 0 代表行列式代表的那个转换矩阵 中 换的基底至少有两个是线性相关的
而如果出现这种情况 维度就会缩小一维, 导致有一维的向量是无解的
本质上就是变换矩阵化简以后是非满秩的, 

## the inverse matrix 
逆矩阵写作 $ A^{-1} $ 
我们一般有一个 $ A^{-1} \times A = \begin{bmatrix} 1 & 0 \\ 0 & 1 \end{bmatrix}(rank = 2)$ 
抽象的 我们可以理解成 普通的矩阵是一个正向的转换, 逆矩阵是对正向转换 的逆过程 
那么逆矩阵存在的条件就是, 
$ det(A) \ne 0$
我们可以这样的来想, 当 $ det(A) = 0$ 的时候会出现维度被压缩的情况
是么有任何函数可以执行一个过程叫做 面 解压缩成 体这样的过程的
因为在这种情况下, 比如我们在被压缩成后的线上指定一个解, 然后还原回去, 我们会发现一个输入向量转化成了一整条线 
![alt text](../Resources/image-2.png) 
而函数只能是一个输入转成一个输出

## column space  
我们可以把一个矩阵看作一群 vector 的集合, 那么一个矩阵内部所有的向量互相相加 或者 数乘 之后能站成的空间就叫做列空间 

所以其实 **rank equal to the number of dimesion of the column space**

## null space && kernle of matrix
在之前那张 矩阵 描述出把一个空间压缩的时候
当单位的空间被压缩成二维的时候, 会有一整个平面的向量 压缩到那个原点
![alt text](../Resources/image-5.png)
![alt text](../Resources/image-4.png)
![alt text](../Resources/image-6.png)

$ A \times \vec{x} = \vec{v} $ 且 $ \vec{v} = \begin{bmatrix} 0 \\ 0 \end{bmatrix} $ 
所以 零空间相当于给出一个 这个方程中 $ \vec{x} $ 的解的集合
0 空间就是这个方程的结果向量 $ \vec{v} $ 为 oringin 的时候方程的解的集合
 
## dot product 
所谓向量的点积 就是把向量每个维度的积加起来
得出的结果相当于 
$ \vec{a} \cdot \vec{b} = res $
$ \vec{a} $ 在 $ \vec{b} $ 上的投影长度 $ \times $ $ \vec{b} $ 的长度
当两者的夹角小于 `90` 度的时候 点积为正
等于 90 度的时候 点积为 `0`
大于九十度的时候, 小于 `0` 

本质上点积想当于把一个向量 `a` 压缩为一维数轴上的一个向量
而这个向量的位置就是 `b`

本质上相当于把向量 `b` 转置之后进行矩阵乘法

此时的 转置矩阵相当于一个 描述一个线性变换的矩阵(你可以理解为一个函数 专门把指定维数的向量变成一个实数轴上的数字)
那么有 `[1 * n]` 的矩阵 $ \times $ `[n * 1]`的矩阵, 
最后得到一个$1 \times 1$的矩阵

那么这个逻辑就是自洽的, 点积的乘积会得到一个数字, 转置乘法后的矩阵乘法也是

所以这样的逻辑同样可以解释, 为什么点积的结果等同于 $ \vec{a} $ 在 $ \vec{b} $ 上的投影 乘以 $ |\vec{b}|$ 

## linearity
线性性用来描述一个变换，是否允许"先操作后变换"和"先变换后操作"结果一样
  一般来说线性性要满足两个条件: 
superosition(可加性): f(x + y) = f(x) + f(y)  
homogeneity(齐次性) : f(a * x) = a * f(x)
Lemma: f(0) = 0

在几何上可以表示为
oringin dont change
the line still be line(no matter the corrdinate or the diagonal)
那么为什么点积回合投影这个东西相关呢

我们可以来想象一下, 在一个二维平面上 出现一条经过原点的直线
然后我们把这个而二维平面压缩到这个直线上
这个过程本质上是一次线性变换, 也就是相当于对这个二维平面的基向量进行一次矩阵乘法
同时这个过程也可以抽象成一个函数, 这个函数我们可以通过线性性检验来判断他是否是线性醒的
证毕后, 这是一个线性变换, 所以过程可以用一个矩阵来表示,
我们可一把压缩的直线在原来的二维平面中表示出来, 可以看到这一条直线是一个数轴, 也同时是改二维平面中的一个向量
我满再来看这个线性变换的过程, 其实就是相当于所有的向量的终点都变成了一个这个数轴上的投影

对于这样的线性变换 我们再去寻找一个变换的矩阵, 我们可以这样观察, 观察原来的二维平面的基向量(1, 0) 和(0, 1)变成啥了 然后拼接成一个矩阵 就是这个变换矩阵
![alt text](../Resources/image-7.png)

然后最后可以证明 这个转换矩阵的值就是 转换后数轴上的单位向量(我们可一把压缩的直线在原来的二维平面中表示出来)

这个结论是怎么推出来的呢 如图
![alt text](../Resources/image-8.png)
这里运用到了对偶性, 好牛逼卧槽

所以两个向量的点积相当于把一个转置之后 做一个矩阵乘法, 然后最后的数就是压缩成一个数轴上的向量
也就是变换矩阵是这样的 我们设一个数轴上的单位向量是 $ \vec{u} $
变换矩阵如下 :
$$ \begin{bmatrix} u_x & u_y \end{bmatrix} $$  
请注意 这里的 $ \vec{u} $ 是一个单位向量, 单位向量
对于非单位向量, 由于线性性我们可以把它换成单位向量的 k 倍,
也就是说 单位向量的长度是 1, 他的长度是 k
那么最终的转置结果就是 
$$ \vec{a} \times \vec{b} = len(a) \times \operatorname{proj}_{\mathbf{a}} \mathbf{b}$$
**或者这样说 其实向量的 点积是表示线性变换的矩阵乘法的特殊形式**
这里给你的启发是 你在任何时候看到一个线性变换 他的输出空间是一维数轴, 也就是一个值无论他是如何定义的空间中会存在唯一的向量 v 与之相关

## cross product 
叉积可以得到以两个向量为边产生的平行四边形的面积

但实际叉积只存在于 三维向量 和 七维向量
而且实际上他并不产生一个数字, 而是产生一个对于当前平面的法向量, 他的模长为平行四边形的面积, 而且他的方向是右手定则判断的
![alt text](../Resources/image-9.png)

## The changed basis of system
对于一个向量 $ \vec{v} $, 我们是在 `I` 的语义下来形容他的
现在我们想换一个坐标系 $ I_1 $ 直接把 $ \vec{v} $ 应用一个线性变换即可得到
得到什么呢? $ \vec{v} $ 在 I 的语义下, 位于 $ I_1 $ 坐标系 的坐标
实际上在 

具体来说就是一个问题
如何用 $ I_1 $ 坐标基描述一个线性变换? 
![alt text](../Resources/image-10.png)
$ I_1^{-1} \times A \times I_1 $

本质上是这样的 一个向量 $ \vec{v} $ 在两个基底中是不相同的
转换基底本质删可以写作一种线性变换
这种转换本质上是 $ \vec{v} $ 向量在 $ I_2 $ 基底中 $ I_1 $ 的表示 就是这样!

## Eigenvector && Eigenvalue
特征向量指的是 对于一个线性变换, 其中有些向量并不发生任何的 ratated 而只有 scale
我们称这样的 vector 为 eigenvector, scale 的倍数为 eigenvalue

notices: eigenvalue can be negative, reveses is envolve in scale 

eigenvector can be though of as the axes of rotation in a lienar transformation
旋转轴

如果你算出的特征向量足够 span 出一个同样的空间, 那么不妨用你算出的特征向量换基
这样很明显是很好算的, 因为如果我们的特征向量就是基向量的阿话 这样的一个线性变换对应的矩阵是一个对角矩阵
而对角矩阵是非常方便运算的

```
 一个线性变换, 等于先变为他的特征向量组的基底, 再进行特征值的缩放
```
这个对角矩阵本质上也形容一种线性变换 只不过是 换了基底的语义下
所以为了方便运算
先换基 然后直接算对角矩阵, 最后再用换基的逆矩阵就可以算的很快
此处的换的那个"基"就是线性变换的特征向量组组成的基底

## What does vector space exactly is ???  
![alt text](../Resources/image-11.png)
![alt text](../Resources/image-12.png)

矩阵乘法之所以是乘法, 因为他本质上是换基, 通过预先知道的规则, 对于这些基底进行数乘, 相加得到新的矩阵

点积是一种函数的运算形式的简化吗, 本质上是矩阵乘法, 但是可以写作两个向量之间直接的相乘

```
Abstractness is the price of generality
```

从"基础解系"开始，你触及的概念链条，精炼如下：

---

**1. 解空间（零空间）**
- 所有满足 \(A\vec{x} = \vec{0}\) 的向量 \(\vec{x}\) 的集合。
- 几何上：被线性变换 \(A\) **完全压扁到原点**的那部分空间。

**2. 秩**
- 线性变换后**幸存**下来的空间维度（列空间的维度）。
- 也就是矩阵 \(A\) 真正"有效"的行/列数。

**3. 维数定理**
- \(\text{初始维度} = \text{秩} + \text{解空间维度}\)
- 几何上：原空间的每一维，变换后要么幸存（计入秩），要么被压扁消失（计入解空间）。

**4. 基础解系**
- 解空间（零空间）的**一组基底**。
- 由"极大线性无关"的解向量组成，能撑起整个"被压扁掉的空间"。
- 向量个数 = 解空间维度 = 初始维度 − 秩。

**5. 自由变元**
- 矩阵化为行最简形后，**没有主元**的列对应的变量。
- 本质：它们代表的维度是**冗余的**——这些列可以被主列线性表出，所以有一个能自由游走的方向，就代表解空间的一个维度。
- 数量 = 解空间维度。

**6. 代入规则**
- 自由变元**轮流置 1，其余置 0**，回代解出主变量。
- 本质：在零空间里，沿着每个自由维度方向各走一个"单位步长"，取到的向量自然线性无关，构成一组基。

---

**一句话动画：**
矩阵 \(A\) 是一台压扁空间的机器。秩告诉你压完后还剩几维；解空间告诉你哪些部分被压进原点消失了。基础解系，就是为那片"消失的废墟"画出的骨架地图。