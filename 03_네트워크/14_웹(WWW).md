- ### 웹 서비스

  - 전세계적으로 TCP, UDP, SCTP 포트 80으로 지정
    - 보안을 위해 8000, 8080 등을 이용하기도 함
    - 보안이 강화된 HTTPS(HTTP over TLS/SSL)의 경우 TCP, UDP, SCTP 포트 443 이용
  - 웹 브라우저는 http 또는 https 서비스에 지정된 포트를 통해 서버와 연결 시도
    - 다양한 웹 브라우저 존재
  - 웹 서버와 연결이 되면 클라이언트의 정보 요구에 대해 서버가 웹 문서 회신
  - 사용자 요구마다 연결 설정과 해제 반복



- ### 클라이언트-서버 모델

  - URL(Uniform Resource Locator)
    - 서버의 자원 명칭
    - 사용하는 프로토콜, 서버의 호스트 이름, 서버
      내부의 파일 경로명으로 구성
    - 예: http://www.korea.co.kr/welcom.html
    - UNIX/Linux 시스템
      - 로그인 이름 hong
      - 개인 홈 디렉토리/public_html/index.html
      - http://www.korea.co.kr/~hong
  - HTTP (HyperText Transfer Protocol)
  - 연결 설정과 해제
    1. 사용자가 웹 브라우저에게 웹 서버의 URL 주소 입력
    2. 웹 브라우저가 DNS 서버에게 웹 서버의 호스트 이름을 IP 주소로 변경 요청
    3. 웹 브라우저가 의 웹 서버와 TCP 접속 시도
    4. 웹 브라우저가 웹 서버에게 최초 화면을 위한 GET 명령 전송
    5. 웹 서버가 웹 브라우저에게 요청한 웹 문서를 회신
    6. 웹 브라우저와 웹 서버 사이의 연결 해제
    7. 웹 브라우저가 사용자 화면에 웹 문서를 출력



- ### APM(Apache, PHP, MySQL)

  - Apache
    - 웹 서버 프로그램
    - 대응되는 프로그램 : Microsoft의 IIS(Internet Information Services) 등
  - PHP
    - 유닉스/리눅스 환경에서 지원되며, HTML 언어의 기능을 보강
    - 대응되는 언어 : Microsoft의 ASP(Active Server Page), Java 언어 기반 JSP(Java Server Pages) 등
  - MySQL
    - 데이터베이스 기능 지원
    - 대응되는 DB: Oracle DB, MariaDB
  - APM의 동작 원리
    1. 웹 브라우저가 Apache에 웹 문서 요청
    2. PHP 코드 처리 필요 시 PHP에 요청
    3. 데이터베이스 처리 필요 시 MySQL에 요청
    4. 데이터베이스 결과 회신
    5. PHP가 실행 결과인 HTML 코드 회신
    6. 웹 문서를 웹 브라우저에 회신
  - PHP 코드의 처리
    - PHP 코드는 HTML 문서에 Embedded 형식으로 작성 : 이 구분자
      - PHP 코드가 포함된 문서의 확장자는 .php
    - 웹 브라우저에 회신되는 내용: PHP 코드는 서버에서 실행되고 결과만 회신



- ### HTML

  - HTML(HyperText Markup Language)

    - 웹 브라우저에서 데이터를 어떻게 표시하는지 나타냄
    - HTML로 작성한 문서는 서버에 보관
    - 클라이언트는 그 문서를 받아 화면에 표시

  - HTML 문서 구조

    - <HTML>로 시작하고, </HTML>로 종료
    - 헤더 : <HEAD>로 시작하고, </HEAD>로 종료
    - 바디 : <BODY>로 시작하고, </BODY>로 종료

  - 시맨틱 마크업

    - 시맨틱 검색
      - 검색 로봇이 검색어 의미를 스스로 분석하고 추리해 사람이
        원하는 정보를 정교하게 찾아주는 검색 방법
      - 일반 검색 방식
        - 사용자가 입력한 단어 위주로 찾으면서 가장 검색빈도수가 높은 순으로 제시
        - 사용자의 검색어 입력 후 다시 입력하는 검색어를 기록하여 연관 검색어를 만들어냄
      - 검색 로봇이 정보를 잘 추출할 수 있도록 구조적인 홈페이지 작성이 중요
    - 시맨틱 마크업과 디자인 분리
      - 내용의 의미 표현에 집중
      - HTML 대신 CSS를 사용하여 ‘구조’와 ‘표현’을 구분
        - 대표적인 혼동 : <FONT>

  - ##### 기본적인 HTML5 마크업 사용

    - 앨리먼트와 태그
      - 앨리먼트(element)
        - HTML 문서의 개별적인 구성 요소
        - 예 : p(paragraph), img(image)
      - 태그(tag) 
        - 부등호(< >)로 둘러싸인 앨리먼트를 조합해서 부르는 이름
        - 예 : <P>, <IMG>
    - 블록 레벨 앨리먼트와 인라인 레벨 앨리먼트 
      - 블록 레벨 앨리먼트
        - 항상 새로운 줄바꿈을 하여 표시됨 
        - 너비값은 브라우저 화면에 100%로 꽉 차게 표시됨 
        - 예 : <p>문단1</p>
    - 인라인 레벨 앨리먼트
      - 같은 줄 안에서 이어서 표시됨
      - 너비값은 요소가 가지고 있는 값 자체로 표시됨
      - 예 : <em>강조 1 </em>
      - 인라인 레벨 앨리먼트는 반드시 블록레벨 앨리먼트 안에 있어야 함
    - 시맨틱 마크업 방법
      - heading : <h1>, <h2>...<h6>
      - 가장 중요한 정보는 <h1>
        - 문서의 구조와 내용의 중요도를 표시(폰트가 크다는 의미가 아님)
        - 가장 중요한 제목에 사용, 페이지 안에 반드시 나타나야 함
        - 순서대로 사용 – 중간 단계를 건너뛰면 안됨
        - 건너뛰면 로봇은 더 이상 중요한 내용이 없다고 판단
      - 시맨틱 마크업은 앨리먼트가 가지고 있는 본래 목적에 맞게 사용하는 것
    - 주요 태그 사용 제안
      - p, em, strong, address는 각각의 목적에 맞게 의미 전달 시 꼭 사용
      - 태그를 그룹으로 묶을 때 블록 레벨에서는 div, 인라인 레벨에서는 span을 사용
      - 그룹핑할 때 header, nav, article, footer, section의 엘리먼트를 목적에 맞게 사용
        - header – 문서의 머리말 지정
        - nav – 메뉴 영역 지정
        - article – 콘텐츠 영역 지정
        - section – 문서 내용 구분
        - footer – 꼬리말 영역 지정

  

- ### HTTP

  - 웹브라우저는 URL을 이용 원하는 자원 표현

  - HTTP 메소드(method)를 이용하여 데이터를 요청(GET)하거나, 회신(POST)

  - 요청과 응답

    - 요청
      -  HTTP 클라이언트가 서버에 요청을 전송
      - 요청 메소드, URL, HTTP 버전과 기타 부가 정보 포함
    - 응답
      -  HTTP 서버가 요청의 결과인 응답 코드가 포함된 정보를 회신

  - 비상태(stateless) 연결

    - 요청과 응답 이후, 연결이 끊어지므로 비상태 프로토콜

  - ##### MIME 유사 메세지

    - MIME
      - Multipurpose Internet Message Extensions
      - 기존 ASCII 문자로 구성된 텍스트만이 전송 가능했던 전자우편을 멀티미디어 데이터 전송도 가능하도록 확장한 것
      - MIME Header
        - MIME-Version
        - Content-Type
        - Content-Transfer-Encoding
        - Content-Id
        - Content-Description
      - Content-Transfer-Encoding
        - 메시지를 0과 1로 인코딩하는 방법 정의
        - Content-Transfer-encoding : <TYPE>
          - Base64
            - 최상위 비트가 0일 필요가 없을 때 byte data전송 해결책
            - 연속된 비트(bin)데이터를 24비트 블록으로 분할
            - 각 블록은 네 개의 단락(각 6비트)으로 분리
            - 각 6비트 단락은 하나의 문자로 해석하여 ASCII 변환
            - 24비트가 네 개의 문자가 되어 최종적으로 32비트가 전송 25%의 오버헤드
      - 차이점
      - HTTP에서 사용하는 MIME 유사메시지는 content-Length 필드 존재
      - Content-Transfer-Encoding 대신 ContentEncoding, Transfer-Encoding 필드 사용

  - ##### 요청 메시지

    - 요청 메시지(Request Message) 구성
      - 요청문(Request Line)
      - 헤더
      - 공백
      - 바디
    - 요청문의 구성
      - 요청 메소드
        - GET
          - URL이 가리키는 웹 문서 전송 요청
        - HEAD
          - 문서 내용보다 특정 문서에 대한 정보만을 요청
        - POST
          - 클라이언트가 서버에 정보(사용자 입력) 전송
        - PUT
          - 클라이언트가 서버에 문서(몸체에 포함) 전송
      - URL
      - HTTP 버전
    - 응답 메시지 구성
      - 요청메시지와 유사하나, 요청문 대신 상태문(Status line) 사용
    - 상태문의 구성
      - HTTP 버전
      - 상태 코드
      - 상태 이름

- ### HTTP의 동작 과정

  - 요청 메시지
    - 개요
      - HTTP 서버: uu.ac.kr
      - 요청 메소드: GET
      - 요청 문서의 URL: index.php
      - HTTP 버전: 1.1
  - 응답 메시지
    - 개요
      - 상태문: HTTP/1.1 200 OK
      - 헤더 정보: 5 줄
      - 바디 정보: 로 시작하는 웹 문서 내용
  - 시뮬레이션
    - HTTP 서버: uu.ac.kr
    - HTTP 클라이언트
      - kihyun.uu.ac.kr
      - telnet 프로그램이 대행



- ### CGI

  - Common Gateway Interface
  - CGI 필요성
    - HTML로만 웹문서를 작성하는 경우 서버의 정보만을 일방적으로 받아들이는 단방향 정보 흐름
    - 사용자가 입력하는 정보에 따른 처리 기능 제공 필요
  - C, C++과 같은 고급언어로도 작성 가능하나, 독립된 개발과 컴파일, 개별 프로세스로 처리하는 부담 때문에 스크립트(Script) 언어 선호
    - PHP, Ruby, …
  - Java를 이용한 웹 응용 개발도 하나의 흐름
    - MVC 개념, Spring
  - FORM 태그
    - 사용자의 입력을 서버에 전달
    - FORM 태그의 속성
      - ACTION: 사용자 입력을 처리한 CGI 프로그램의 URL 주소
      - METHOD: 사용자 데이터를 넘기는 방식
      - ENCTYPE: 데이터 형식
    - INPUT 태그의 속성
      - TEXT: 텍스트 입력
      - PASSWORD: 암호 입력
      - CHECKBOX: 체크 박스
      - RADIO: 라디오 버튼
      - SUBMIT: 입력 허가
      - RESET: 입력 취소
    - 웹브라우저 측
      - JavaScript 이용하여 처리
    - 웹 서버
      - CGI 로 처리

  