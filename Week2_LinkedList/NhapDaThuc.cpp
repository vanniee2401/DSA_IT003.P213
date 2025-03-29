// template
#include <bits/stdc++.h>
using namespace std;

struct DONTHUC
{
    int somu;
    double heso;

    DONTHUC(double _heso = 0, int _somu = 0)
    {
        heso = _heso;
        somu = _somu;
    }

    DONTHUC &operator=(const DONTHUC &rhs)
    {
        if (this == &rhs)
            return *this;
        this->heso = rhs.heso;
        this->somu = rhs.somu;
        return *this;
    }
};

struct Node
{
    DONTHUC *data;
    Node *next;

    Node(DONTHUC *_data = nullptr)
    {
        this->data = _data;
        this->next = nullptr;
    }
};

struct DATHUC
{
    Node *head;
    Node *tail;
    DATHUC()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
};

// ###INSERT CODE HERE -

void Nhap(DATHUC &B, double heso, int somu)
{
    Node *newNode = new Node(new DONTHUC(heso, somu));

    if (B.head == nullptr)
    {
        B.head = B.tail = newNode;
    }
    else
    {
        B.tail->next = newNode;
        B.tail = newNode;
    }
}

void Xuat(DATHUC &B)
{
    Node *current = B.head;
    bool first = true;
    int count = 0;
    bool hasNonZeroTerm = false;
    while (current != nullptr)
    {
        int somu = current->data->somu;
        double heso = current->data->heso;
        if (heso != 0)
        {
            hasNonZeroTerm = true;
            if (!first)

                if (heso > 0)
                    cout << "+";
            if (heso < 0)
                cout << "-";
            if (somu == 0)
                cout << abs(heso);
            else
            {
                if (abs(heso) != 1 && somu > 0)
                    cout << abs(heso);
                cout << "x";
                if (somu > 1)
                    cout << "^" << somu;
            }
            first = false;
        }
        current = current->next;
    }
    if (!hasNonZeroTerm)
        cout << "0";
    cout << endl;
}

double TinhDaThuc(DATHUC &B, double x)
{
    double result = 0;
    Node *current = B.head;
    while (current != nullptr)
    {
        result += current->data->heso * pow(x, current->data->somu);
        current = current->next;
    }
    return result;
}

int main()
{
    DATHUC B;
    int N;

    cin >> N;
    for (int test = 0; test < N; test++)
    {
        double heso;
        int somu;
        cin >> heso >> somu;
        Nhap(B, heso, somu);
    }

    cout << "Da thuc vua nhap la: ";
    Xuat(B);
    double x;
    cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
