#include <iostream>
#include <vector>
using namespace std;

class vector3d {
    float data[3];
public:
    vector3d() { data[2] = data[1] = data[0] = 0; }
    vector3d(float value) { data[2] = data[1] = data[0] = value; }
    vector3d(float a1, float a2, float a3) { data[0] = a1;  data[1] = a2; data[2] = a3; }
    float  operator[](int idx) const { return data[idx]; }
    float& operator[](int idx) { return data[idx]; }
};
ostream& operator <<(ostream& os, const vector3d& v) {
    return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}
vector3d operator + (const vector3d& v1, const vector3d& v2) {
    return vector3d(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
}
vector3d operator - (const vector3d& v1, const vector3d& v2) {
    return vector3d(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}
vector3d operator * (const vector3d& v1, const float x) {
    return vector3d(v1[0] * x, v1[1] * x, v1[2] * x);
}
vector3d operator / (const vector3d& v1, const float x) {
    return vector3d(v1[0] / x, v1[1] / x, v1[2] / x);
}
const vector3d operator -(const vector3d& v1) {
    return vector3d(-v1[0], -v1[1], -v1[2]);
}
const vector3d operator !(const vector3d& v1) {
    if (v1[0] == 0 && v1[1] == 0 && v1[2] == 0) {
        return vector3d(1, 1, 1);
    }
    else
        return vector3d(0, 0, 0);
}
bool test_vector3d(vector <vector3d> Vec, vector3d v1, vector3d v2, float v3) {
    bool check = true;
    for (int i = 0; i < Vec.size(); ++i) {
        switch (i)
        {
        case 0:
            if ((Vec[i][0] == (v1[0] + v2[0])) && (Vec[i][1] == (v1[1] + v2[1])) && (Vec[i][2] == (v1[2] + v2[2])))
                cerr << "�������� �������� " << v1 << " � " << v2 << " - ��������� " << endl;
            else
            {
                cerr << "�������� �������� " << v1 << " � " << v2 << " - �������" << endl;
                check = false;
            }
            break;

        case 1:
            if ((Vec[i][0] == (v1[0] - v2[0])) && (Vec[i][1] == (v1[1] - v2[1])) && (Vec[i][2] == (v1[2] - v2[2])))
                cerr << "����2: �������� ��������  �������� " << v1 << " � " << v2 << " - ���������" << endl;
            else
            {
                cerr << "����2: �������� �������� �������� " << v1 << " � " << v2 << " - �������" << endl;
                check = false;
            }
            break;
        case 2:
            if ((Vec[i][0] == (v1[0] * v3)) && (Vec[i][1] == (v1[1] * v3)) && (Vec[i][2] == (v1[2] * v3)))
                cerr << "����3: �������� �������� ��������� ������� �� ������ " << v1 << " �� " << v3 << " - ���������" << endl;
            else
            {
                check = false;
                cerr << "����3: �������� �������� ��������� ������� �� ������ " << v1 << " �� " << v3 << " - �������" << endl;
            }
            break;
        case 3:
            if ((Vec[i][0] == (v1[0] / v3)) && (Vec[i][1] == (v1[1] / v3)) && (Vec[i][2] == (v1[2] / v3)))
                cerr << "����4: �������� �������� ������� ������� �� ������ " << v1 << " �� " << v3 << " - ���������" << endl;
            else
            {
                check = false;
                cerr << "����4: �������� �������� ������� ������� �� ������ " << v1 << " �� " << v3 << " - �������" << endl;
            }
            break;
        case 4:
            if ((Vec[i][0] == (-v1[0])) && (Vec[i][1] == (-v1[1])) && (Vec[i][2] == (-v1[2])))
                cerr << "����5: ������� �������� �������������� ����� �������  " << v1 << " - ���������" << endl;
            else
            {
                check = false;
                cerr << "����5: ������� �������� �������������� ����� �������  " << v1 << " - �������" << endl;
            }
            break;

        default:
            vector3d v(0, 0, 0);
            if (i == 5)
                v = v1;
            if (v[0] == 0 && v[1] == 0 && v[2] == 0) {
                if ((Vec[i][0] == 1) && (Vec[i][1] == 1) && (Vec[i][2] == 1)) {
                    cerr << "����" << i + 1 << ": ������� ! ������� " << v << " - ���������" << endl;
                }
                else {
                    check = false;
                    cerr << "����" << i + 1 << ": ������� ! ������� " << v << " - �������" << endl;
                }
            }
            else {
                if ((Vec[i][0] == 0) && (Vec[i][1] == 0) && (Vec[i][2] == 0)) {
                    cerr << "����" << i + 1 << ": ������� ! ������� " << v << " - ���������" << endl;
                }
                else {
                    check = false;
                    cerr << "����" << i + 1 << ": ������� ! ������� " << v << " - �������" << endl;
                }
            }
            break;
        }
    }
    return check;
}

int main(int x, char** y) {
    vector3d v1(12), v2(3, -4, 2), v3, v4, v5, v6, v7, v8, v9, v10;
    vector <vector3d> Vect;
    float v3 = 0.5;
    v4 = v1 + v2; Vect.push_back(v4);
    v5 = v1 - v2; Vect.push_back(v5);
    v6 = v1 * v3; Vect.push_back(v6);
    v7 = v1 / v3; Vect.push_back(v7);
    v8 = -v1; Vect.push_back(v8);
    v9 = !v1; Vect.push_back(v9);
    v10 = !v9; Vect.push_back(v10);
    cout << " First : " << v4 << " Second : " << v5 << " Third : " << v6 << " Fourth : " << v7 << " Fifth : " << v8 << " Sixth : " << v9 << " Seventh : " << v10 << endl;
    bool Check = test_vector3d(Vect, v1, v2, v3);
    return 0;
}