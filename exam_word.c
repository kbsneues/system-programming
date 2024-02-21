#include <stdio.h> // printf(), fputs(), sscanf(), fprintf() 함수 사용   
#include <string.h> // strtok(), strstr() 함수 사용 

void exam_word(char *ptr, FILE *wp) { // exam_word 함수는 문자열 포인터 , 파일 포인터를 Parameter로 받는다.

	while(ptr != NULL) { // 한줄의 문자 끝까지 읽는다. 

		if(ptr[0] == '.') { // 주석문 검사 (첫번째 글자가 . 일 때) 
			printf(".\n"); fputs(".\n",wp); // 출력, output 파일에 작성
			break; // 다음줄 검색 
		}

		if(strstr(ptr,",") != NULL) { // 콤마 검사 
			char *ftr = strtok(ptr,","); // BUFFER,X 일 때  ftr은 BUFFER 문자열을 가리키는 주소이다. 
			while(ftr != NULL) { // 문자열 끝까지 탐색
				printf("%s\n",ftr); // 출력 
				fputs(ftr,wp); fputs("\n",wp); // output.txt 파일에 작성 
				ftr = strtok(NULL," "); // ftr은 X 문자를 가리킨다. X 문자를 출력하고 ftr은 NULL을 반환한다.
			}
			break; // 다음줄 검색 
		}

		if(strstr(ptr,"'") != NULL) { // 작은 따옴표 검사
			char *ktr = strtok(ptr,"'"); // X'F1'  C'EOF'

			printf("%s\n",ktr); // X, C 출력 
			fputs(ktr,wp); fputs("\n",wp); // output.txt 파일에 작성 

			if(ktr[0] == 'X') { // 16진수 상수 (X'F1')
				int num; 
				ktr = strtok(NULL,"'"); // ktr은 F1 문자열을 가리키는 주소이다.
				sscanf(ktr,"%x",&num); // F1 문자열을 16진수 상수로 변환하여 num 값에 저장한다.
				printf("%d\n",num); // 10진수 정수값 출력  F1(16진수) -> 241(10진수)  
				fprintf(wp,"%d",num); fputs("\n",wp); // 10진수 정수값을 output.txt 파일에 작성
				break; // 문자열 끝까지 읽었으므로 while문 종료  
			}

			if(ktr[0] == 'C') { // 문자열 상수 (C'EOF')
				ktr = strtok(NULL,"'"); // ktr은 EOF 문자열을 가리키는 주소이다.
				printf("%s\n",ktr); // 출력 
				fputs(ktr,wp); fputs("\n",wp); // output.txt 파일에 작성 
				break; // 문자열 끝까지 읽었으므로 while문 종료
			}

		}

		printf("%s\n",ptr); // 주석문(첫번째 문자 .) , 콤마, 작은 따옴표가 없는 문자열 (COPY, START, 1000, BYTE) 출력
				    // 예를 들어 COPY START 1000 한줄을 읽어들였을 때 COPY 문자열을 출력  
		fputs(ptr,wp); fputs("\n",wp); // output.txt 파일에 작성 
		ptr = strtok(NULL," "); // ptr은 START 문자열을 가리키는 주소이다.

	}
}
