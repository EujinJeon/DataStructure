#include <iostream>
using namespace std;

class corona_nation {
public:
    corona_nation(string name = "empty", int c_attack = 0, int c_dead = 0);
    void print_info();

    string country; // 지역명 입력받을 문자열
    int attack; // 감염자 수 입력받을 정수형 변수
    int dead; // 사망수 입력 받을 정수형 변수
    double deadrate; // 사망률을 입력 받을 실수형 변수

};


corona_nation::corona_nation(string name, int c_attack, int c_dead) {
    country = name;
    attack = c_attack;
    dead = c_dead;
    deadrate = ((double)dead / (double)attack) * 100;
};

void corona_nation::print_info() {
    cout.width(10);
    cout << country;
    cout.width(10);
    cout << attack;
    cout.width(10);
    cout << dead;
    cout.width(10);
    cout << deadrate;
}

template<class T>
class DLLNODE {
public:
    DLLNODE() {
        next = prev = 0;
    }

    DLLNODE(const T& el, DLLNODE *n = 0, DLLNODE *p = 0) {
        info = el;
        next = n;
        prev = p;
    }

    T info;
    DLLNODE* next, * prev;
};

template<class T>
class DLL {
public:
    DLL() {
        head = NULL;
    }

    ~DLL() {
        for (DLLNODE<T> *p=NULL; p != NULL; ) {
            p = head->next;
            delete head;
            head = p;
        }
    }


    void AddtoDLLSorted(const T& el);
    void deleteDLLSorted(const string &name);
    void printDLLSorted();
protected:
    DLLNODE<T>* head;
};

template<class T>
void DLL<T>::AddtoDLLSorted(const T& el) {
    DLLNODE<T>* tmp = new DLLNODE<T>(el);
    DLLNODE<T>* pt = new DLLNODE<T>;
    pt = head;
    if (pt == NULL) {
        pt = tmp;
        pt->next = NULL;
        head = tmp;

    }

    else {
        while (pt != NULL) {
            if (pt->info.country > tmp->info.country) {
                if (pt == head) {
                    pt->prev = tmp;
                    tmp->next = pt;
                    head = tmp;
                    break;
                }

                else if (pt->next != NULL && pt->prev!=NULL) {
                    pt->prev->next = tmp;
                    tmp->prev = pt->prev;
                    tmp->next = pt;
                    pt->prev = tmp;
                    break;
                }

                else if (pt->next == NULL) {
                    tmp->prev = pt->prev;
                    pt->prev = tmp;
                    tmp->next = pt;
                    break;
                }

            }

            else {
                if (pt->next == NULL) {
                    pt->next = tmp;
                    tmp->prev = pt;
                    break;
                }
            }//위에 if문의 조건이랑 안맞을때 데이터를 맨뒤에다가 넣는 작업
            pt = pt->next;
        }
    }
}

template<class T>
void DLL<T>::deleteDLLSorted(const string &name){
    DLLNODE<T>* tmp = new DLLNODE<T>;
    tmp = head;
    while (tmp != NULL) {
        if (tmp->info.country == name) {
            if (tmp == head) {
                tmp->next->prev = NULL;
                head = tmp->next;
                delete tmp;
                break;
            }

            else if (tmp->next != NULL && tmp->prev != NULL) {
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                delete tmp;
                break;
            }
            else if (tmp->next == NULL) {
                tmp->prev->next = NULL;
                delete tmp;
                break;
            }
        }
        else {
            tmp = tmp->next;
        }
    }
}

template<class T>
void DLL<T>::printDLLSorted() {
    DLLNODE<T>* ptr = new DLLNODE<T>;
    ptr = head;
    while (ptr!=NULL) {
        cout << ptr->info.country << "  ";
        cout << ptr->info.attack << "  ";
        cout << ptr->info.dead << "  ";
        cout << ptr->info.deadrate << "%" <<endl;
        ptr = ptr->next;
    }
}

int main() {
    DLL<corona_nation> DLLdata;

    DLLdata.AddtoDLLSorted(corona_nation("Korea", 13002, 5230));
    DLLdata.AddtoDLLSorted(corona_nation("USA", 102352, 12500));
    DLLdata.AddtoDLLSorted(corona_nation("China", 673100, 321000));
    DLLdata.AddtoDLLSorted(corona_nation("Germany", 107591, 2012));
    DLLdata.AddtoDLLSorted(corona_nation("Vietnam", 13112, 1103));
    DLLdata.AddtoDLLSorted(corona_nation("Italy", 135586, 17127));
    DLLdata.AddtoDLLSorted(corona_nation("France", 78167, 10328));
    DLLdata.AddtoDLLSorted(corona_nation("Iran", 55242, 6159));
    DLLdata.AddtoDLLSorted(corona_nation("Spain", 623112, 5152));
    DLLdata.AddtoDLLSorted(corona_nation("Japan", 23112, 1522));

    DLLdata.printDLLSorted();

    cout << "삭제하고 싶은 나라를 입력하세요 : ";
    string temp;
    cin >> temp;
    DLLdata.deleteDLLSorted(temp);
    DLLdata.printDLLSorted();



}