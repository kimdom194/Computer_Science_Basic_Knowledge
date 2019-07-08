### 메모리

- 주소를 가지는 매체

- Logical address
  - 프로세스마다 독립적으로 가지는 주소 공간
  - 각 프로세스마다 0번지부터 시작
  - **cpu가 보는 주소**(컴파일을 다시해야되게때문에 피지컬 주소를 안봄)
- Physical address
  - 메모리에 실제로 올라가는 위치



- 주소 바인딩 : 주소를 결정하는 것

  - Symbolic address(숫자가아닌 주소) > logical > **(이 시점이 언제인가?)** physical

  - compile time binding(컴파일시에 이미 결정하는것(비효율적) symbolic > logical)

    - 물리적 메모리 주소가 컴파일 시 알려짐
    - 시작 위치 변경시 재컴파일
    - 컴파일러는 절대 코드 생성

  - Load time binding

    - 로더의 책임하에 물리적 메모리 주소 부여
    - 컴파일러가 재배치가능코드를 생성한 경우 가능

  - execution time binding(런타임바인딩)

    - 수행이 시작된 이후에도 프로세스의 메모리 상 위치를 옮길 수 있음(실행중에도 바뀔수가 있다.)

    - cpu가 주소를 참조할 때마다 바인딩을 점검

    - 하드웨어적인 지원이 필요

      - Memory Management Unit

        - 로지컬  어드레스를 피지철 어드레스로 매핑해주는 하드웨어 디바이스

      - MMU scheme

        - 사용자 프로세스가 cpu에서 수행되며 생성해내는 모든 주소값에 대해 base register의 값을 더한다

      - user program

        - 로지컬 어드레스만을 다룬다
        - 실제 피지컬 어드레스를 볼 수 없으며 알 필요가 없다.

        

- Dynamic Loading

  - 프로세스 전체를 메모리에 미리 다 올리는 것이 아니라 해당 루틴이 불려질 때 메모리에 로드 하는것
  - memory utilization의 향상
  - 가끔씩 사용되는 많은 양의 코드의 경우 유용(오류 처리 루틴)
  - 운영체제의 특별한 지원 없이 프로그램 자체에서 구현 가능(os 라이브러리를 통해 지원 가능)
  - Loading : 메모리로 올리는 것

- Overlays

  - 메모리에 프로세스의 부분 중 실제 필요한 정보만을 올림
  - 프로세스의 크기가 메모리보다 클 때 유용
  - 운영체제의 지원 없이 사용자에 의해 구현
  - 작은 공간의 메모리를 사용하던 초창기 시스템에서 수작업으로 프로그래머가 구현
    - Manual Overlay
    - 프로그래밍이 매우 복잡

- Swapping

  - 프로세스를 일시적으로 메모리에서 backing store로 쫒아내는 것

- Backing store (=swap area)

  - 디스크
    - 많은 사용자의 프로세스 이미지를 담을 만큼 충분히 빠르고 큰 저장 공간

- Swap in / Swap out

  - 일반적으로 중기 스케줄러에 의해 swap out 시킬 프로세스 선정
  - cpu 우선순위가 낮은 프로세스를 swaped out 시킴
  - Compile time 혹은 load time binding에서는 원래 메모리 위치로 swap in 해야함
  - execution time binding에서는 추후 빈 메모리 영역 아무곳에나 올릴 수 있음
  - swap time은 대부분 transfer time(swap되는 양에 비례하는 시간)임

- Dynamic Linking

  - Linking을 실행 시간까지 미루는 기법
  - static linking
    - 예를 들어 출력할 때 cout이라는 클래스 라이브러리를 사용하잖아요 그 cout이라는 클래스 라이브러리를 실행하는 코드가 있겠죠. hello.exe에다가 집어넣어서 만든 것이 Static Linking입니다.
    - 라이브러리가 프로그램의 실행 코드에 포함됨
    - 실행파일의 크기가 커짐
    - 동일한 라이브러리를 각각의 프로세스가 메모리에 올리므로 메모리 낭비
    - 미리 컴파일 되어 있기 때문에 **컴파일 시간도 단축**. 또 직접 구현한 코드를 라이브러리화시켜서 **기술 유출 방지**로 사용할 수도 있다.
    - 멀티유저시스템인 LINUX, UNIX 운영체제의 경우에는 사태가 좀 심각해진다. > 같은 동작을 하는 프로그램 코드가 n개 존재하게됨
  - Dynamic linking
    - 라이브러리가 실행시 연결됨
    - 라이브러리 호출 부분에 라이브러리 루틴의 위치를 찾기 위한 stub이라는 작은 코드를 둠
      - stub
        - 런타임시 해당 루틴이 불리면 그 스텁은 자신을 그 루틴이 들어있는 주소값과 바꿔치기 해버린다.
        - 한번 루틴이 불리게 되면 스텁이 있었다는 사실은 사라지고 주소가 된다.
        - 한개의 원본을 사용하여 메모리 절감 효과를 일으킨다. > **코드가 중복 적재되지 않는다.**
    - 라이브러리가 이미 메모리에 있으면 그 루틴의 주소로 가고 없으면 디스크에서 읽어옴
    - 운영체제의 도움이필요
    - 메모리 요구사항이 훨씬 적으나 약간의 오버헤드 발생가능
    - 프로그램 업데이트시 원래 코드와 라이브러리가 별도로 있는거니까 원래코드는 그대로 있고 **library**만 버전업이 되면 그거에 대한 성능을 내가 그대로받을 수 있다.



### 물리적인 메모리 관리법

- 메모리는 일반적으로 두 영역으로 나누어 사용

  - os 상주 영역

    - 인터럽트 벡터와 함께 낮은 주소영역 사용

  - 사용자 프로세스 영역

    - 높은 주소영역 사용

    

- 사용자 프로세스 영역 할당 방법

  - ##### Contiguous allocation(연속 할당)

    - 각각의 프로세스가 메모리의 연속적인 공간에 적재되도록 하는 것

      - Fixed partition allocation
      - Variable partition allocation

    - **Hole**

      - 가용 메모리 공간
      - 다양한 크기의 hole들이 메모리 여러 곳에 흩어져 있음
      - 프로세스가 도착하면 수용 가능한 hole을 할당
      - 운영체제는 다음의 정보를 유지
        - 할당 공간
        - 가용 공간(hole)

    - 고정 분할 방식

      - 융통성이 없음
      - 물리적 메모리를 몇개의 영구적 분할로 나눔
      - 외부 조각 문제
        - 분할의 크기가 작아서 프로그램 할당이 안된 공간
      - 내부 조각 문제
        - 분할의 크기가 커서 프로그램 할당 후 남은 공간

    - 가변 분할 방식

      - 외부 조각 문제

        - compaction
          - 사용중인 메모리 영역을 한군데로 몰고 hole들을 다른 한 곳으로 몰아 큰 block을 만드는 것
          - 매우 비용이 많이 드는 방법임
          - 최소한의 메모리 이동으로 compaction하는 방법(매우 복잡한 문제)
          - compaction은 프로세스의 주소가 실행 시간에 동적으로 재배치 가능한 경우에만 수행될 수 있다

      - 가변분할 방식에서 size n인 요청을 만족하는 가장 적절한 hole을 찾는 문제

        - first fit	
          - 최초로 찾아지는 hole에 할당
        - best fit
          - size가 가장근접한 hole에 할당
          - 모든 hole의 리스트를 탐색해야함
          - 많은 수의 아주 작은 hole들이 생성됨
        - worst fit
          - 가장 큰 hole에 할당
          - 모든 리스트를 탐색해야함
          - 상대적으로 아주 큰 hole들이 생성됨
        - first fit과 best fit이 worst fit보다 속도와 공간 이용률 측면에서 효과적인 것으로 알려짐

        

  - ##### Noncontiguous allocation

    - 하나의 프로세스가 메모리의 여러 영역에 분산되어 올라갈 수 있음

      - paging

        - OS가 과거에 레퍼런스 스트링을 알수가 없어서 LFU,LRU를 사용할 수 없다.

        - 프로세스의 virtual memory를 동일한 사이즈의 page 단위로 나눔

        - virtual memory의 내용이 page 단위로 저장됨

        - 일부는 backing storage에 일부는 physical memory에 저장

        - page table
        
          - 메인 메모리(RAM)에 상주
          - page table base register가 pagetable을 가리킴
          - page table length register가 테이블 크기를 보관
          - 모든 메모리 접근 연산에는 2번의 메모리 액세스 필요
  - 페이지 테이블 접근 1번, 실제 데이터/명령 접근 1번
          - 속도 향상을 위해 associative register 혹은 translation look-aside buffer(TLB : page table의 cahe라고 볼 수 있다. 페이지 테이블 접근 1번을 안하고 실제 데이터로 바로 접근하기에)라 불리는 고속의 lookup hardware cache 사용

        - ##### two-level page table

          - 32bit 컴퓨터라고 가정하고, 12bit는 offset을 표현하게 된다. 그렇다면 20bit가 남게 된다. 만약 온전히 20bit로만 테이블을 접근하게 된다면 각 페이지의 크기가 4KB이므로 **페이지 테이블의 크기가 굉장히 커지게 된다.** 이러한 큰 크기를 메모리에 할당하는 것은 부담이며, 극히 일부분만 필요로 하기에 공간낭비를 초래한다. 그렇기 때문에 10bit로 나누어 사용한다.

        - Multilevel Paging and Performance
        
          - address space가 더 커지면 다단계 페이지 테이블 필요
          - 각 단계의 페이지 테이블이 메모리에 존재하므로 local address의 physical address 변환에 더 많은 메모리 접근 필요
          - TLB를 통해 메모리 접근 시간을 줄일 수 있음
        
      - TLB는 전체를 탐색해야하기 때문에 병렬탐색을 해야한다.
    
  - Memory Protection
    
          - page table의 각 entry 마다 아래의 bit를 둔다
          - Protection bit
            - page에 대한 접근 권한
          - Valid invalid bit
            - valid는 해당 주소의 frame에 그 프로세스를 구성하는 유효한 내용이 있음을 뜻함(접근 허용)
      - invalid는 해당 주소의 frame에 유효한 내용이 없음을 뜻함(접근 불허)
      
  - Inverted Page Table
    
          - page table이 매우 큰 이유
            - 모든 프로세스 별로 그 logical address에 대응하는 모든 페이지에 대해 page table entry가 존재
            - 대응하는 page가 메모리에 있든 아니든 간에 page table에는 entry로 존재
          - Page frame 하나당 page table에 하나의 entry를 둔것
          - 각 page table entry는 각각의 물리적 메모리의 page frame이 담고 있는 내용 표시
          - 단점
      - 페이지 전체를 탐색해야함 > associative register 사용(비싸다)
      
  - Shared Page
    
          - Shared code
            - **Re-entrant code(=Pure code)**
            - Read only로 하여 프로세스 간에 하나의 code만 메모리에 올림
            - shared code는 모든 프로세스의 logical address space에서 동일한 위치에 있어야 함
          - Private code and data
            - 각 프로세스들은 독자적으로 메모리에 올림
      -   Private data는 logical address space의 아무 곳에 와도 무방
  
- segmentation
      
  - 프로그램은 의미 단위인 여러개의 세그먼트로 구성
    
  - 작개는 프로그램을 구성하는 함수 하나하나를 세그먼트로 정의
    
  - 크게는 프로그램 전체를 하나의 세그먼트로 정의 가능
    
  - 일반적으로는 code,data,stack부분이 하나씩의 세그먼트로 정의됨
    
  - ##### Protection
    
    - 각 세그먼트 별로 protection bit가 있음
    
  - ##### Sharing
    
          - shared segment
          - same segment number
    - 세그먼트는 의미 단위이기 때문에 공유와 보안에 있어서 paging보다 훨씬 효과적이다
    
  - ##### Allocation
    
          - first / best fit
          - extermal fragmentation 발생
    - 세그먼트의 길이가 동일하지 않으므로 가변분할 방식에서와 동일한 문제점들이 발생
  
- paged segmentation
      
        - pure segmentation과의 차이점
          - segment table entry가 segment의 base address를 가지고 있는것이 아니라 segment를 구성하는 page table의 base address를 가지고 있음