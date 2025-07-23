#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
template<typename T>
class Polynomial{
    vector<T> coefficients;
    public:
    Polynomial(vector<T> coeffs){
        coefficients=coeffs;
    }
    T evaluate(T x){
        T result=0;
        for(int i=0;i<coefficients.size();i++){
            result+=coefficients[i]*pow(x,i);
        }
        return result;
    }
    Polynomial<T> operator+(const Polynomial<T>& other){
        Polynomial<T> result(coefficients);
        for(int i=0;i<other.coefficients.size();i++){
            result.coefficients[i]+=other.coefficients[i];
        }
        return result;
    }
};
int main(){
    vector<int> coeffs1={1,2,3};
    vector<int> coeffs2={4,5,6};
    Polynomial<int> p1(coeffs1);
    Polynomial<int> p2(coeffs2);
    Polynomial<int> p3=p1+p2;
    cout<<p3.evaluate(2)<<endl;
    return 0;
}
