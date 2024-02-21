#include <stdio.h> // fget(), printf(), fopen(), fclose(), perror() 함수 사용   
#include <stdlib.h> // exit() 함수 사용  
#include <string.h> // strlen(), strtok() 함수 사용 

#include "2323402.h" // exam_word() 함수 사용 

int main(int argc, char *argv[]) { // main() 함수 

	if(argc == 1) { // command 창에서 ./2323402.c 만 입력했을 때
		printf("실행파일 뒤에 assembly 프로그램 파일을 입력하세요.\n");
		exit(0); // 프로그램 정상 종료
	}

	if(argc == 2) { // command 창에서 ./2323402.c test.asm 만 입력했을 때

		FILE *fp,*wp; // // 파일 포인터 
		char buf[80]; // 어셈블 파일(test.asm, example.asm) 한 줄씩 읽어들여 저장하는 배열 
		char *asm_file = argv[1]; // 어셈블 파일 (test.asm, example.asm) 

		if((fp = fopen(asm_file,"r")) == NULL) { // 어셈블 파일을 읽기 용으로 연다.
			perror("fopen: test.asm"); // test.asm 파일이 존재하지 않을 때 오류 메세지 출력
			exit(1); // 프로그램 강제 종료 
		}

		wp = fopen("output.txt","w");  // output.txt 파일을 쓰기 용으로 연다. 
					       // output.txt 파일이 존재하지 않으면 새로 만든다. 


		while(fgets(buf,80,fp) != NULL) { // 어셈블 파일(test.asm, example.asm)에서 한 줄씩 읽어들인다
			
			buf[strlen(buf)-1] = '\0'; // 개행 문자 제거 (어셈블 파일 내에서 한 줄의 마지막 문자에 개행문자가 삽입되어 있다.) 

			char *ptr = strtok(buf," "); // buf에서 token 뽑아낸다.

			exam_word(ptr,wp); // 단어를 차례대로 출력하고 output.txt 파일에 저장한다. 

		}

		fclose(fp); // 어셈블 파일을 닫는다. 

		fclose(wp); // output.txt 파일을 닫는다.
	}

	else { // ./2323402.c test.asm example.asm (3개 이상 인자를 작성할 때)
		printf("./ 실행 프로그램  assembly 프로그램 만 입력하세요.\n");
		exit(0); // 프로그램 정상 종료
	}


	return 0; // 프로그램 정상 종료
}

