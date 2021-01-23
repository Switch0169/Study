#include<iostream>
#include<cstring>
using namespace std;
class CN; //提前声明
class EN; //提前声明

class Weight { //抽象类
protected:
    char kind[20]; //计重类型
    int gram; //克
public:
    Weight(int tg, const char tk[])
    {
        gram = tg;
        strcpy(kind, tk);
    }
    virtual void Print(ostream& out) { //输出不同类型的计重信息

    }
};
class EN : public Weight { //英国计重
protected:
    int B;
    int A;
    int D;
public:
    EN(int rB, int rA, int rD, int g, const char k[]) :Weight(g, k)
    {
        B = rB;
        A = rA;
        D = rD;
    }
    void Convert(int tw)
    {
        B = tw / 512;
        tw = tw - B * 512;
        A = tw / 32;
        tw = tw - A * 32;
        D = tw / 2;
        tw = tw - D * 2;
        gram = tw;
    }
    int turn()
    {
        return (B * 512 + A * 32 + D * 2 + gram);
    }
    void Print(ostream& out) {
        cout << "英国计重:" << B << "磅" << A << "盎司" << D << "打兰" << gram << "克" << endl;
    }
};
ostream& operator <<(ostream& oo, EN& ra) {
    ra.Print(oo);
    return oo;
}
class CN : public Weight { //中国计重
protected:
    int j;
    int l;
    int q;
public:
    CN(int rj, int rl, int rq, int g, const char k[]) :Weight(g, k)
    {
        j = rj;
        l = rl;
        q = rq;
    }
    void Convert(int tw)
    {
        j = tw / 500;
        tw = tw - j * 500;
        l = tw / 50;
        tw = tw - l * 50;
        q = tw / 5;
        tw = tw - q * 5;
        gram = tw;
    }
    CN operator =(EN& ra) {
        int G;
        G = ra.turn();
        Convert(G);
        return *this;
    }
    void Print(ostream& out) {
        cout << "中国计重:" << j << "斤" << l << "两" << q << "钱" << gram << "克" << endl;
    }
};
ostream& operator <<(ostream& oo, CN& ra) {
    ra.Print(oo);
    return oo;
}

//以全局函数方式重载输出运算符，代码3-5行....自行编写
//重载函数包含两个参数：ostream流对象、Weight类对象，参数可以是对象或对象引用
//重载函数必须调用参数Weight对象的Print方法
int main()//主函数
{
    int tw;
    //创建一个中国计重类对象cn
    //构造参数对应斤、两、钱、克、类型，其中克和类型是对应基类属性gram和kind
    CN cn(0, 0, 0, 0, "中国计重");
    cin >> tw;
    cn.Convert(tw); //把输入的克数转成中国计重
    cout << cn;

    //创建英国计重类对象en
    //构造参数对应磅、盎司、打兰、克、类型，其中克和类型是对应基类属性gram和kind
    EN en(0, 0, 0, 0, "英国计重");
    cin >> tw;
    en.Convert(tw); //把输入的克数转成英国计重
    cout << en;
    cn = en; //把英国计重转成中国计重
    cout << cn;
    return 0;
}