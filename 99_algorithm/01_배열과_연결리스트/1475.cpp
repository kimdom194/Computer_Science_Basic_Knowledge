/* 
다솜이는 은진이의 옆집에 새로 이사왔다. 다솜이는 자기 방 번호를 예쁜 플라스틱 숫자로 문에 붙이려고 한다.

다솜이의 옆집에서는 플라스틱 숫자를 한 세트로 판다. 한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다. 다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의 최솟값을 출력하시오. (6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.)

입력
첫째 줄에 다솜이의 방 번호 N이 주어진다. N은 1,000,000보다 작거나 같은 자연수 또는 0이다.

출력
첫째 줄에 필요한 세트의 개수를 출력한다.
*/

#include <bits/stdc++.h>

using namespace std;
int main(void){
    string roomNum;
    cin >> roomNum; // 방번호 입력
    int roomlen = roomNum.length(); // 방번호 길이
    string arrRoom[roomlen];
    
    for(int i = 0; i < roomlen; i++){ // 배열에 방번호 삽입
        arrRoom[i] = roomNum.substr(i,1);
    }

    int cnt[10] = {0}; // 카운트 어레이 입력

    for(int i = 0; i < roomlen; i++){
        for(int j = 0; j < 10; j++){
            string k = to_string(j);
            if(k.compare(arrRoom[i]) == 0){ // 일치하면 카운트 + 1
                    cnt[j] = cnt[j] + 1;
            }
        }
    }

    if((cnt[9]+cnt[6]) % 2 == 0){
        cnt[6], cnt[9] = (cnt[9]+cnt[6]) / 2;
    }else{
        cnt[6], cnt[9] = (cnt[9]+cnt[6]) / 2 + 1;
    }
    cout << *max_element(cnt, cnt+10) << endl; //맥스값으로 세트수 계산
    
}