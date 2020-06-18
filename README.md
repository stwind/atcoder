# AtCoder

Playing [AtCoder](https://atcoder.jp/).

## Requirements

* gcc 9
* pipenv

## Setup

```sh
pipenv install
pipenv shell
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