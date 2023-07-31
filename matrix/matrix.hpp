#ifndef MATRIX_HPP
#define MATRIX_HPP
#include<vector>
template<typename T>
struct Matrix{
	int a,b;
	std::vector<std::vector<T>> mat;
	T& operator() (int i,int j){
		return mat[i][j];
	}
	const T& operator() (int i,int j) const{
		return mat[i][j];
	}
	Matrix(int i,int j){
		a=i;
		b=j;
		mat.resize(i,std::vector<T>(j));
	}
	Matrix(std::vector<std::vector<T>> matrix){
		mat=move(matrix);
	}
	Matrix operator *(const Matrix& rhs) const{

	}
};
#endif
