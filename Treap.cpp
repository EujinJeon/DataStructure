#include <iostream>
using namespace std;

class corona_nation {
public:
    corona_nation(string name = "empty", int c_attack = 0, int c_dead = 0);

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

template<class T>
class TREAPNode {
public :
    TREAPNode() {
        left = right = 0;
    }
    TREAPNode(const T& el, TREAPNode<T>* l = 0, TREAPNode<T>* r = 0) {
        info = el; left = l; right = r;
        priority = el.deadrate;
        key = el.country;
    }
    T info; // 코로나 정보가 들어가는 변수
    string key; // BST 조건값을 충족하기 위한 Value값
    double priority; // 우선순위
    TREAPNode<T>* left, * right; //TREE Left Right값 노드 생성
};

template<class T>
class TREAP {
public:
    TREAP() {
        root = NULL;
    }

    ~TREAP() {
        clear();
    }

    void clear() {
        root = 0;
    }

    bool isEmpty()const {
        return root == 0;
    }

    void search(string nation) const {
        int steps = 0; // 원하는 값을 찾을 때까지 몇번 거쳤는지 카운트하기 위한 변수
        search(nation, steps); 
    }

    void insert(const T&);
    void erase();
protected:
    TREAPNode<T>* root;
    TREAPNode<T> *Insert(TREAPNode<T>* p, const T& el); //실질적인 인서트가 일어나는 함수
    TREAPNode<T>* Delete(TREAPNode<T>*); //실질적인 삽입이 일어나는 함수
    void search(string key, int step) const;
    TREAPNode<T>* rotateleft(TREAPNode<T>*); // 삽입과 삭제가 이루어져도 HEAPS와 BST 조건을 충족하기 위한 기능
    TREAPNode<T>* rotateright(TREAPNode<T>*); //삽입과 삭제가 이루어져도 HEAPS와 BST 조건을 충족하기 위한 기능
};

template <class T>
void TREAP<T> ::search(string key, int steps) const {
    TREAPNode<T>* p = root;
    while (p != 0) {
        if (p->key == key) { //입력값이랑 찾은 값이 같으면 밑에 명령어 실행
            cout << endl;
            cout << p->key << "를 찾았습니다." << endl;
            cout << steps << "번 거쳤습니다." << endl;
            break;
        }
        else if (p->key > key) {
            steps++;
            cout << p->key << "를 거쳤습니다." << endl;
            p = p->left;
        }// 입력값이 현재의 key값보다 작으면 왼쪽으로 이동
        else {
            steps++;
            cout << p->key << "를 거쳤습니다." << endl;
            p = p->right;
        }//입력값이 현재의 key값보다 크면 오른쪽으로 이동
    }
}

template <class T>
void TREAP<T> ::insert(const T& el) {
    TREAPNode<T>* corona = root;
    root = Insert(corona, el);
}
template <class T>
TREAPNode<T> *TREAP<T>::Insert(TREAPNode<T>* p, const T& el) {
    TREAPNode<T>* tmp = new TREAPNode<T>(el);
    if (p == NULL) {
        return new TREAPNode<T>(el);
    } //재귀의 무한 반복을 방지하고 빈노드에 도착했을때 새로운 노드 생성

    if (p->key < tmp->key) {
        p->right = Insert(p->right, el); // 재귀를 통한 구현
        if (p->priority < p->right->priority) {
            p=rotateleft(p);
        }// 현재 노드의 우선순위 값보다 오른쪽 노드의 우선순위 값이 크면 왼쪽으로 회전
    }

    else {
        p->left = Insert(p->left, el); // 재귀를 통한 구현
        if (p->priority < p->left->priority) {
            p=rotateright(p);
        }//현재 노드의 우선순위 값보다 왼쪽 노드의 우선순위 값이 크면 오른쪽으로 회전
    }
    return p;
}

template <class T>
void TREAP<T> :: erase(){
    root = Delete(root);
    cout << "Root 값을 삭제했습니다." << endl;
}
template <class T>
TREAPNode<T>* TREAP<T> ::Delete(TREAPNode<T>* p) {
    p->priority = -std::numeric_limits<double>::infinity(); // priority를 -무한대로 변환
    if (p == NULL) {
        return p;
    } // 재귀함수의 무한반복 방지

    else {
        if (p->left==NULL && p->right==NULL) {
            delete p;
            p = NULL;
        }

        else if(p->left != NULL && p->right != NULL) {
            if (p->left->priority < p->right->priority) { // 현재노드의 왼쪽 오른쪽의 우선순위를 비교해서 큰쪽으로 이동
                p = rotateleft(p);
                p->left = Delete(p->left);
            }
            else {
                p = rotateright(p);
                p->right = Delete(p->right);
            }
        }
        else if (p->right == NULL) {  // 현재 노드의 오른쪽이 비어있으면
            TREAPNode<T>* tmp = p->left; // 현재 노드의 왼쪽 노드를 임시로 만들어둔 노드에 집어 놓고
            delete p;                   // 그 노드를 지우고
            p = tmp;                    // 임시 노드에 넣어뒀던 왼쪽 노드를 삭제돼서 지워진 노드공간에 다시 집어넣는다
         }

        else if(p->left == NULL) {      // 현재 노드의 왼쪽이 비어있으면
           TREAPNode<T>* tmp = p->right;// 현재 노드의 오른쪽 노드를 임시로 만들어둔 노드에 집어 놓고
           delete p;                   // 그 노드를 지우고
           p = tmp;                    // 임시 노드에 넣어뒀던 오른쪽 노드를 삭제돼서 지워진 노드공간에 다시 집어넣는다
        }
        
    }
    return p;
}

template <class T>
TREAPNode<T>* TREAP<T> ::rotateleft(TREAPNode<T>* p) {
    TREAPNode<T>* tmp = p->right;
    TREAPNode<T>* tmp2 = p->right->left;

    tmp->left = p;
    p->right = tmp2;
    p = tmp;
    return tmp;
}

template <class T>
TREAPNode<T>* TREAP<T> ::rotateright(TREAPNode<T>* p) {
    TREAPNode<T>* tmp = p->left;
    TREAPNode<T>* tmp2 = p->left->right;

    tmp->right = p;
    p->left = tmp2;
    p = tmp;
    return tmp;
}

int main() {
    string country;
    TREAP<corona_nation> treap;
    treap.insert(corona_nation("Korea", 13002, 5230));
    treap.insert(corona_nation("USA", 1745606, 102798));
    treap.insert(corona_nation("China", 673100, 321000));
    treap.insert(corona_nation("Germany", 107591, 2012));
    treap.insert(corona_nation("Vietnam", 13112, 1103));
    treap.insert(corona_nation("Italy", 135586, 17127));
    treap.insert(corona_nation("France", 78167, 10328));
    treap.insert(corona_nation("Iran", 55242, 6159));
    treap.insert(corona_nation("Spain", 238564, 27121));
    treap.insert(corona_nation("Japan", 23112, 1522));
    treap.insert(corona_nation("Arab", 5333, 214));

    cout << "찾고 싶은 나라를 입력해주세요.(한국, 미국, 중국, 독일, 이란, 베트남, 이탈리아, 프랑스, 스페인, 일본, 아랍)"<<endl;
    cin >> country;
    treap.search(country);
    treap.erase();
    
	return 0;
}