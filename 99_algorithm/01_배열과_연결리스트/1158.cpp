/*
https://www.acmicpc.net/problem/1158
조세퍼스 문제는 다음과 같다.

1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 이제 순서대로 K번째 사람을 제거한다. 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다. 이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 원에서 사람들이 제거되는 순서를 (N, K)-조세퍼스 순열이라고 한다. 예를 들어 (7, 3)-조세퍼스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.

N과 K가 주어지면 (N, K)-조세퍼스 순열을 구하는 프로그램을 작성하시오.
*/

#include <bits/stdc++.h>

using namespace std;
int main(void) {
    vector<int> v;
    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++){ //벡터에 값 채우기
        v.push_back(i);
        }

    vector<int>::iterator it; //포인터
    it = v.begin(); //포인터 처음으로 보내고

    cout << "<";
    while (v.size() != 1) {
        for (int i = 0; i < K-1; i++) { // K번 돌리는 코드
            it++;
            if (it == v.end()){
                it = v.begin();     
            }
        }
        cout << *it <<", "; // 현재위치 값 출력
        v.erase(it); // 지우고
        if (it == v.end()){
            it = v.begin();
            }
    }
    cout << *it << ">";
}