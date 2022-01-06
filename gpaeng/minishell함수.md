## 공통

<br/>

https://42kchoi.tistory.com/259?category=953120

<br/>

 `-lreadline` 컴파일러 플래그를 사용하여 컴파일해야 한다

< -lreadline을 사용하기 위해 설치 >

https://stackoverflow.com/questions/23085076/readline-readline-h-file-not-found

<br/>

## readline()

<br/>

https://www.man7.org/linux/man-pages/man3/readline.3.html

https://junselee.tistory.com/3

- char *  readline (const char *prompt);
- readline은 입력받은 문자열을 저장하고 그 메모리주소를 반환한다.
- 프롬프트가 NULL이거나 빈 문자열이면 프롬프트가 발행되지 않습니다.
- 반환된 줄은 malloc(3)으로 할당됩니다. 호출자는 완료되면 해제해야 합니다. 
- 반환된 줄에는 마지막 줄 바꿈이 제거되어 줄의 텍스트만 남습니다.

```c
       #include <stdio.h>
       #include <readline/readline.h>
       #include <readline/history.h>
```

<br/>


## add_history()

<br/>

https://junselee.tistory.com/3

- void **add_history** *(char \*string)*

-  add_history에 저장된 문자열은 up & down 방향키를 이용해 확인 할 수 있다.

- 히스토리 목록의 끝에 문자열을 배치합니다. 연결된 데이터 필드(있는 경우)는 NULL로 설정됩니다.

  (Place string at the end of the history list. The associated data field (if any) is set to NULL.)






---------------------





## rl_on_new_line()

<br/>

https://tiswww.case.edu/php/chet/readline/readline.html

- int **rl_on_new_line** *(void)*

- 일반적으로 줄 바꿈을 출력한 후 새(빈) 줄로 이동했음을 업데이트 루틴에 알립니다.

  (Tell the update functions that we have moved onto a new (empty) line, usually after outputting a newline.)

<br/>



## rl_replace_line()

<br/>

https://tiswww.case.edu/php/chet/readline/readline.html

- void **rl_replace_line** *(const char \*text, int clear_undo)*

- rl_line_buffer의 내용을 텍스트로 바꿉니다. 가능한 경우 포인트와 마크가 유지됩니다. clear_undo가 0이 아니면 현재 행과 관련된 실행 취소 목록이 지워집니다.

  (Replace the contents of `rl_line_buffer` with text. The point and mark are preserved, if possible. If clear_undo is non-zero, the undo list associated with the current line is cleared.)

<br/>



## rl_redisplay()

<br/>

- void **rl_redisplay** *(void)*

- rl_line_buffer의 현재 내용을 반영하도록 화면에 표시되는 내용을 변경합니다.

  (Change what's displayed on the screen to reflect the current contents of rl_line_buffer.)

### +

#### rl_line_buffer()

- char * **rl_line_buffer**

- 지금까지 모은 라인입니다. 줄의 내용을 수정할 수 있지만 2.4.5 실행 취소 허용을 참조하십시오. rl_extend_line_buffer 함수는 rl_line_buffer에 할당된 메모리를 늘리는 데 사용할 수 있습니다.

  (This is the line gathered so far. You are welcome to modify the contents of the line, but see 2.4.5 Allowing Undoing. The function rl_extend_line_buffer is available to increase the memory allocated to rl_line_buffer.)

<br/>

### < 예제 >

- Ctrl+c 눌렀을 때 (signum == SIGINT), rl_* 함수 실행

```
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

void    handler(int signum)
{
    if (signum == SIGINT)
    {
        printf("\n");
        rl_on_new_line();
        rl_replace_line("ddd", 0);
        rl_redisplay();
    }
}

int main(void)
{
    char    *line;

    while (1){
        signal(SIGINT, handler);
    	line = readline("prompt>: ");
    	if (line)
    		printf("%s\n", line);    
    	else
    		break ;
    	add_history(line);
    	free(line);
    }
    return (0);
}
```

<br/>
