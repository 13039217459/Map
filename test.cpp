#include"Matrix.cpp"
void main(){
	int p[] = {1,2,3,4,5,6,7,8,9};
	Matrix m(3);
	m.set(p);
	m.show();
	Matrix m2=m.zhuanZhi(m);
	m2.show();
}