### File System

- File
  - 일반적으로 비휘발성의 보조기억장치에 저장
  - 운영체제는 다양한 저장장치를 file이라는 동일한 논리적 단위로 볼 수 있게 해 줌
  - Operation
    - create, read, write, reposition, delete, open, close 등
- File attribute(혹은 파일의 메타데이터)
  - 파일 자체의 내용이 아니라 파일을 관리하기 위한 각종 정보들
    - 파일 이름, 유형, 저장된 위치, 파일 사이즈
    - 접근권한(읽기/쓰기/실행), 시간(생성/변경/사용), 소유자 등
- File system
  - 운영체제에서 파일을 관리하는 부분
  - 파일 및 파일의 메타데이터, 디렉토리 정보 등을 관리
  - 파일의 저장 방법 결정
  - 파일 보호 등
- Directory
  - 파일의 메타데이터 중 일부를 보관하고 있는 일종의 특별한 파일
  - 그 디렉토리에 속한 파일 이름 및 파일 애트리뷰트 등
  - operation
    - search for a file, create a file, delete a file
    - list a directory, rename a file, traverse the file system
    - Partition(=Logical Disk)
  - 하나의 디스크 안에 여러 파티션을 두는게 일반적
  - 여러 개의 물리적인 디스크를 하나의 파티션으로 구성하기도 함
  - 디스크를 파티션으로 구성한 뒤 각각의 파티션에 **파일시스템**을 깔거나 **스와핑** 등 다른 용도로 사용할 수 있음

- open()
  
  - 디스크로부터 파일의 메타데이터를 메모리로 가지고 옴
- File Protection
  - 각 파일에 대해 누구에게 어떤 유형의 접근(read/write/execution)을 허락할 것인가?
  - access control 방법
    - access control matrix
      - access control list : 파일별로 누구에게 어떤 접근 권한이 있는지 표시
      - capabilly : 사용자별로 자신이 접근 권한을 가진 파일 및 해당 권한 표시
    - grouping
      - 전체 유저를 owner, group, public의 세 그룹으로 구분
      - 각 파일에 대해 세 그룹의 권한을 3비트씩으로 표시
      - ex) UNIX
    - password
      - 파일마다 비밀번호를 두는 방법(디렉토리 파일에 두는 방법도 가능)
      - 모든 접근 권한에 대해 하나의 패스워드 : all or nothing
      - 접근 권한별 패스워드 : 암기문제, 관리문제

- 시스템이 제공하는 파일 정보의 접근 방식
  - 순차접근
    - 카세트 테이프를 사용하는 방식처럼 접근
    - 읽거나 쓰면 offset은 자동적으로  증가
  - 직접 접근
    - LP레코드판과 같이 접근하도록함
    - 파일을 구성하는 레코드를 임의의 순서로 접근할 수 있음

- Contiguous Allocation

  - 블럭단위로 나눔
    - 인접한 블럭을 할당
  - 단점
    - external fragmentation
    - file grow가 어려움
      - file 생성시 얼마나 큰 hole을 배당할 것인가?
      - grow 가능 vs 낭비(internal fragmentation)
  - 장점
    - 빠른 입출력
      - 한번의 seek/rotation으로 많은 바이트 tranfer
      - realtime file용으로, 또는 이미 run중이던 프로세스의 스와핑 용
    - direct access(=random access)가능

- Linked Allocation

  - 장점
    - external fragmentation 발생 안 함
  - 단점
    - no random access
    - reliability 문제
      - 한 sector가 고장나 pointer가 유실되면 많은 부분을 잃음
    - pointer를 위한 공간이 block의 일부가 되어 공간 효율성을 떨어트림
  - 변형
    - File allocation table(FAT)파일 시스템
      - 포인터를 별도의 위치에 보관하여 reliability와 공간 효율성 문제 해결

- Indexed Allocation

  - 장점

    - external fragmentation 발생하지 않음
    - Random access 가능

  - 단점

    - 작은 파일의 경우 공간 낭비(실제로 많은 파일들이 작다)

    - Too large file의 경우 하나의 블록으로 인덱스를 저장하기에 부족

      - multilevel index
      - linked scheme

      

- UNIX 파일 시스템 구조

  - 유닉스 파일 시스템의 중요 개념
    - Boot block
      - 부팅에 필요한 정보
    - Super block
      - 파일 시스템에 관한 총체적인 정보를 담고 있다.
    - Inode(Index node)
      - 파일 이름을 제외한 파일의 모든 메타 데이터를 저장
    - Data block
      - 파일의 실제 내용을 보관



- Free space Management
  - Bit map or bit vector
    - 비트맵은 부가적인 공간을 필요로 함
    - 연속적인 n개의 free block을 찾는데 효과적
  - Linked list
    - 모든 free block들을 링크로 연결
    - 연속적인 가용공간을 찾는 것은 쉽지 않다
    - 공간의 낭비가 없다
  - Grouping
    - Linked list의 변형
    - 첫번째 free block이 n개의 포인터를 가짐
      - n-1 포인터는 프리 데이터 블록을 가리킴
      - 마지막 포인터가 가리키는 블록은 또 다시 n 포인터를 가짐
  - counting
    - 프로그램들이 종종 여러 개의 연속적인 블록을 할당하고 반납한다는 성질에 착안
    - first free block, # of contiguous free blocks을 유지



- Directory Implementation
  - Linear list
    - <file name, file의 메타데이터>의 리스트
    - 구현이 간단
    - 디렉토리 내에 파일이 있는지 찾기 위해서는 라이너서치 필요
  - Hash table
    - linear list + hashing
    - Hash table은 file name을 이 파일의 linear list의 위치로 바꾸어줌
    - search time을 없앰
    - Collision 발생 가능
  - 파일의 메타데이터의 보관 위치
    - 디렉토리 내에 직접 보관
    - 디렉토리에는 포인터를 두고 다른곳에 보관
      - inode, FAT 등
  - 긴 파일 이름의 지원
    - <File name, file의 메타데이터>의 list에서 각 엔트리는 일반적으로 고정 크기
    - 파일 이름이 고정 크기인 엔트리 길이보다 길어지는 경우 엔터리의 마지막 부분에 이름의 뒷부분이 위치한 곳의 포인터를 두는 방법
    - 이룸의 나머지 부분은 동일한 디렉토리 파일의 일부에 존재



- VFS and NFS
  - Virtual File System
    - 서로 다른 다양한 파일시스템에 대해 동일한 시스템 콜 인터페이스(API)를 통해 접근할 수 있게 해주는 OS의 Layer
  - Network File System
    - 분산 시스템에서는 네트워크를 통해 파일이 공유될 수 있음
    - NFS는 분산 환경에서의 대표적인 파일 공유법임



- Page cache and buffer cache
  - Page cache
    - Virtual memory의 paging system에서 사용하는 페이지 프레임을 caching의 관점에서 설명하는 용어
    - memory mapped i/o를 쓰는 경우 file의 i/o에서도 페이지 캐쉬 사용
  - Memory mapped i/o
    - file의 일부를 virtual memory에 매핑 시킴
    - OS의 개입여부가 일반적인 Read/write와 다름
    - 매핑시킨 영역에 대한 메모리 접근 연산은 파일의 입출력을 수행하게 함
  - Buffer cache
    - 파일 시스템을 통한 i/o 연산은 메모리의 특정 영역인 buffer cache 사용
    - file 사용의 locality활용
      - 한번 읽어온 block에 대한 후속 요청시 buffer cache에서 즉시 전달
    - 모든 프로세스가 공용으로 사용
    - Replacement algoritm 필요(LRU, LFU 등 사용할 수 있다.)
  - unified buffer cache
    - 최근 OS에서는 기존의 버퍼 캐쉬가 페이지 캐쉬에 통합됨