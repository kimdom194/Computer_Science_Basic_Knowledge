### CPU Scheduling

- 프로세스 실행 과정은 CPU burst와 I/O burst의 반복임
  - 프로세스의 특성 분류
    - CPU burst : 계산 위주의 job
      - load store
      - add store
      - read from file
    - I/O burst : 계산시간보다 I/O에 시간이 많이 필요한 job
      - store increment
      - index
      - write to file

- 여러 종류의 job(process)이 섞여 있기 때문에 CPU 스케줄링이 필요하다.
  - interactive job에게 적절한 response 제공 요망
  - CPU와 I/O 장치 등 시스템 자원을 골고루 효율적으로 사용



- ##### CPU Scheduler

  - Ready 상태의 프로세스 중에서 이번에 CPU를 줄 프로세스를 고른다.

- ##### Dispatcher

  - CPU의 제어권을 스케줄러에 의해 선택된 프로세스에게 넘긴다.
  - 이 과정을 문맥교환이라고 한다.

- CPU 스케줄링이 필요한 경우는 프로세스에게 다음과 같은 상태 변화가 있는 경우이다.

  1. Running > Blocked(I/O 요청 시스템 콜)

  2. Running > Ready(할당시간 만료로 timer interrupt)

  3. Blocked > Ready(I/O 완료 후 인터럽트)

  4. Terminate

  ##### 1번과 4번에서의 스케줄링은 강제로 빼앗지 않고 자진 반납한다. > 비선점 non preemptive

  ##### 나머지 스케줄링은 강제로 빼앗는다. > 선점 preemptive



### 성능 척도

- CPU 입장

  - 처리량
  - 이용률

- ##### 고객 입장

  - 반환 시간
  - 대기 시간
  - 응답 시간



### 비선점 종류

- FCFS
- SJF

### 선점 종류

- SRTF(선점형 SJF)
  - 최소 평균 대기 시간 보장
- Round Robin(RR)
  - 할당 시간을 가짐
  - 응답시간이 빨라진다.
  - 최소 N-1번의 응답시간만 기다리면 응답이 온다.



##### Multilevel Queue

- Ready queue를 여러개로 분할

- 각 큐는 독립적인 스케줄링 알고리즘을 가짐
- 큐에 대한 스케줄링이 필요



##### CPU 사용시간 예측법

- N+1번째 예측시간 = N번째 실제 사용시간 N번째 예측시간
- 사용시간은 사용 전에 알 수 없기에 예측만 가능함.



##### Multiple Processor Scheduling

CPU가 여러 개인 경우 스케줄링은 더욱 복잡해짐

- Homogeneous processor

  - 큐에 한줄로 세워서 각 프로세서가 알아서 꺼내가게 할 수 있다.
  - 반드시 특정 프로세서에서 실행되어야 하는 경우 복잡해짐

- ##### Load sharing

  - 일부 프로세서에 job이 몰리지 않도록 부하를 적절히 공유하는 매커니즘이 필요
  - 별개의 큐를 두는 방법 vs 공동 큐를 사용하는 방법

- Symmetric Multiprocessing(SMP)

  - 각 프로세서가 각자 알아서 스케줄링 결정

- Asymmetric multiprocessing

  - 하나의 프로세서가 시스템 데이터의 접근과 공유를 책임지고 나머지 프로세서는 거기에 따름



##### Real Time Scheduling

- Hard real time systems
  - 정해진 시간 안에 반드시 끝내도록 스케줄링해야 함

- Soft real time computing
  - 일반 프로세스에 비해 높은 priority를 갖도록 해야 함
- Local Scheduling
  - 유저 레벨 스레드의 경우 사용자 수준의 스레드 라이브러리에 의해 어떤 스레드를 스케줄할지 결정
- Global Scheduling
  - 커널 레벨 스레드의 경우 일반 프로세스와 마찬 가지로 커널의 단기 스케줄러가 어떤 스레드를 스케줄할지 결정



