#pragma once 

#include <iostream>
#include <cmath>

class vector {
public:
	vector(float x = 0, float y = 0)
	:_x(x), _y(y) {}

    void setPoint(float x, float y) {
        _x = x;
        _y = y;
    }
    
    std::pair<float, float> getPoint() {
        return {_x, _y};
    }

	float length() {
		return sqrt(pow(_x, 2) + pow(_y, 2));
	}

	void printPoint() {
        std::cout << "Point: { " << _x << ", " << _y << " }" << std::endl;
	}
    
    void printLength() {
        std::cout << "Length of vector: " << length() << std::endl;
    }
    
    ~vector() = default;

protected:
	float _x;
	float _y;
};

class vectorE: public vector {
public:
    vectorE(float x = 0, float y = 0, float z = 0)
    :vector(x, y), _z(z){}
    
    void getPoint(float x, float y, float z) {
        _x = x;
        _y = y;
        _z = z;
    }

    float length() {
        return sqrt(pow(_x, 2) + pow(_y, 2) + pow(_z, 2));
    }
    
    void printPoint() {
        std::cout << "Point: { " << _x << ", " << _y <<  ", " << _z << " }" << std::endl;
    }
    
    void printLength() {
        std::cout << "Length of vector: " << length() << std::endl;
    }
    
    ~vectorE() = default;
protected:
    float _z;
};