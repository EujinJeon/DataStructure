#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

//코로나 관련 입력값을 받을 클래스
class Corona_World {
public:

    //private에 선언된 변수들에 접근하기 위한 설정
    friend int main(void);
    friend bool cmpc(const Corona_World& a, const Corona_World& b);
    friend bool cmpattack(const Corona_World& a, const Corona_World& b);
    friend bool cmpdead(const Corona_World& a, const Corona_World& b);
    friend bool cmpdeadper(const Corona_World& a, const Corona_World& b);

private:
    string country; // 지역명 입력받을 문자열
    int attack; // 감염자 수 입력받을 정수형 변수
    int dead; // 사망수 입력 받을 정수형 변수
    double deadper; // 사망률을 입력 받을 실수형 변수

};

bool cmpc(const Corona_World& a, const Corona_World& b) { 
    return a.country < b.country;
}// 지역명 순으로 정렬하기 위한 함수 선언

bool cmpattack(const Corona_World& a, const Corona_World& b) {
    return a.attack > b.attack;
}// 감염자 순으로 정렬하기 위한 함수 선언

bool cmpdead(const Corona_World& a, const Corona_World& b) {
    return a.dead > b.dead;
}// 사망자 순으로 정렬하기 위한 함수 선언

bool cmpdeadper(const Corona_World& a, const Corona_World& b) {
    return a.deadper > b.deadper;
}// 사망률 순으로 정렬하기 위한 함수 선언


int main(void)
{
    int cnum; // 사용자에게 입력값을 받아 몇개의 나라를 입력할 것인지 정해주는 정수형 변수
    int rota; // 밑에 제어문을 사용하기 위한 변수
    int num; // 사용자에게 입력값을 받아 반복문 안에서 탈출 시킬지 정해주는 변수
    int call=0;
    Corona_World temp;
    vector<Corona_World> data; // 클래스 타입으로 벡터 선언
   
        cout << "몆개의 나라를 입력하실 건가요?" << endl;
        cin >> cnum;
   

    for (int i = 0; i < cnum; i++) {
        cout << "나라 이름을 입력하시오." << endl;
        cin >> temp.country;
        cout << "감염자 수를 입력하시오." << endl;
        cin >> temp.attack;
        cout << "사망자 수를 입력하시오." << endl;
        cin >> temp.dead;
        temp.deadper = (double)temp.dead / (double)temp.attack * 100;
        data.push_back(temp);
    }

    while (1) {
        cout << "1. 자료 삭제" << endl;
        cout << "2. 국가명 순으로 출력" << endl;
        cout << "3. 감염자 순으로 출력" << endl;
        cout << "4. 사망자 순으로 출력" << endl;
        cout << "5. 사망률 순으로 출력" << endl;
        cout << "필요하신 기능을 선택해세요.";
        cin >> rota;
        

        if (rota == 1) {
            for (int i = 0; i < data.size(); i++) {
                cout <<i+1<<"." <<"나라 이름 : " << data[i].country << " 감염자 수 : " << data[i].attack << " 사망자 수 : " << data[i].dead
                    << " 사망률 : " << data[i].deadper << "%" << endl;
            }
            cout << "몇번째 데이터를 삭제 하시겠습니까? : ";
            cin >> call;// 몆번째 자료를 삭제할지 입력받문구
            if (call>cnum){
                cout << "숫자를 잘 못 입력하셨습니다.\n숫자를 다시 입력해주세요.";
                cin >> call;
            }
            data.erase(data.begin() +(call-1));
            cout << "프로그램을 종료하시려면 1번을 눌러주세요.\n계속 하시려면 아무 번호나 입력하시오.";
            cin >> num;
            if (num == 1) break;
            else continue;
        }// 벡터로 받은 입력값을 삭제하는 기능

        if (rota == 2) {
            sort(data.begin(), data.end(), cmpc);
            for (int i = 0; i < data.size(); i++) {
                cout << "나라 이름 : " << data[i].country << " 감염자 수 : " << data[i].attack << " 사망자 수 : " << data[i].dead
                    << " 사망률 : " << data[i].deadper << "%" << endl;
            }
            cout << "프로그램을 종료하시려면 1번을 눌러주세요.\n계속 하시려면 아무 번호나 입력하시오.";
            cin >> num;
            if (num == 1) break;
            else continue;
        }// 국가 명으로 정렬

        if (rota == 3) {
            sort(data.begin(), data.end(), cmpattack);
            for (int i = 0; i < data.size(); i++) {
                cout << "나라 이름 : " << data[i].country << " 감염자 수 : " << data[i].attack << " 사망자 수 : " << data[i].dead
                    << " 사망률 : " << data[i].deadper << "%" << endl;
            }
            cout << "프로그램을 종료하시려면 1번을 눌러주세요.\n계속 하시려면 아무 번호나 입력하시오.";
            cin >> num;
            if (num == 1) break;
            else continue;
        }// 감염자 순으로 정렬(내림차순)

        if (rota == 4) {
            sort(data.begin(), data.end(), cmpdead);
            for (int i = 0; i < data.size(); i++) {
                cout << "나라 이름 : " << data[i].country << " 감염자 수 : " << data[i].attack << " 사망자 수 : " << data[i].dead
                    << " 사망률 : " << data[i].deadper << "%" << endl;
            }
            cout << "프로그램을 종료하시려면 1번을 눌러주세요.\n계속 하시려면 아무 번호나 입력하시오.";
            cin >> num;
            if (num == 1) break;
            else continue;
        }// 사망자 순으로 정렬(내림차순)

        if (rota == 5) {
            sort(data.begin(), data.end(), cmpdeadper);
            for (int i = 0; i < data.size(); i++) {
                cout << "나라 이름 : " << data[i].country << " 감염자 수 : " << data[i].attack << " 사망자 수 : " << data[i].dead
                    << " 사망률 : " << data[i].deadper << "%" << endl;
            }
            cout << "프로그램을 종료하시려면 1번을 눌러주세요.\n계속 하시려면 아무 번호나 입력하시오.";
            cin >> num;
            if (num == 1) break;
            else continue;
        }// 사망률 순으로 정렬(내림차순)
    }
        

}