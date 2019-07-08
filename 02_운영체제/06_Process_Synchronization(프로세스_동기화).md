### 데이터의 접근

- Data > 연산할 data > 연산 > 연산 결과



OS에서 race condition은 언제 발생하는가?

1. 커널 수행 중 인터럽트 발생 시
2. 프로세스가 시스템 콜을 하여 커널모드로 수행중인데 문맥교환이 일어나는 경우
3. 멀티프로세서에서 공유 메모리내의 커널 데이터



##### 임계구역

- n개의 프로세스가 공유 데이터를 동시에 사용하기를 원하는 경우
- 각 프로세스의 code segment에는 공유 데이터를 접근하는 코드인 critical section이 존재
- 문제점
  - 하나의 프로세스가 임계구역에 있을 때 다른 프로세스는 들어올 수 없어야 한다.
- 프로세스들은 수행의 동기화를 위해 공유 변수를 사용할 수 있다.



##### 프로그램적 해결법의 충족 조건

- 상호 배제
  
- 프로세스가 임계구역 부분을 수행 중이면 다른 모든 프로레스들은 들어올 수 없다.
  
- Progress
  
  - 아무도 임계구역에 있지 않은 성태에서 들어가고자 하는 프로세스가 있다면 허가해주어야 한다.
- Bounded Waiting
  
- 프로세스가 임계구역에 들어가려고 요청한 후부터 그 요청이 허용될 때까지 다른 프로세스들이 임계구역에 들어가는 횟수에 한계가 있어야 한다.
  
- ##### 하드웨어적으로 test and set 명령어를 지원한다면 앞의 3가지 문제를 간단히 해결할 수 있다.

  - boolean * TestAndSet (boolean * target) 

    {

      boolean * rv = * target;

      *target = TRUE;

      return rv;

    }

    인자로 받은 값을 그대로 반환한다. 다만, 인자의 값자체를 TRUE로 변경한다.

    while(true) 

    {

      while(TestAndSet(&lock))

      // do nothing

      // critical section

      lock = FALSE;

      // remainder section

    }

    제일 처음에는 lock은 FALSE값으로 초기화되어 있다. 

    따라서, 처음으로 실행한 프로세스는 첫 while문을 통과한다. 

    그리고, TestAndSet에 의해서 lock은 TRUE가 되었으므로, 다른 프로세스가 임계 영역을 실행하려고 해도, while문에서 걸려서 실행할 수 없다. 상호 배제 조건을 만족하는 셈이다. 

    그리고 임계 영역을 다 끝낸 프로세스는 lock값을 다시 FALSE로 되돌려서 다른 프로세스도 임계영역을 실행할 수 있도록 한다. 

    따라서, 진행 조건도 만족하는 셈이다.

    다만, 한정 대기 조건(기아 상태 방지)을 만족한다고 볼 수는 없다.

    

### 세마포어 S

앞의 방식들을 추상화 시킴 두 가지 atomic 연산에 의해서만 접근 가능

- P(S) : 변수값(S : 자원의 갯수, 여부)을 획득하는 과정(자원의 갯수가 음수면 진행)
  - block() : 커널은 블럭을 호출한 프로세스를 suspend 시킴
    - 이 프로세스의  PCB를 세마포어에 대한 wait queue에 넣음

- V(S) : 사용하고 반납하는 과정(자원의 갯수가 양수면 진행)
  - wakeup(P) : 블럭된 프로세스 P를 wakeup 시킴
    - 이 프로세스의 PCB를 ready queue로 옮김

##### Deadlock

- 둘 이상의 프로세스가 서로 상대방에 의해 충족될 수 있는 event를 무한히 기다리는 현상

##### Starvation(기아현상)

- indefinite blocking : 프로세스가 suspend 된 이후에 해당하는 세마포어 큐에서 빠져나갈 수 없는 현상



##### Busy-wait VS Block/wakeup

- 임계영역의 길이가 긴 경우 Block/wakeup이 적당
- 임계 영역의 길이가 매우 짧은 경우 Block/wakeup 오버헤드가 busy-wait 오버헤드보다 커질 수 있음
- 일반적으로는 Block/wakeup 방식이 더 좋음



### 여러가지 고전적인 문제점들

- Bounded Buffer Problem(Producer Consumer Problem)
- Readers Writers Problem
<<<<<<< Updated upstream

- Dining Philosophers Problem

=======
- Dining Philosophers Problem
  - 모니터 코드에 대한 이해가 우선 필요
    - 세마포어의 문제점
      - 코딩하기 힘들다
      - 정확성의 입증이 어렵다.
      - 자발적 협력이 필요하다
      - 한번의 실수가 모든 시스템에 크게 영향을 미침
    - 
>>>>>>> Stashed changes
