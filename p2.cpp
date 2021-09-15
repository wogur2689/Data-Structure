#include <stdio.h>

void main(){
	/* 2주차
		자료의 형태에 따른 분류
		-단순 구조
			-정수, 실수, 문자, 문자열 등의 기본 자료형
		-선형 구조
			-자료들 사이의 관계가 1:1 관계
			-순차 리스트, 연결 리스트, 스택, 큐, 데크 등
		-비선형 구조
			-자료들 사이의 관계가 1:다, 또는 다:다 관계
			-트리, 그래프 등
		-파일 구조
			-서로 관련 있는 필드로 구성된 레코드의 집합인 파일에 대한 구조
			-순차 파일, 색인 파일, 직접 파일 등

		컴퓨터에서의 자료 표현
		-숫자, 문자, 그림 ,소리, 기호 등 모든 형식의 자료를 2진수 코드로 표현하여 저장 및 처리
		-2진수 코드란?
			-1과 0, On과 Off, 참과 거짓의 조합
		-2진수 코드의 단위 [비트]

		-10진수의 표현
			-존 형식의 표현
				-10진수 한 자리를 표현하기 위해서 1바이트(8비트)를 사용하는 형식
			-존 영역
				-상위 4비트
				-1111로 표현
			-수치 영역
				-하위 4비트
				-표현하고자 하는 10진수 한 자리 값에 대한 2진수 값을 표시
			-존 형식의 구조
				-xxxx8421
			-10진수의 표현
				-여러 자리의 10진수를 표현하는 방법
					-10진수의 자릿수만큼 존 형식을 연결하여 사용
					-마지막 자리의 존 영역에 부호를 표시
					양수(+): 1100 음수(-): 1101 
				-팩 형식의 표현
					-10진수 한 자리를 표현하기 위해서 존 영역 없이 4비트를 사용하는 형식
					-최하위 4비트에 부로를 표시 

			-2진수의 정수 표현
				-n비트의 부호 절댓값 형식
					-최상위 1비트 : 부호 표시
					양수(+) : 0 음수(-) : 1
					-나머지 n-1 비트 : 이진수 표시
				-1의 보수 형식
					-음수 표현에서 부호 비트를 사용하는 대신 1의 보수를 사용하는 방법
					-n비트의 2진수를 1의 보수로 만드는 방법 
						-n비트를 모두 1로 만든 이진수에서 변환하고자 하는 이진수를 뺌
				-2의 보수 형식
					-음수의 표현에서 부호 비트를 사용하는 대신 2의 보수를 사용하는 방법
					-n비트의 2진수를 2의 보수로 만드는 방법
						-n비트에 1을 더함
				-2진수 정수의 세가지 표현 방법에서 양수의 표현은 같고 음수의 표현만 다름.
				
			-2진수의 실수 표현
				-고정 소수점 표현
					-소수점이 항상 최상위 비트의 왼쪽 밖에 고정되어 있는 것으로 취급
				-부동 소수점 형식의 표현
					-고정 소수점 형식에 비해서 표현 가능한 값의 범위가 넓음
					-실수를 구분하여 표현
			
		-문자 자료의 표현
			-문자에 대한 이진수 코드를 정의하여 사용 (BCD, EBCDIC, ASCII)
			-BCD
				-6비트를 사용하여 문자표현
				-상위 2비트 : 존 비트
				-하위 4비트 : 2진수 비트
				-존 비트와 2진수 비트를 조합하여 10진수 0~9와 영어 대문자, 특수 문자를 표현
			-EBCDID
				-8비트를 사용하여 문자 표현
				-상위 4비트 : 존 비트
				-하위 4비트 : 2진수 비트
				-존비트와 2진수 비트를 조합하여 10진수 0~9와 영어 대문자/소문자, 특수문자를 표현
			-ASCII
				-7비트를 사용하여 문자 표현
				-상위 3비트 : 존비트
				-하위 4비트 : 2진수 비트
				-존비트와 2진수 비트를 조합하여 10진수 0~9와 영어 대문자/소문자, 특수문자를 표현
			-유니코드(65536개)
				-국제 표준코드
				-2바이트를 조합하여 하나의 글자를 표현
				-현재는 표현의 한계를 극복한 유니코드가 일반화
				-XML, JAVA, COBOL

		-논리자료
			-논리값을 표현하기 위한 자료 형식
			-논리값: 참과 거짓, 1과 0
		-포인터 자료
			-메모리의 주소를 표현하기 위한 자료 형식
			-변수의 주소나 메모리의 특정 위치에 대한 주소를 저장하고 주소연산하기 위해 사용
		-문자열 자료
			-여러 문자로 이루어진 문자의 그룹을 하나의 자료로 취급하여 메모리에 연속적으로 저장하는 자료 형식
			-하나의 문자열 자료에 포한된 부분 문자열을 표현하는 방법
				-방법 1 : 부분 문자열 사이에 구분자를 사용하여 저장
				-방법 2 : 가장 긴 문자열의 길이에 맞춰 고정 길이로 저장한다.
				-방법 3 : 부분 문자열을 연속하여 저장하고 각 부분 문자열에 대한 포인터를 사용한다.

		-자료의 추상화
			-뇌의 추상화 기능 : 기억할 대상의 구별되는 특징만을 단순화 하여 기억하는 기능
			-크고 복잡한 문제를 단순화시켜 쉽게 해결하기 위한 방법
			-처리할 자료, 연산, 자료형에 대한 추상화 표현
			-자료 : 프로그램의 처리 대상이 되는 모든 것을 의미
			-연산 : 어떤 일을 처리하는 과정. 연산자에 의해 수행
			-자료형 : 처리할 자료의 집합과 자료에 대해 수행할 연산자의 집합

		-추상 자료형 : 자료와 연산자의 특성을 논리적으로 추상화 하여 정의한 자료형
		-추상화 - "무엇인가?"를 논리적으로 정의
		-구체화 - "어떻게 할 것인가?"를 실제적으로 표현

		추상화와 구체와의 관계
		추상화 : 추상자료형 / 알고리즘 정의
		구체화 : 자료형 / 프로그램 구현

		알고리즘
		-문제 해결 방법을 추상화하여 단계적 절차를 논리적으로 기술해 놓은 명세서

		알고리즘의 조건
		-입력 : 알고리즘 수행에 필요한 자료가 외부에서 입력으로 제공될 수 있어야 한다.
		-출력 : 알고리즘 수행 후 하나 이상의 결과를 출력해야 한다.
		-명확성 : 수행할 작업의 내용과 순서를 나타내는 알고리즘의 명령어들은 명확하게 명세되어야 한다.
		-유한성 : 알고리즘은 수행 뒤에 반드시 종료되어야 한다.
		-효과성 : 알고리즘의 모든 명령어들은 기본적이며 실행이 가능해야 한다.

		알고리즘의 표현 방법의 종류
		-자연어를 이용한 서술적 표현 방법
		-순서도를 이용한 도식화 표현 방법
		-프로그래밍 언어를 이용한 구체화 방법
		-가상코드를 이용한 추상화 방법

		순서도를 이용한 도식화
		타원: 시작, 종료
		사각형 : 처리문, 치환문
		평행사변형 : 입력, 출력
		마름모 : 조건문, 판단문
		화살표 : 제어 흐름

		가상코드를 이용한 추상화
		-기본 요소 : 기호, 자료형, 연산자
		지정문 형식 : 변수 <- 값

		알고리즘 성능 분석 기준
		- 정확성 : 올바른 자료 입력 시 유한한 시간 내에 올바른 결과 출력 여부
		- 명확성 : 알고리즘이 얼마나 이해하기 쉽고 명확하게 나타내는가
		- 수행량 : 일반적인 연산 제외, 알고리즘 특성 나타내는 중요 연산 모두 분석
		- 메모리 사용량
		- 최적성 : 가장 중요

		알고리즘 성능 분석 방법
		-공간 복잡도 : 알고리즘을 프로그램으로 실행하여 완료하기까지 필요한 총 저장 공간의 양
		고정공간 + 가변공간
		-시간 복잡도 : 알고리즘을 프로그램으로 실행하여 완료하기까지의 총 소요시간
		컴파일 시간 + 실행시간

		알고리즘 성능 분석 표기법
		- 빅-오 표기법
		 -O(f(n))과 같이 표기, Big Oh of f (n)"으로 읽음
		 -수학적 정의 : 함수 f(n)과 g(n)이 주어졌을 때, 모든 n>=n0에 대하여 lf(n)l =< c lg(n)l을 만족하는 상수 c와 n0이 존재하면,
		 f(n) = O(g(n))이다.
		 -함수의 상한을 나타내기 위한 표기법 : 최악의 경우에도 g(n)의 수행시간 안에는 알고리즘 수행 완료 보장
		 -먼저 실행 빈도수 구하기 -> 실행 시간 함수 찾기 -> 가장 큰 영향을 주는 n에 대한 항을 한 개 선택하여 계수는 생략하고 O의 오른쪽 괄호 안에 표시

		- 빅-오메가 표기법
		 -Ω(f(n))과 같이 표기, Big Omega of f (n)"으로 읽음
		 -수학적 정의 : 함수 f(n)과 g(n)이 주어졌을 때, 모든 n>=n0에 대하여 lf(n)l >= c lg(n)l을 만족하는 상수 c와 n0이 존재하면,
		 f(n) = Ω(g(n))이다.
		 -함수의 하한을 나타내기 위한 표기법

		- 빅-세타 표기법
		 -θ(f(n))과 같이 표기, Big Theta of f (n)"으로 읽음
		 -수학적 정의 : 함수 f(n)과 g(n)이 주어졌을 때, 모든 n>=n0에 대하여 clg(n) >= f(n) >= clg(n)l을 만족하는 상수 c1와 c2와 n0이 존재하면,
		 f(n) = θ(g(n))이다.
		 -상한과 하한이 같은 정확한 차수를 표현하기 위한 표기법

		최선, 평균, 최악의 경우
		-최선의 경우 : 수행 시간이 가장 빠른 경우 - 의미 없는 경우가 많음
		-평균의 경우 : 수행시간이 평균적인 경우 - 계산하기가 상당히 어려움
		-최악의 경우 : 수행 시간이 가장 늦은 경우 - 가장 널리 사용되고 계산하기 쉽고 응용에 따라 중요한 의미를 가짐.
	*/
}