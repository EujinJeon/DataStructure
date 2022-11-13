#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

//�ڷγ� ���� �Է°��� ���� Ŭ����
class Corona_World {
public:

    //private�� ����� �����鿡 �����ϱ� ���� ����
    friend int main(void);
    friend bool cmpc(const Corona_World& a, const Corona_World& b);
    friend bool cmpattack(const Corona_World& a, const Corona_World& b);
    friend bool cmpdead(const Corona_World& a, const Corona_World& b);
    friend bool cmpdeadper(const Corona_World& a, const Corona_World& b);

private:
    string country; // ������ �Է¹��� ���ڿ�
    int attack; // ������ �� �Է¹��� ������ ����
    int dead; // ����� �Է� ���� ������ ����
    double deadper; // ������� �Է� ���� �Ǽ��� ����

};

bool cmpc(const Corona_World& a, const Corona_World& b) { 
    return a.country < b.country;
}// ������ ������ �����ϱ� ���� �Լ� ����

bool cmpattack(const Corona_World& a, const Corona_World& b) {
    return a.attack > b.attack;
}// ������ ������ �����ϱ� ���� �Լ� ����

bool cmpdead(const Corona_World& a, const Corona_World& b) {
    return a.dead > b.dead;
}// ����� ������ �����ϱ� ���� �Լ� ����

bool cmpdeadper(const Corona_World& a, const Corona_World& b) {
    return a.deadper > b.deadper;
}// ����� ������ �����ϱ� ���� �Լ� ����


int main(void)
{
    int cnum; // ����ڿ��� �Է°��� �޾� ��� ���� �Է��� ������ �����ִ� ������ ����
    int rota; // �ؿ� ����� ����ϱ� ���� ����
    int num; // ����ڿ��� �Է°��� �޾� �ݺ��� �ȿ��� Ż�� ��ų�� �����ִ� ����
    int call=0;
    Corona_World temp;
    vector<Corona_World> data; // Ŭ���� Ÿ������ ���� ����
   
        cout << "�p���� ���� �Է��Ͻ� �ǰ���?" << endl;
        cin >> cnum;
   

    for (int i = 0; i < cnum; i++) {
        cout << "���� �̸��� �Է��Ͻÿ�." << endl;
        cin >> temp.country;
        cout << "������ ���� �Է��Ͻÿ�." << endl;
        cin >> temp.attack;
        cout << "����� ���� �Է��Ͻÿ�." << endl;
        cin >> temp.dead;
        temp.deadper = (double)temp.dead / (double)temp.attack * 100;
        data.push_back(temp);
    }

    while (1) {
        cout << "1. �ڷ� ����" << endl;
        cout << "2. ������ ������ ���" << endl;
        cout << "3. ������ ������ ���" << endl;
        cout << "4. ����� ������ ���" << endl;
        cout << "5. ����� ������ ���" << endl;
        cout << "�ʿ��Ͻ� ����� �����ؼ���.";
        cin >> rota;
        

        if (rota == 1) {
            for (int i = 0; i < data.size(); i++) {
                cout <<i+1<<"." <<"���� �̸� : " << data[i].country << " ������ �� : " << data[i].attack << " ����� �� : " << data[i].dead
                    << " ����� : " << data[i].deadper << "%" << endl;
            }
            cout << "���° �����͸� ���� �Ͻðڽ��ϱ�? : ";
            cin >> call;// �p��° �ڷḦ �������� �Է¹޹���
            if (call>cnum){
                cout << "���ڸ� �� �� �Է��ϼ̽��ϴ�.\n���ڸ� �ٽ� �Է����ּ���.";
                cin >> call;
            }
            data.erase(data.begin() +(call-1));
            cout << "���α׷��� �����Ͻ÷��� 1���� �����ּ���.\n��� �Ͻ÷��� �ƹ� ��ȣ�� �Է��Ͻÿ�.";
            cin >> num;
            if (num == 1) break;
            else continue;
        }// ���ͷ� ���� �Է°��� �����ϴ� ���

        if (rota == 2) {
            sort(data.begin(), data.end(), cmpc);
            for (int i = 0; i < data.size(); i++) {
                cout << "���� �̸� : " << data[i].country << " ������ �� : " << data[i].attack << " ����� �� : " << data[i].dead
                    << " ����� : " << data[i].deadper << "%" << endl;
            }
            cout << "���α׷��� �����Ͻ÷��� 1���� �����ּ���.\n��� �Ͻ÷��� �ƹ� ��ȣ�� �Է��Ͻÿ�.";
            cin >> num;
            if (num == 1) break;
            else continue;
        }// ���� ������ ����

        if (rota == 3) {
            sort(data.begin(), data.end(), cmpattack);
            for (int i = 0; i < data.size(); i++) {
                cout << "���� �̸� : " << data[i].country << " ������ �� : " << data[i].attack << " ����� �� : " << data[i].dead
                    << " ����� : " << data[i].deadper << "%" << endl;
            }
            cout << "���α׷��� �����Ͻ÷��� 1���� �����ּ���.\n��� �Ͻ÷��� �ƹ� ��ȣ�� �Է��Ͻÿ�.";
            cin >> num;
            if (num == 1) break;
            else continue;
        }// ������ ������ ����(��������)

        if (rota == 4) {
            sort(data.begin(), data.end(), cmpdead);
            for (int i = 0; i < data.size(); i++) {
                cout << "���� �̸� : " << data[i].country << " ������ �� : " << data[i].attack << " ����� �� : " << data[i].dead
                    << " ����� : " << data[i].deadper << "%" << endl;
            }
            cout << "���α׷��� �����Ͻ÷��� 1���� �����ּ���.\n��� �Ͻ÷��� �ƹ� ��ȣ�� �Է��Ͻÿ�.";
            cin >> num;
            if (num == 1) break;
            else continue;
        }// ����� ������ ����(��������)

        if (rota == 5) {
            sort(data.begin(), data.end(), cmpdeadper);
            for (int i = 0; i < data.size(); i++) {
                cout << "���� �̸� : " << data[i].country << " ������ �� : " << data[i].attack << " ����� �� : " << data[i].dead
                    << " ����� : " << data[i].deadper << "%" << endl;
            }
            cout << "���α׷��� �����Ͻ÷��� 1���� �����ּ���.\n��� �Ͻ÷��� �ƹ� ��ȣ�� �Է��Ͻÿ�.";
            cin >> num;
            if (num == 1) break;
            else continue;
        }// ����� ������ ����(��������)
    }
        

}