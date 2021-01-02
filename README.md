# AtCoder

Playing [AtCoder](https://atcoder.jp/).

## Requirements

* gcc 9
* pipenv

## Setup

```sh
$ pipenv install
$ pipenv shell
```

## Usage

New contest

```sh
$ atcoder-tools gen {contest_id} --without-login --workspace .
```


Compile single task

```sh
$ gcc-9 -std=gnu++17 -g -Wall -lstdc++ -Wunused-result ./agc001/A/main.cpp -o ./agc001/A/main
```

Test single task

```sh
$ atcoder-tools test -d ./agc001/A
```

## Solved Problems

### AGC001

|Task|Solution|
|---|:---:|
|[A - BBQ Easy](https://atcoder.jp/contests/agc001/tasks/agc001_a)|[■](agc001/A/main.cpp)|
|[B - Mysterious Light](https://atcoder.jp/contests/agc001/tasks/agc001_b)|[■](agc001/B/main.cpp)|

### ABC042

|Task|Solution|
|---|:---:|
|[A - 和風いろはちゃんイージー](https://atcoder.jp/contests/abc042/tasks/abc042_a)|[■](abc042/A/main.cpp)|
|[B - 文字列大好きいろはちゃんイージー](https://atcoder.jp/contests/abc042/tasks/abc042_b)|[■](abc042/B/main.cpp)|
|[C - こだわり者いろはちゃん](https://atcoder.jp/contests/abc042/tasks/abc042_c)|[■](abc042/C/main.cpp)|

### DP

|Task|Solution|
|---|:---:|
|[A - Frog 1](https://atcoder.jp/contests/dp/tasks/dp_a)|[■](dp/A/main.cpp)|
|[B - Frog 2](https://atcoder.jp/contests/dp/tasks/dp_b)|[■](dp/B/main.cpp)|
|[C - Vocation](https://atcoder.jp/contests/dp/tasks/dp_c)|[■](dp/C/main.cpp)|
|[D - Knapsack 1](https://atcoder.jp/contests/dp/tasks/dp_d)|[■](dp/D/main.cpp)|
|[E - Knapsack 2](https://atcoder.jp/contests/dp/tasks/dp_e)|[■](dp/E/main.cpp)|
|[F - LCS](https://atcoder.jp/contests/dp/tasks/dp_f)|[■](dp/F/main.cpp)|
|[G - Longest Path](https://atcoder.jp/contests/dp/tasks/dp_g)|[■](dp/G/main.cpp)|
|[H - Grid 1](https://atcoder.jp/contests/dp/tasks/dp_h)|[■](dp/H/main.cpp)|
|[I - Coins](https://atcoder.jp/contests/dp/tasks/dp_i)|[■](dp/I/main.cpp)|
|[K - Stones](https://atcoder.jp/contests/dp/tasks/dp_k)|[■](dp/K/main.cpp)|
|[L - Deque](https://atcoder.jp/contests/dp/tasks/dp_L)|[■](dp/L/main.cpp)|
|[M - Candies](https://atcoder.jp/contests/dp/tasks/dp_M)|[■](dp/M/main.cpp)|
|[N - Slimes](https://atcoder.jp/contests/dp/tasks/dp_N)|[■](dp/N/main.cpp)|
|[O - Matching](https://atcoder.jp/contests/dp/tasks/dp_O)|[■](dp/O/main.cpp)|
|[P - Independent Set](https://atcoder.jp/contests/dp/tasks/dp_P)|[■](dp/P/main.cpp)|
|[Q - Flowers](https://atcoder.jp/contests/dp/tasks/dp_Q)|[■](dp/Q/main.cpp)|
|[R - Walk](https://atcoder.jp/contests/dp/tasks/dp_R)|[■](dp/R/main.cpp)|
|[S - Digit Sum](https://atcoder.jp/contests/dp/tasks/dp_S)|[■](dp/S/main.cpp)|
|[T - Permutation](https://atcoder.jp/contests/dp/tasks/dp_T)|[■](dp/T/main.cpp)|
|[U - Grouping](https://atcoder.jp/contests/dp/tasks/dp_U)|[■](dp/U/main.cpp)|
|[V - Subtree](https://atcoder.jp/contests/dp/tasks/dp_V)|[■](dp/V/main.cpp)|
|[W - Intervals](https://atcoder.jp/contests/dp/tasks/dp_W)|[■](dp/W/main.cpp)|
|[X - Tower](https://atcoder.jp/contests/dp/tasks/dp_X)|[■](dp/X/main.cpp)|

### ABC181

|Task|Solution|
|---|:---:|
|[A - Heavy Rotation](https://atcoder.jp/contests/abc181/tasks/abc181_a)|[■](abc181/A/main.cpp)|
|[B - Trapezoid Sum](https://atcoder.jp/contests/abc181/tasks/abc181_b)|[■](abc181/B/main.cpp)|
|[C - Collinearity](https://atcoder.jp/contests/abc181/tasks/abc181_c)|[■](abc181/C/main.cpp)|
|[D - Hachi](https://atcoder.jp/contests/abc181/tasks/abc181_d)|[■](abc181/D/main.cpp)|
|[E - Transformable Teacher](https://atcoder.jp/contests/abc181/tasks/abc181_e)|[■](abc181/E/main.cpp)|
|[F - Silver Woods](https://atcoder.jp/contests/abc181/tasks/abc181_f)|[■](abc181/F/main.cpp)|

### ABC180

|Task|Solution|
|---|:---:|
|[A - box](https://atcoder.jp/contests/abc180/tasks/abc180_a)|[■](abc180/A/main.cpp)|
|[B - Various distances](https://atcoder.jp/contests/abc180/tasks/abc180_b)|[■](abc180/B/main.cpp)|
|[C - Cream puff](https://atcoder.jp/contests/abc180/tasks/abc180_c)|[■](abc180/C/main.cpp)|
|[D - Takahashi Unevolved](https://atcoder.jp/contests/abc180/tasks/abc180_d)|[■](abc180/D/main.cpp)|
|[E - Traveling Salesman among Aerial Cities](https://atcoder.jp/contests/abc180/tasks/abc180_e)|[■](abc180/E/main.cpp)|

### ABC086

|Task|Solution|
|---|:---:|
|[A - Product](https://atcoder.jp/contests/abc086/tasks/abc086_a)|[■](abc086/A/main.cpp)|
|[C - Traveling](https://atcoder.jp/contests/abc086/tasks/arc089_a)|[■](abc086/C/main.cpp)|

### ABC064

|Task|Solution|
|---|:---:|
|[A - RGB Cards](https://atcoder.jp/contests/abc064/tasks/abc064_a)|[■](abc064/A/main.cpp)|

### ABC088

|Task|Solution|
|---|:---:|
|[A - Infinite Coins](https://atcoder.jp/contests/abc088/tasks/abc088_a)|[■](abc088/A/main.cpp)|
|[B - Card Game for Two](https://atcoder.jp/contests/abc088/tasks/abc088_b)|[■](abc088/B/main.cpp)|
|[C - Takahashi's Information](https://atcoder.jp/contests/abc088/tasks/abc088_c)|[■](abc088/C/main.cpp)|
|[D - Grid Repainting](https://atcoder.jp/contests/abc088/tasks/abc088_d)|[■](abc088/D/main.cpp)|

### ABC157

|Task|Solution|
|---|:---:|
|[A - Duplex Printing](https://atcoder.jp/contests/abc157/tasks/abc157_a)|[■](abc157/A/main.cpp)|

### ABC081

|Task|Solution|
|---|:---:|
|[A - Placing Marbles](https://atcoder.jp/contests/abc081/tasks/abc081_a)|[■](abc081/A/main.cpp)|
|[A - Shift only](https://atcoder.jp/contests/abc081/tasks/abc081_b)|[■](abc081/B/main.cpp)|
|[C - Not so Diverse](https://atcoder.jp/contests/abc081/tasks/abc081_c)|[■](abc081/C/main.cpp)|

### ABC095

|Task|Solution|
|---|:---:|
|[A - Something on It](https://atcoder.jp/contests/abc095/tasks/abc095_a)|[■](abc095/A/main.cpp)|
|[A - Bitter Alchemy](https://atcoder.jp/contests/abc095/tasks/abc095_b)|[■](abc095/B/main.cpp)|

### ABC085

|Task|Solution|
|---|:---:|
|[A - Already 2018](https://atcoder.jp/contests/abc085/tasks/abc085_a)|[■](abc085/A/main.cpp)|
|[B -  Kagami Mochi](https://atcoder.jp/contests/abc085/tasks/abc085_b)|[■](abc085/B/main.cpp)|
|[C - Otoshidama](https://atcoder.jp/contests/abc085/tasks/abc085_c)|[■](abc085/C/main.cpp)|

### ABC069

|Task|Solution|
|---|:---:|
|[B - i18n](https://atcoder.jp/contests/abc069/tasks/abc069_b)|[■](abc069/B/main.cpp)|

### ABC082

|Task|Solution|
|---|:---:|
|[B - Two Anagrams](https://atcoder.jp/contests/abc082/tasks/abc082_b)|[■](abc082/B/main.cpp)|

### ABC068

|Task|Solution|
|---|:---:|
|[B - Break Number](https://atcoder.jp/contests/abc068/tasks/abc068_b)|[■](abc068/B/main.cpp)|

### ABC053

|Task|Solution|
|---|:---:|
|[B - A to Z String](https://atcoder.jp/contests/abc053/tasks/abc053_b)|[■](abc053/B/main.cpp)|

### ABC072

|Task|Solution|
|---|:---:|
|[B - OddString](https://atcoder.jp/contests/abc072/tasks/abc072_b)|[■](abc072/B/main.cpp)|
|[C - Together](https://atcoder.jp/contests/abc072/tasks/arc082_a)|[■](abc072/C/main.cpp)|

### ABC113

|Task|Solution|
|---|:---:|
|[B - Palace](https://atcoder.jp/contests/abc113/tasks/abc113_b)|[■](abc113/B/main.cpp)|

### ABC102

|Task|Solution|
|---|:---:|
|[B - Maximum Difference](https://atcoder.jp/contests/abc102/tasks/abc102_b)|[■](abc102/B/main.cpp)|

### ABC087

|Task|Solution|
|---|:---:|
|[B - Coins](https://atcoder.jp/contests/abc087/tasks/abc087_b)|[■](abc087/B/main.cpp)|
|[C - Candies](https://atcoder.jp/contests/abc087/tasks/arc090_a)|[■](abc087/C/main.cpp)|

### ABC105

|Task|Solution|
|---|:---:|
|[B - Cakes and Donuts](https://atcoder.jp/contests/abc105/tasks/abc105_b)|[■](abc105/B/main.cpp)|

### ABC144

|Task|Solution|
|---|:---:|
|[B - 81](https://atcoder.jp/contests/abc144/tasks/abc144_b)|[■](abc144/B/main.cpp)|

### ABC133

|Task|Solution|
|---|:---:|
|[B - Good Distance](https://atcoder.jp/contests/abc133/tasks/abc133_b)|[■](abc133/B/main.cpp)|

### ABC175

|Task|Solution|
|---|:---:|
|[B - Making Triangle](https://atcoder.jp/contests/abc175/tasks/abc175_b)|[■](abc175/B/main.cpp)|

### ABC083

|Task|Solution|
|---|:---:|
|[B - Some Sums](https://atcoder.jp/contests/abc083/tasks/abc083_b)|[■](abc083/B/main.cpp)|
|[C - Multiple Gift](https://atcoder.jp/contests/abc083/tasks/arc088_a)|[■](abc083/C/main.cpp)|

### ABC090

|Task|Solution|
|---|:---:|
|[B - Palindromic Numbers](https://atcoder.jp/contests/abc090/tasks/abc090_b)|[■](abc090/B/main.cpp)|

### AGC025

|Task|Solution|
|---|:---:|
|[A - Digits Sum](https://atcoder.jp/contests/agc025/tasks/agc025_a)|[■](agc025/A/main.cpp)|

### ABC156

|Task|Solution|
|---|:---:|
|[B - Digits](https://atcoder.jp/contests/abc156/tasks/abc156_b)|[■](abc156/B/main.cpp)|

### ABC067

|Task|Solution|
|---|:---:|
|[B - Snake Toy](https://atcoder.jp/contests/abc067/tasks/abc067_b)|[■](abc067/B/main.cpp)|

### AGC027

|Task|Solution|
|---|:---:|
|[A - Candy Distribution Again](https://atcoder.jp/contests/agc027/tasks/agc027_a)|[■](agc027/A/main.cpp)|

### AGC012

|Task|Solution|
|---|:---:|
|[A - AtCoder Group Contest](https://atcoder.jp/contests/agc012/tasks/agc012_a)|[■](agc012/A/main.cpp)|

### ABC071

|Task|Solution|
|---|:---:|
|[B - Not Found](https://atcoder.jp/contests/abc072/tasks/abc072_a)|[■](abc072/B/main.cpp)|

### ABC061

|Task|Solution|
|---|:---:|
|[B - Counting Roads](https://atcoder.jp/contests/abc061/tasks/abc061_a)|[■](abc061/B/main.cpp)|

### ABC047

|Task|Solution|
|---|:---:|
|[B - すぬけ君の塗り絵 2 イージー](https://atcoder.jp/contests/abc047/tasks/abc047_a)|[■](abc047/B/main.cpp)|

### ABC091

|Task|Solution|
|---|:---:|
|[B - Two Colors Card Game](https://atcoder.jp/contests/abc091/tasks/abc091_a)|[■](abc091/B/main.cpp)|
|[C - 2D Plane 2N Points](https://atcoder.jp/contests/abc091/tasks/arc092_a)|[■](abc091/C/main.cpp)|

### ARC096

|Task|Solution|
|---|:---:|
|[C - Half and Half](https://atcoder.jp/contests/arc096/tasks/arc096_a)|[■](arc096/C/main.cpp)|

### ABC057

|Task|Solution|
|---|:---:|
|[C - Digits in Multiplication](https://atcoder.jp/contests/abc057/tasks/abc057_c)|[■](abc057/C/main.cpp)|

### ABC112

|Task|Solution|
|---|:---:|
|[C - Pyramid](https://atcoder.jp/contests/abc112/tasks/abc112_c)|[■](abc112/C/main.cpp)|

### ABC049

|Task|Solution|
|---|:---:|
|[C - 白昼夢](https://atcoder.jp/contests/abc049/tasks/abc049_c)|[■](abc049/C/main.cpp)|

### AGC013

|Task|Solution|
|---|:---:|
|[A - Sorted Arrays](https://atcoder.jp/contests/agc013/tasks/agc013_a)|[■](agc013/A/main.cpp)|

### AGC011

|Task|Solution|
|---|:---:|
|[A - Airport Bus](https://atcoder.jp/contests/agc011/tasks/agc011_a)|[■](agc011/A/main.cpp)|

### ABC059

|Task|Solution|
|---|:---:|
|[C - Sequence](https://atcoder.jp/contests/abc059/tasks/arc072_a)|[■](abc059/C/main.cpp)|

### ABCC093

|Task|Solution|
|---|:---:|
|[C - Same Integers](https://atcoder.jp/contests/abc093/tasks/arc094_a)|[■](abc093/C/main.cpp)|

### ACG010

|Task|Solution|
|---|:---:|
|[A - Addition](https://atcoder.jp/contests/agc010/tasks/agc010_a)|[■](agc010/A/main.cpp)|

### AGC020

|Task|Solution|
|---|:---:|
|[A - Move and Win](https://atcoder.jp/contests/agc020/tasks/agc020_a)|[■](agc020/A/main.cpp)|

### ABC073

|Task|Solution|
|---|:---:|
|[C - Write and Erase](https://atcoder.jp/contests/abc073/tasks/abc073_c)|[■](abc073/C/main.cpp)|

### ABC075

|Task|Solution|Memo|
|---|:---:|---|
|[B - Minesweeper](https://atcoder.jp/contests/abc075/tasks/abc075_b)|[■](abc075/B/main.cpp)||
|[C - Bridge](https://atcoder.jp/contests/abc075/tasks/abc075_c)|[■](abc075/C/main.cpp)|Union Find|

### ABC096

|Task|Solution|
|---|:---:|
|[C - Grid Repainting 2](https://atcoder.jp/contests/abc096/tasks/abc096_c)|[■](abc096/C/main.cpp)|


### ABC070

|Task|Solution|
|---|:---:|
|[B - Two Switches](https://atcoder.jp/contests/abc070/tasks/abc070_b)|[■](abc070/B/main.cpp)|

### ABC055

|Task|Solution|
|---|:---:|
|[B - Training Camp](https://atcoder.jp/contests/abc055/tasks/abc055_b)|[■](abc055/B/main.cpp)|

### ABC046

|Task|Solution|
|---|:---:|
|[B - AtCoDeerくんとボール色塗り](https://atcoder.jp/contests/abc046/tasks/abc046_b)|[■](abc046/B/main.cpp)|

### ABC048

|Task|Solution|
|---|:---:|
|[B - Between a and b ...](https://atcoder.jp/contests/abc048/tasks/abc048_b)|[■](abc048/B/main.cpp)|

### ABC060

|Task|Solution|
|---|:---:|
|[B - Choose Integers](https://atcoder.jp/contests/abc060/tasks/abc060_b)|[■](abc060/B/main.cpp)|

### ABC065

|Task|Solution|
|---|:---:|
|[B - Trained?](https://atcoder.jp/contests/abc065/tasks/abc065_b)|[■](abc065/B/main.cpp)|

### ABC098

|Task|Solution|
|---|:---:|
|[A - Add Sub Mul](https://atcoder.jp/contests/abc098/tasks/abc098_a)|[■](abc098/A/main.cpp)|
|[B - Cut and Count](https://atcoder.jp/contests/abc098/tasks/abc098_b)|[■](abc098/B/main.cpp)|
|[C - Attention](https://atcoder.jp/contests/abc098/tasks/arc098_a)|[■](abc098/C/main.cpp)|
|[D - Xor Sum 2](https://atcoder.jp/contests/abc098/tasks/arc098_b)|[■](abc098/D/main.cpp)|

### ABC079

|Task|Solution|Memo|
|---|:---:|---|
|[C - Train Ticket](https://atcoder.jp/contests/abc079/tasks/abc079_c)|[■](abc079/C/main.cpp)||
|[D - Wall](https://atcoder.jp/contests/abc079/tasks/abc079_d)|[■](abc079/D/main.cpp)|Floyd-Warshall|

### ABC122

|Task|Solution|
|---|:---:|
|[C - GeT AC](https://atcoder.jp/contests/abc122/tasks/abc122_c)|[■](abc122/C/main.cpp)|
|[D - We Like AGC](https://atcoder.jp/contests/abc122/tasks/abc122_d)|[■](abc122/D/main.cpp)|

### AGC023

|Task|Solution|
|---|:---:|
|[A - Zero-Sum Ranges](https://atcoder.jp/contests/agc023/tasks/agc023_a)|[■](agc023/A/main.cpp)|

### ABC084

|Task|Solution|
|---|:---:|
|[D - 2017-like Number](https://atcoder.jp/contests/abc084/tasks/abc084_d)|[■](abc084/D/main.cpp)|

### ARC061

|Task|Solution|
|---|:---:|
|[C - たくさんの数式](https://atcoder.jp/contests/arc061/tasks/arc061_a)|[■](arc061/C/main.cpp)|

### ABC104

|Task|Solution|
|---|:---:|
|[C - All Green](https://atcoder.jp/contests/abc104/tasks/abc104_c)|[■](abc104/D/main.cpp)|

### AGC033

|Task|Solution|
|---|:---:|
|[A - Darker and Darker](https://atcoder.jp/contests/agc033/tasks/agc033_a)|[■](agc033/A/main.cpp)|

### ABC051

|Task|Solution|
|---|:---:|
|[B - Sum of Three Integers](https://atcoder.jp/contests/abc051/tasks/abc051_b)|[■](abc051/B/main.cpp)|

### ABC054

|Task|Solution||
|---|:---:|---|
|[C - One-stroke Path](https://atcoder.jp/contests/abc054/tasks/abc054_c)|[■](abc054/C/main.cpp)||
|[D - Mixing Experiment](https://atcoder.jp/contests/abc054/tasks/abc054_d)|[■](abc054/D/main.cpp)|半分全列挙|


### keyence2020

|Task|Solution|
|---|:---:|
|[B - Robot Arms](https://atcoder.jp/contests/keyence2020/tasks/keyence2020_b)|[■](keyence2020/B/main.cpp)|

### ABC032

|Task|Solution|Memo|
|---|:---:|---|
|[C - 列](https://atcoder.jp/contests/abc032/tasks/abc032_c)|[■](abc032/C/main.cpp)||
|[D - ナップサック問題](https://atcoder.jp/contests/abc032/tasks/abc032_d)|[■](abc032/D/main.cpp)|半分全列挙|

### ABC038

|Task|Solution|
|---|:---:|
|[A - お茶](https://atcoder.jp/contests/abc038/tasks/abc038_c)|[■](abc038/A/main.cpp)|
|[B - ディスプレイ](https://atcoder.jp/contests/abc038/tasks/abc038_c)|[■](abc038/B/main.cpp)|
|[C - 単調増加](https://atcoder.jp/contests/abc038/tasks/abc038_c)|[■](abc038/C/main.cpp)|
|[D - プレゼント](https://atcoder.jp/contests/abc038/tasks/abc038_d)|[■](abc038/D/main.cpp)|

### ARC022

|Task|Solution|
|---|:---:|
|[B - 細長いお菓子](https://atcoder.jp/contests/arc022/tasks/arc022_2)|[■](arc022/B/main.cpp)|

### ABC017

|Task|Solution|
|---|:---:|
|[D - サプリメント](https://atcoder.jp/contests/abc017/tasks/abc017_4)|[■](abc017/D/main.cpp)|

### ARC029

|Task|Solution|
|---|:---:|
|[A - 高橋君とお肉](https://atcoder.jp/contests/arc029/tasks/arc029_1)|[■](arc029/A/main.cpp)|

### ABC002

|Task|Solution|
|---|:---:|
|[D - 派閥](https://atcoder.jp/contests/abc002/tasks/abc002_4)|[■](abc002/D/main.cpp)|

### ARC031

|Task|Solution|
|---|:---:|
|[B - 埋め立て](https://atcoder.jp/contests/arc031/tasks/arc031_2)|[■](arc031/B/main.cpp)|

### ARC037

|Task|Solution|
|---|:---:|
|[B - バウムテスト](https://atcoder.jp/contests/arc037/tasks/arc037_b)|[■](arc037/B/main.cpp)|

### ABC007

|Task|Solution|Memo|
|---|:---:|---|
|[A - 植木算](https://atcoder.jp/contests/abc007/tasks/abc007_1)|[■](abc007/A/main.cpp)|
|[B - 辞書式順序](https://atcoder.jp/contests/abc007/tasks/abc007_2)|[■](abc007/B/main.cpp)|
|[C - 幅優先探索](https://atcoder.jp/contests/abc007/tasks/abc007_3)|[■](abc007/C/main.cpp)|
|[D - 禁止された数字](https://atcoder.jp/contests/abc007/tasks/abc007_4)|[■](abc007/D/main.cpp)|桁DP|

### ARC005

|Task|Solution|
|---|:---:|
|[C - 器物損壊！高橋君](https://atcoder.jp/contests/arc005/tasks/arc005_3)|[■](arc005/C/main.cpp)|

### JOI2008yo

|Task|Solution|
|---|:---:|
|[A - おつり](https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_a)|[■](joi2008yo/A/main.cpp)|

### PRATICE2

|Task|Solution|
|---|:---:|
|[A - Disjoint Set Union](https://atcoder.jp/contests/practice2/tasks/practice2_a)|[■](practice2/A/main.cpp)|
|[B - Fenwick Tree](https://atcoder.jp/contests/practice2/tasks/practice2_b)|[■](practice2/B/main.cpp)|
|[C - Floor Sum](https://atcoder.jp/contests/practice2/tasks/practice2_c)|[■](practice2/C/main.cpp)|
|[D - Maxflow](https://atcoder.jp/contests/practice2/tasks/practice2_d)|[■](practice2/D/main.cpp)|

### ABC103

|Task|Solution|
|---|:---:|
|[D - Islands War](https://atcoder.jp/contests/abc103/tasks/abc103_d)|[■](abc103/D/main.cpp)|

### ABC076

|Task|Solution|
|---|:---:|
|[C - Dubious Document 2](https://atcoder.jp/contests/abc076/tasks/abc076_c)|[■](abc103/C/main.cpp)|

### ABC009

|Task|Solution|
|---|:---:|
|[C - 辞書式順序ふたたび](https://atcoder.jp/contests/abc009/tasks/abc009_3)|[■](abc009/C/main.cpp)|

### ARC006

|Task|Solution|
|---|:---:|
|[C - 積み重ね](https://atcoder.jp/contests/arc006/tasks/arc006_3)|[■](arc006/C/main.cpp)|

### ABC005

|Task|Solution|
|---|:---:|
|[C - おいしいたこ焼きの売り方](https://atcoder.jp/contests/abc005/tasks/abc005_3)|[■](abc005/C/main.cpp)|

### ABC117

|Task|Solution|Memo|
|---|:---:|---|
|[D - XXOR](https://atcoder.jp/contests/abc117/tasks/abc117_d)|[■](abc117/D/main.cpp)|桁DP|

### TDPC

|Task|Solution|Memo|
|---|:---:|---|
|[A - コンテスト](https://atcoder.jp/contests/tdpc/tasks/tdpc_contest)|[■](tdpc/A/main.cpp)||
|[D - サイコロ](https://atcoder.jp/contests/tdpc/tasks/tdpc_dice)|[■](tdpc/D/main.cpp)||
|[E - 数](https://atcoder.jp/contests/tdpc/tasks/tdpc_number)|[■](tdpc/E/main.cpp)|桁DP|

### ABC029

|Task|Solution|Memo|
|---|:---:|---|
|[D - 1](https://atcoder.jp/contests/abc029/tasks/abc029_d)|[■](abc029/D/main.cpp)|桁DP|

### ABC129

|Task|Solution|Memo|
|---|:---:|---|
|[E - Sum Equals Xor](https://atcoder.jp/contests/abc129/tasks/abc129_e)|[■](abc129/E/main.cpp)|桁DP|

### ABC015

|Task|Solution|Memo|
|---|:---:|---|
|[D - 高橋くんの苦悩](https://atcoder.jp/contests/abc015/tasks/abc015_4)|[■](abc015/D/main.cpp)||

### joi2013yo

|Task|Solution|Memo|
|---|:---:|---|
|[D - 暑い日々 (Hot days)](https://atcoder.jp/contests/joi2013yo/tasks/joi2013yo_d)|[■](joi2013yo/D/main.cpp)||

### code-festival-2014-quala

|Task|Solution|Memo|
|---|:---:|---|
|[D - 壊れた電卓](https://atcoder.jp/contests/code-festival-2014-quala/tasks/code_festival_qualA_d)|[■](code-festival-2014-quala/D/main.cpp)||

### ATC001

|Task|Solution|Memo|
|---|:---:|---|
|[C - 高速フーリエ変換](https://atcoder.jp/contests/atc001/tasks/fft_c)|[■](atc001/C/main.cpp)||

### indeednow-finala-open

|Task|Solution|Memo|
|---|:---:|---|
|[C - Optimal Recommendations](https://atcoder.jp/contests/indeednow-finala-open/tasks/indeednow_2015_finala_c)|[■](indeednow-finala-open/C/main.cpp)||

### ABC099

|Task|Solution|Memo|
|---|:---:|---|
|[C - Strange Bank](https://atcoder.jp/contests/abc099/tasks/abc099_c)|[■](abc099/C/main.cpp)||

### ABC153

|Task|Solution|Memo|
|---|:---:|---|
|[E - Crested Ibis vs Monster](https://atcoder.jp/contests/abc153/tasks/abc153_e)|[■](abc153/E/main.cpp)||

### yahoo-procon2017-final-open

|Task|Solution|Memo|
|---|:---:|---|
|[A - YahooYahooYahoo](https://atcoder.jp/contests/yahoo-procon2017-final-open/tasks/yahoo_procon2017_final_a)|[■](yahoo-procon2017-final-open/A/main.cpp)||

### ABC138

|Task|Solution|Memo|
|---|:---:|---|
|[E - Strings of Impurity](https://atcoder.jp/contests/abc138/tasks/abc138_e)|[■](abc138/E/main.cpp)||

### ARC017

|Task|Solution|Memo|
|---|:---:|---|
|[C - 無駄なものが嫌いな人](https://atcoder.jp/contests/arc017/tasks/arc017_3)|[■](arc017/C/main.cpp)|半分全列挙|

### AGC026

|Task|Solution|Memo|
|---|:---:|---|
|[C - String Coloring](https://atcoder.jp/contests/agc026/tasks/agc026_c)|[■](agc026/C/main.cpp)|半分全列挙|

### ABC018

|Task|Solution|Memo|
|---|:---:|---|
|[D - バレンタインデー](https://atcoder.jp/contests/abc018/tasks/abc018_4)|[■](abc018/D/main.cpp)|半分全列挙|

### ABC012

|Task|Solution|Memo|
|---|:---:|---|
|[D - バスと避けられない運命](https://atcoder.jp/contests/abc012/tasks/abc012_4)|[■](abc012/D/main.cpp)|Floyd-Warshall|

### ABC074

|Task|Solution|Memo|
|---|:---:|---|
|[D - Restoring Road Network](https://atcoder.jp/contests/abc074/tasks/arc083_b)|[■](abc074/D/main.cpp)|Floyd-Warshall|

### exawizards2019

|Task|Solution|Memo|
|---|:---:|---|
|[C - Snuke the Wizard](https://atcoder.jp/contests/exawizards2019/tasks/exawizards2019_c)|[■](exawizards2019/C/main.cpp)||

### ABC120

|Task|Solution|Memo|
|---|:---:|---|
|[D - Decayed Bridges](https://atcoder.jp/contests/abc120/tasks/abc120_d)|[■](abc120/D/main.cpp)|Union Find|

### joi2016yo

|Task|Solution|Memo|
|---|:---:|---|
|[E - ゾンビ島 (Zombie Island)](https://atcoder.jp/contests/joi2016yo/tasks/joi2016yo_e)|[■](joi2016yo/E/main.cpp)|Dijkstra|

### joi2014yo

|Task|Solution|Memo|
|---|:---:|---|
|[E - タクシー (Taxis)](https://atcoder.jp/contests/joi2014yo/tasks/joi2014yo_e)|[■](joi2014yo/E/main.cpp)|Dijkstra|

### ABC006

|Task|Solution|Memo|
|---|:---:|---|
|[D - トランプ挿入ソート](https://atcoder.jp/contests/abc006/tasks/abc006_4)|[■](abcc006/D/main.cpp)|LIS|
