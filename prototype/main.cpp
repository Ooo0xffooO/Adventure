#include <iostream>

using namespace std;

enum imageType{
    LSAT,SPOT
};

class Image{
private:
    static Image* _prototypes[10];
    static int _nextSlot;
public:
    virtual void draw()=0;
    static Image* findAndClone(imageType);
protected:
    virtual Image* clone()=0;
    virtual imageType returnType()=0;
    static void addPrototype(Image *image){
        _prototypes[_nextSlot++] = image;
    }
};
Image* Image::_prototypes[];
int Image::_nextSlot;

Image* Image::findAndClone(imageType type) {
    for(int i = 0; i<_nextSlot;i++){
        if(_prototypes[i]->returnType()==type)
            return _prototypes[i]->clone();
    }
    return nullptr;
}

class LandSatImage: public Image
{
public:
    imageType returnType () override{
        return LSAT;
    }
    void draw() override{
        cout<<"LandSatImage::draw"<<_id<<endl;
    }
    Image *clone() override{
        return new LandSatImage(1);
    }

private:
    static LandSatImage _landSatImage;
    explicit LandSatImage(){addPrototype(this);}    //构造的时候会调用父类的方法
    int _id{};                          //std::vector<int> v1{1, 2, 3};
    static int _count;                  //静态自动初始化为0
protected:
    explicit LandSatImage(int dummy){   //这里是为了防止clone函数中new的时候会调用构造函数,防止再次addPrototype
        _id = _count++;                 //这里为什么要用protected的，是为了和private做一个区分，首先这个构造方法是不想被类外部调用
    }                                   //--其次设置为protected可以只让类的内部和子类访问,如果当前LandSatImage有一个子类，
};                                      //就可以在子类中调用clone函数

LandSatImage LandSatImage::_landSatImage;
int LandSatImage::_count;
