### 교착상태(deadlock)

- 일련의 프로세스들이 서로가 가진 자원을 기다리며 block된 상태

- resource(자원)
  - 하드웨어, 소프트웨어 등을 포함하는 개념
    - ex) I/O device, CPU cycle, memory space, semaphore 등
  - 프로세스가 자원을 사용하는 절차
    - request, allocate, use, release



- deadlock 발생의 조건(모두 만족해야 한다)
  - Mutual exclution(상호 배제)
    - 매 순간 하나의 프로세스만이 자원을 사용할 수 있음
  - NO preemption(비선점)
    - 프로세스는 자원을 스스로 내어놓을뿐 강제로 빼앗기지 않음
  - Hold and wait(보유대기)
    - 자원을 가진 프로세스가 다른 자원을 기다릴 때 보유 자원을 놓지 않고 계속 가지고 있음
  - Circular wait(순환대기)
    - 자원을 기다리는 프로세스간에 사이클이 형성되어야 함
    - p1 > p2 > p3 > p1



- deadlock 처리 방법
  - Prevention
    - 자원 할당 시 Deadlock의 4가지 조건 중 어느 하나가 만족되지 않도록 하는 것
  - Avoidance
    - 자원 요청에 대한 부가적인 정보를 이용해서 데드락의 가능성이 없는 경우에만 자원을 할당
    - 시스템 state가 원래 state로 돌아올 수 있는 경우에만 자원 할당
      - single instance : Resource allocation graph algorithm 사용
        - 프로세스가 자원을 미래에 요청할 수 있음을 뜻함(점선으로 표시)
        - 프로세스가 해당 자원 요청시 request edge로 바뀜(실선)
        - 자원이 release 되면 assignment edge는 다시 claim edge로 바뀐다
        - request edge의 assignment edge 변경시 (점선을 포함하여) cycle이 생기지 않는 경우에만 요청 자원을 할당한다.
        - cycle 생성 여부 조사시 프로세스 수가 n일때 O(n**2)시간이 걸린다.
      - multiple instances : Banker's algorithm 사용
        - 자원 최대 사용량을 알고있다.
        - 최대 사용량 - 현재 사용량을 빼면 가용 자원량이 나온다.
        - 자원 요청이 들어오면 가용자원으로 충족이 가능할때 할당
    - **위에 2개는 예방하는 방법**
  - Detection and recovery
    - 발생은 허용하되 그에 대한 디텍션 루틴을 두어 발견시 복구
    - Detection
      - 싱글 인스턴스의 경우 cycle이 곧 deadlock을 의미
      - 멀티 인스턴스의 경우 뱅커 알고리즘과 유사한 방법 활용
    - Recovery
      - 데드락에 연루된 프로세스 모두 사살
      - 데드락이 없어질때까지 연루된 프로세스 하나씩 사살
  - ignorance
    - 유닉스를 포함한 대부분의 os가 채택
    - 데드락이 일어나지 않는다고 생각하고 아무런 조치도 취하지 않음
    - 데드락이 매우 드물게 나타나므로 조치 자체가 더 큰 오버헤드일 수 있음
    - 만약 시스템에 데드락이 발생한 경우 시스템이 비정상적으로 작동하는 것을 사람이 느낀 후 직접 프로세스를 죽이는 등의 방법으로 대처
    - 시스템이 책임지지 않음