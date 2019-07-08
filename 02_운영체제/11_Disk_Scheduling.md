### Disk Structure

- Logical block

  - 디스크의 외부에서 보는 디스크의 단위 정보 저장 공간들
  - 주소를 가진 1차원 배열처럼 취급
  - 정보를 전송하는 최소 단위

- 섹터

  - 로지컬 블록이 물리적인 디스크에 매핑된 위치
  - 섹터 0은 최외곽 실린더의 첫 트랙에 있는 첫번째 섹터이다.

  

- ##### Disk scheduling
  - Access time의 구성
    - seek time
      - 헤드를 해당 실린더로 움직이는데 걸리는 시간
    - Rotational latency
      - 헤드가 원하는 섹터에 도달하기까지 걸리는 회전 지연 시간
    - Transfer time
      - 실제 데이터의 전송시간
  - Disk bandwidth
    - 단위 시간 당 전송된 바이트의 수
  - disk scheduling
    - seek time을 최소화하는것이목표
    - seek time = seek distance

- Disk Management

  - physical formatting(Low level formatting)
    - 디스크를 컨트롤러가읽고 쓸 수 있도록 섹터들로 나누는과정
    - 각 섹터는 header + 실제 data(보통 512bytes) + trailer로 구성
    - 헤더와 트레일러는 sector number, ECC(Error Correcting Code)등의 정보가 저장되며 controller가 직접 접근 및 운영
  - Partitioning
    - 디스크를 하나 이상의 실린더 그룹으로 나누는 과정
    - OS는 이것을 독립적 disk로 취급(logical disk)
  - Logical formatting
    - 파일 시스템을 만드는 것
    - FAT, inodem free space등의 구조 포함
  - Booting
    - ROM에 있는 small bootstrap loader의 실행
    - sector 0(boot block)을 load 하여 실행
    - sector 0은 "full Bootstrap loader program"
    - OS를 디스크에서 LOAD 하여실행



- Disk scheduling algorithm

  - FCFS(First come first service)
  - SSTF(Shortest Seek Time First)
  - SCAN
    - 디스크의 ARM이 한쪽 끝에서 다른쪽 끝으로 이동하며 가는 길목에 있는 요청을 처리한다.
    - 다른 한쪽 끝에 도달하면 역방향으로 이동
    - 문제점 : 실린더 위치에 따라 대기 시간이 다르다.

  - C SCAN
    - 헤드가 한쪽끝에서 다른쪽 끝으로 이동하며 가는 길목에 있는 모든 요청을 처리
    - 다른쪽 끝에 도달했으면 요청을 처리하지않고 곧바로 출발점으로 다시 이동
  - N SCAN
    - 스캔과 동일하지만 지나가면서 들어오는 요청은 처리하지않음 다음번에 처리

  - LOOK
    - SCAN에서 더이상 가는방향으로 요청이 없으면 방향을 바꿈
  - C LOOK
    - C SCAN에서 더이상 가는방향으로 요청이 없으면 방향을 바꿈



- Swap Space Management
  - Disk를 사용하는 두가지 이유
    - Memory의 volatile한 특성 > file system
    - 프로그램 실행을 위한 memory 공간 부족 > swap space(swap area)
  - Swap space
    - Virtual Memory system에서는 디스크를 메모리의 연장 공간으로 사용
    - 파일시스템 내부에 둘 수도 있으나 partition 사용이 일반적
      - 공간효율성보다는 속도 효율성이 우선
      - 일반 파일보다 훨씬 잛은 시간만 존재하고 자주 참조됨
      - 따라서 블록의 크기 및 저장 방식이 일반 파일시스템과 다름
- RAID
  - 여러개의 디스크를 묶어서 사용
- RAID의 사용목적
  - 디스크 처리 속도 향상
    - 여러 디스크에 블록의 내용을 분산 저장
  - 신뢰성 향상
    - 동일 정보를 여러 디스크에 중복저장

