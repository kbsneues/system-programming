 <div align="center">
<h2> 🧑🏻‍💻어셈블러 구현🧑🏻‍💻 </h2>
Ubuntu 환경에서 어셈블러를 구현하였습니다
</div>

<h2>0. Overview</h2>
이 프로그램은 앞으로 구현하게 될 어셈블러의 구현에 사용될 기본요소 모듈을 구현하
는 것입니다.

<h2>1. 문제 정의</h2>
파일로부터 assembly 소스 프로그램을 입력받아 프로그래밍 언어의 기본적인 단위인
Token 을 생성하여 화면과 출력화일(output.txt)에 출력한다.

2. 요구 사항

2.1 Separator 
Token 과 token 사이를 구분해주는 것을 separator 라고 하는데 여기서 제작하려는
프로그램에선 다음과 같은 것이 있다. 
(1) blank 문자 - 빈칸(' ')과 탭('\t') 
(2) '(작은따옴표) - 16 진수 상수와 문자열 상수를 둘러싸는 데 필요하다. 
ex) X'F1'의 'F1'과 C'EOF'의 'EOF' 
(3) ,(콤마) - 오퍼랜드를 구분한다. 
ex) LDCH BUFFER, X 에서 BUFFER 와 X 를 구분

2.2 입력 파일구조
(1) 입력으로 받을 assembly 프로그램의 statement 는 newline('\n')으로 구분되며 한
statement 의 최대 길이는 80 문자로 정한다. 
(2) Statement 내에서 label, operator, operand 는 2.1 의 (1)에서 보인 것과 같이
blank 문자로 구분되며 각 label 과 OP Code 는 컬럼(column)의 위치가 고정되어
있고, 두 필드가 하나 이상의 공백 문자(blank)에 의해서 구분된다. (1-6 칼럼까지 레이블, 8 칼럼부터 OP Code) 
(3) 주석문(comment)의 시작 문자는 끝점('.')으로 정하며 statement 의 어느
column 에도 올 수 있다. (주석문은 TOKEN 이 아니므로 출력하지 않고 넘어간다.) 
(4) UNIX 에서 fgets 함수를 사용하여 한 line 씩 읽어들이면 됨. EOF 가 되면 fgets 의 값으로 null 값이 return 됨

2.3 출력 형태
(1) 생성된 token 을 화면과 출력파일(output.txt)에 한줄에 하나씩 출력한다. 
(2) 문자열 상수는 그대로 출력하고 16 진수 상수는 10 진수로 바꾸어 출력한다. 즉 C'EOF'에서 'EOF'는 EOF 로 X'11'에서 '11'는 17 로 출력한다. 


2.4 실행 예제
.This is an example program.
COPY START 1000 
FIRST LDCH BUFFER,X 
BUFFER RESB 4096 
EOF BYTE C'EOF' 
INPUT BYTE X'11' 

위의 프로그램을 파일로 입력으로 받아 처리하면 다음과 같이 출력이 나와야 한다. 

출력) 
. 
COPY 
START 
1000 
FIRST 
LDCH 
BUFFER 
X 
BUFFER 
RESB 
4096 
EOF 
BYTE 
C 
EOF 
INPUT 
BYTE 
X 
17 

NOTE) 주석문에서 .은 token 이므로 출력을 해야 하지만 주석문의 내용은 token 이
아니므로 출력하지 않는다. X'11'에서 11 은 16 진수이므로 해당되는 10 진수 숫자인 17 로
출력한다. 단 START 에서 1000 은 16 진수이나 여기에선 편의상 10 진수로 생각한다. 

3. 실행 및 테스트
(1) 실행 프로그램 이름은 학번(7 자리).out (예,2021001.exe 또는 2021001.out 등)으로
하며 입력으로 받을 assembly 프로그램 이름은 command line 으로 받는다. 출력파일 명은 output.txt 로 한다
(2) 우선 위 2.4 의 예제를 test.asm 으로 만든다. 
LEX(또는 2021001.exe) test.asm 로 실행을 해서 출력이 위와 같이 나오는가를 확인한다. 
(3) 교재 Figure 2.1(p.45)의 예제 프로그램을 example.asm 으로 저장한 후 실행해 볼 것(단 statement 의 주석을 모두 제거할 것)
