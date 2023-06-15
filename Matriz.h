#pragma once
#include <vector>
#include <iostream>
#include <math.h>   
using namespace std;

#define PI 3.14159265

const vector<int> z_indices = { 0,0,0,1,1,0,1,1 };
const vector<int> z_indices1 = { 0,0,0,0,0,0,0,0 };
const vector<int> y_indices = { 0,0,2,0,0,2,2,2 };
const vector<int> y_indices1 = { 0,0,0,1,0,0,0,0 };
const vector<int> x_indices = { 1,1,1,2,2,1,2,2 };
const vector<int> x_indices1 = { 0,0,0,0,0,0,0,0 };

class matrix
{

public:
    vector< vector<float> > m;
    int r, c;
    matrix()
    {
        this->r = this->c = 0;
    }

    matrix(int _r, int _c) {
        this->r = _r;
        this->c = _c;
        m.resize(r);
        for (int i = 0; i < r; i++)
        {
            m[i].resize(c);
        }
    }

    matrix(vector< vector<float> > _m) {
        m = _m;
        this->r = _m.size();
        this->c = _m[0].size();
    }

    matrix(vector<float> v) {
        for (int i = 0; i < v.size(); i++)
        {
            vector<float> temp(1, v[i]);
            m.push_back(temp);
        }

        this->r = m.size();
        this->c = m[0].size();
    }

    matrix mult(matrix n)
    {
        if (this->c != n.r)
        {
            cout << "c: " << c << endl;
            cout << "n.r: " << n.r << endl;
            cout << "no se puede multiplicar" << endl;
            return matrix();
        }
        matrix res(this->r, n.c);
        for (int i = 0; i < this->r; i++)
        {
            for (int j = 0; j < n.c; j++)
            {
                res.m[i][j] = 0;
                for (int k = 0; k < n.r; k++)
                {
                    res.m[i][j] = res.m[i][j] + m[i][k] * n.m[k][j];
                }
            }
        }

        return res;
    }

    void print() {

        for (int i = 0; i < this->r; i++)
        {
            for (int j = 0; j < this->c; j++)
            {
                cout << m[i][j] << '\t';
            }
            cout << endl;
        }

        cout << endl;
    }

    static matrix GenIdentity(int size)
    {
        vector<vector<float>> m_identity(size);

        for (int i = 0; i < size; i++)
        {
            vector<float> row(size, 0);
            row[i] = 1;
            m_identity[i] = row;
        }
        matrix Identity(m_identity);
        return Identity;
    }

    static matrix GenScale(vector<float> s_axis, int size)
    {

        vector<vector<float>> m_scale(size);
        for (int i = 0; i < size; i++)
        {
            vector<float> row(size, 0);
            if (i < s_axis.size())
            {
                row[i] = s_axis[i];
            }
            else
            {
                row[i] = 1;
            }
            m_scale[i] = row;
        }

        matrix Scale(m_scale);
        return Scale;
    }

    static matrix GenTranslation(vector<float> t_axis, int size)
    {

        vector<vector<float>> m_translation(size);
        for (int i = 0; i < size; i++)
        {
            vector<float> row(size, 0);
            row[i] = 1;
            if (i < t_axis.size())
            {
                row[row.size() - 1] = t_axis[i];
            }
            m_translation[i] = row;
        }

        matrix Translation(m_translation);
        return Translation;
    }


    static matrix GenRotate(double angule, char axi, int size)
    {
        vector <int> indices;
        switch (axi)
        {
        case 'x':
            indices = x_indices; break;
        case 'y':
            indices = y_indices; break;
        case 'z':
            indices = z_indices; break;
        deafult:
            return matrix();
        }

        double radian_angule = angule * PI / 180.0;

        double _cos = cos(radian_angule);
        double _sin = sin(radian_angule);
        double _n_sin = -sin(radian_angule);

        matrix Rotate = GenIdentity(size);

        Rotate.m[indices[0]][indices[1]] = _cos;
        Rotate.m[indices[2]][indices[3]] = _n_sin;
        Rotate.m[indices[4]][indices[5]] = _sin;
        Rotate.m[indices[6]][indices[7]] = _cos;
        return Rotate;
    }

    static matrix GenRotate1(double angule, char axi, int size)
    {
        vector <int> indices;
        switch (axi)
        {
        case 'x':
            indices = x_indices1; break;
        case 'y':
            indices = y_indices1; break;
        case 'z':
            indices = z_indices; break;
        default:
            return matrix();
        }

        double radian_angule = angule * PI / 180.0;

        double _cos = cos(radian_angule);
        double _sin = sin(radian_angule);
        double _n_sin = -sin(radian_angule);

        matrix Rotate = GenIdentity(size);

        Rotate.m[indices[0]][indices[1]] = _sin;
        Rotate.m[indices[2]][indices[3]] = _sin;
        Rotate.m[indices[4]][indices[5]] = 1;
        Rotate.m[indices[6]][indices[7]] = 1;
        
        
        return Rotate;
    }

};