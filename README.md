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
