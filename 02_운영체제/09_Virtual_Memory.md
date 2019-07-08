### Demand Paging

- 실제로 필요할 때 page를 메모리에 올리는 것

  - 입출력 양의 감소
  - 메모리 사용량 감소
  - 빠른 응답시간
  - 더많은 사용자 수용

- Valid/Invalid bit의 사용

  - Invalid의 의미
    - 사용되지 않는 주소 영역인 경우
    - 페이지가 물리적 메모리에 없는 경우
  - 처음에는 모든 페이지 엔티티가 invalid로 초기화
  - address translation시에 invalid bit가 set 되어있으면 > **"page fault"**
  - Page fault
    - 요청한 페이지가 메모리에 없는 경우 운영체제가 올린다.

- Free frame이 없는 경우

  - Page replacement

    - 어떤 frame을 빼앗아올지 결정해야 함
    - 곧바로 사용되지 않을 page를 쫒아내는 것이 좋음
    - 동일한 페이지가 여러번 메모리에서 쫒겨났다가 다시 들어올 수 있음

  - Optimal algorithm

    - MIN(OPT) : 가장 먼 미래에 참조되는 페이지를 리플레이스

  - FIFO algorithm : 먼저 들어온 것을 먼저 내쫒음

  - LRU algorithm **O(1) 시간복잡도** : 가장 오래 전에 참조된 것을 지움

  - LFU algorithm **O(log n) 시간복잡도** : 참조 횟수가 가장 적은 페이지를 지움

    - 최저 참조 횟수인 페이지가 여럿 있는 경우 > 임의  선정

    - 장단점

      - 참조 시점의 최근성을 반영하지 못함
      - LRU처럼 직전 참조 시점만 보는 것이 아니라 장기적인 시간 규모를 보기 때문에 page의 인기도를 좀 더 정확히 반영할 수 있음
      - LRU보다 구현이 복잡함

      

### 다양한 캐슁 환경

- 캐슁 기법
  - 한정된 빠른 공간(=캐쉬)에 요청된 데이터를 저장해 두었다가 후속 요청시 캐쉬로부터 직접 서비스하는 방식
  - paging system 외에도 cache memory, buffer caching, web caching등 다양한분야에서 사용
- 캐쉬 운영의 시간 제약
  - 교체 알고리즘에서 삭제할 항목을 결정하는 일에 지나치게 많은시간이 걸리는 경우 실제 시스템에서사용할 수 없음
  - buffer caching이나 web caching의 경우
    - O(1)에서 O(log n)정도까지 허용
  - paging system인 경우
    - page fault인 경우에만 os가 관여함
    - 페이지가 이미 메모리에 존재하는 경우 참조시각 등의 정보를 os가 알 수 없음
    - O(1)인 LRU의 리스트 조작조차 불가능
    - Clock algorithm
      - LRU의 근사 알고리즘
      - 여러 명칭으로 불림
        - NUR, NRU, Second chance algorithm
      - Reference bit을 사용해서 교체 대상 페이지 선정
      - Reference bit가 0인 것을 찾을 때까지 포인터를 하나씩 앞으로 이동
      - 포인터 이동하는 중에 reference bit 1은 모두 0으로 바꿈
      - 0인 것을 찾으면 그 페이지를 교체
      - 한바퀴 되돌아와서도 0이면 그때는 replace 당함
      - 자주 사용되는 페이지라면 second chance가 올때 1
- Page Frame의 allocation
  - 각 프로세스에 얼마만큼의 페이지 프레임을 할당할 것인가?
  - allocation의 필요성
    - 메모리 참조 명령어 수행시 명령어, 데이터 등 여러 페이지 동시 참조
      - 명령어 수행을 위해 최소한 할당되어야 하는 frame의 수가 있음
    - loop를 구성하는 page들은 한꺼번에 allocate 되는 것이 유리함
      - 최소한의 allocation이 없으면 매 loop마다 page fault
  - allocation Scheme
    - 모든 프로세스에 똑같은 갯수 할당
    - 프로세스 크기에 비례하여 할당
    - 프로세스의 priority에 따라 다르게 할당
  - Global vs Local Replacement
    - Global
      - Replace시 다른 프로세스에 할당된 프레임을 빼앗아 올 수 있다.
      - 프로세스별 할당량을 조절하는 또 다른 방법임
      - FIFO, LRU, LFU등의 알고리즘을 global replacement로 사용시에 해당
      - working set, PFF알고리즘 사용
        - working set model
          - locality에 기반하여 프로세스가 일정 시간 동안 원활하게 수행되기 위해 한꺼번에 메모리에 올라와 있어야 하는 page들의 집합을 working set이라 정의함
          - 프로세스의 working set 전체가 메모리에 올라와있어야 수행되고 그렇지 않을 경우 모든 frame을 반납한 후 swap out
          - Thrashing을 방지함
          - Multiprogramming degree를 결정함
            - working set의 결정
              - working set window를 통해 알아냄
              - window size가 d인 경우
                - 워킹셋에 속한 페이지는 메모리에 유지, 속하지  않은것은 버림(즉 참조된 후 d시간 동안 해당 페이지를 메모리에 유지한 후 버림)
        - PFF(Page fault frequency)Scheme
          - page fault rate의 상한값과 하한값을 둔다
            - page fault rate이 상한값을 넘으면 frame을 더 할당한다
            - page fault rate이 하한값 이하이면 할당 frame 수를 줄인다
          - 빈 프레임이 없으면 일부 프로세스를 swap out
    - Local
      - 자신에게 할당된 frame 내에서만 replacement
      - FIFO, LRU, LFU 등의 알고리즘을 프로세스별로 운영시

- Thrashing
  - 프로세스의 원활한 수행에 필요한 최소한의 page frame 수를 할당 받지 못한 경우 발생
  - page fault rate이 매우 높아짐
  - CPU utilization이 낮아짐
  - OS는 MPD(Multiprogramming degree)를 높여야 한다고 판단
  - 또다른 프로세스가 시스템에 추가됨
  - 프로세스당 할당된 프레임의 수가 더욱 감소
  - 프로세스는 page의 swap in / swap out으로 매우 바쁨
  - 대부분의 시간에 cpu는 한가함
  - low throughput



- page size의 결정
  - 사이즈를 감소시키면
    - 페이지 수 증가
    - 페이지 테이블 크기 증가
    - internal fragmentation 감소
    - disc transfer의 효율성 감소
      - seek/rotation vs transfer
    - 필요한 정보만 메모리에 올라와 메모리 이용이 효율적
      - locality의 활용 측면에서는 좋지 않음
  - trend
    - larger page size