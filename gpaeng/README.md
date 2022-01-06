# echo

```shell
> echo [-neE] [arg ...]
```

### Output the args, separated by spaces, terminated with a newline

>The return status is 0 

> -n : the trailing newline is suppressed



#### < Case >

- [ ] `args` 출력
- [ ] 빈칸 여러개 -> 빈칸 하나로 출력
- [ ] option `-n` 일 시 `\n` 개행 제거

- [ ] `option flags`가 `0`이면 `\n` 개행 출력

- [ ] `single quote(' ')` 일 때 환경 변수를 치환하지 않고 그래도 출력

  ```shell
  > echo '$PATH'
  > $PATH
  
  > echo "$PATH"
  > PATH 경로 출력
  ```

  

- [ ] `$?` 경우 `g_exit_status` 값 출력

- [ ] option `-n == -nnnnn` 동일 하게 출력

- [ ] `; ;`  or ` | |`  이면 `syntax error` 처리





# cd

```shell
> cd [-L] [-P [-e]] [-@] [directory]
```

### Change the current working directory to directory

> If directory is not supplied the value of the HOME shell variable is used

> Any additional arguments following directory are ignored



#### < Case >

- [ ] `cd` or `cd 경로 ` 일 경우 HOME 경로를 찾아서 이동

- [ ] `cd $PATH` 일 경우 `PATH` 경로 찾아서 이동 

- [ ] `cd 경로` 이후에 인자가 들어올 경우 Error message 없이 경로로 이동

- [ ] `cd [env에 없는 환경변수]`일 경우 HOME 경로를 찾아서 이동

- [ ] `cd 222 333` 와 같이 인자 2개이상 일 때 Error 출력

  ```shell
  bash: cd: [첫번째 인자]: No such file or directory
  ```

- [ ] 올바르지 않은 폴더 경로를 인자로 받을 때 Error 출력

  ```shell
  bash: cd: [인자]: No such file or directory
  ```

- [ ] `unset HOME` 한 후 `cd $HOME` 했을 때 Error 출력

  ```shell
  bash: cd: HOME not set
  ```

- [ ] `cd -` 이전 경로로 이동





# pwd

```shell
> pwd [-LP]
```

### Print the absolute pathname of the current working directory



#### < Case >

- [ ] 현재 `directory 경로` 출력





# export

```shell
> export [-fn] [-p] [name[=value]]
```

### Mark each name to be passed to child processes in the environment



#### < Case >

- [ ] `export` , `export $환경변수`면 `print_export`
- [ ] `export` 뒤에 인자가 1개이면 환경변수에 저장 X
- [ ] `export key=value`이면 환경변수에 저장 (key에 숫자 있으면 안된다.)
- [ ] `|` 뒤에 `export` 가 있으면 환경변수 생성 X



# unset

```shell
> unset [-fnv] [name]
```

### Remove each variable or function name



#### < Case >

- [ ] `unset 환경변수` 해당 환경 변수가 있으면 삭제 O
- [ ] `unset 환경변수` 해당 환경 변수가 없으면 삭제 X
- [ ] `|` 뒤에 `unset` 있으면 환경 변수 삭제 X



# env

```shell
> env [환경변수]
```

### Print a list of environment variables 

### run another utility in an altered envirenment without having to modify the currently existing environment



#### < Case >

- [ ] `env`  입력시 환경 변수 전체 출력

- [ ] `env $PATH` 입력 시 PATH값에 상관 없이 환경 변수 전체 출력 

- [ ] `env path` 입력 시 Error 출력

  ```shell
  env: path: No such file or directory
  ```

   



# exit

```shell
> exit [n]
```

### Exit the shell, returning a status of n to the shell's parent



#### < Case >

- [ ] `exit` 입력 시 `exit` 출력 후 `shell` 끄기

- [ ] `exit` 뒤의 숫자 인자 + 인자가 2개(인자 개수) 이상이면 `Error` 발생 후 `shell` 종료 X

  ```shell
  > exit 111 222 333
  exit
  bash: exit: too many arguments
  
  //but
  > exit 111
  exit 된다.
  ```

- [ ] `exit` 뒤의 인자가 숫자가 아닌 경우 `Error` 발생 후 `shell` 종료 O

  ```shell
  > exit gpaeng
  exit
  bash: exit: gpaeng: numeric argument required
  ```

- [ ] `|` 뒤에 `exit` 있으면 쉘 종료 X (자식 Process의 exit이기 때문)



# Reference

https://www.gnu.org/software/bash/manual/bash.pdf

https://wiki.kldp.org/HOWTO/html/Adv-Bash-Scr-HOWTO/internal.html

[https://velog.io/@hidaehyunlee/minishell-2.-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8-%EA%B5%AC%EC%A1%B0-%EB%B0%8F-%EA%B0%9C%EB%B0%9C-%EA%B8%B0%EB%A1%9D%EB%93%A4](https://velog.io/@hidaehyunlee/minishell-2.-프로그램-구조-및-개발-기록들)

