#pragma once
#include <vector>

using namespace std;

struct Image{
    struct Pixel{
        vector<unsigned char> RGB;
        Pixel(){
            RGB.resize(3, 0);
        }
    };

    char idLength = 0;
    char colorMapType = 0;
    char dataTypeCode = 2;
    short colorMapOrigin = 0;
    short colorMapLength = 0;
    char colorMapDepth = 0;
    short xOrigin = 0;
    short yOrigin = 0;
    short width = 0;
    short height = 0;
    char bitsPerPixel = 24;
    char imageDescriptor = 0;

    vector<Pixel> imagePixels;
    vector<char> f;

    Image();
    ~Image();
    Image &operator=(const Image &d);
    Image(const Image &d);

    void CalcPixels();

    void Initialize(Image &object);
};


void Image::CalcPixels(){

    unsigned int numPixels = width * height;
    while(numPixels != 0)
    {
        Pixel pimi;
        imagePixels.push_back(pimi);
        numPixels--;
    }

} //sets pixels vector to number of pixels in the image
Image & Image::operator=(const Image &d) {
    idLength = d.idLength;
    colorMapType = d.colorMapType;
    dataTypeCode = d.dataTypeCode;
    colorMapOrigin = d.colorMapOrigin;
    colorMapLength = d.colorMapLength;
    colorMapDepth = d.colorMapDepth;
    xOrigin = d.xOrigin;
    yOrigin = d.yOrigin;
    width = d.width;
    height = d.height;
    bitsPerPixel = d.bitsPerPixel;
    imageDescriptor = d.imageDescriptor;
    imagePixels.resize(0);
    f.resize(0);
    for(int i = 0; i < d.imagePixels.size(); i++)
        imagePixels.push_back(d.imagePixels[i]);
    for(int i = 0; i < d.f.size(); i++)
        f.push_back(d.f[i]);

    return *this;
}

Image::Image(){
    idLength = 0;
    colorMapType = 0;
    dataTypeCode = 2;
    colorMapOrigin = 0;
    colorMapLength = 0;
    colorMapDepth = 0;
    xOrigin = 0;
    yOrigin = 0;
    width = 0;
    height = 0;
    bitsPerPixel = 24;
    imageDescriptor = 0;
    imagePixels.resize(0);
    f.resize(0);
}

Image::Image(const Image &d){
    idLength = d.idLength;
    colorMapType = d.colorMapType;
    dataTypeCode = d.dataTypeCode;
    colorMapOrigin = d.colorMapOrigin;
    colorMapLength = d.colorMapLength;
    colorMapDepth = d.colorMapDepth;
    xOrigin = d.xOrigin;
    yOrigin = d.yOrigin;
    width = d.width;
    height = d.height;
    bitsPerPixel = d.bitsPerPixel;
    imageDescriptor = d.imageDescriptor;
    imagePixels.resize(0);
    f.resize(0);
    for(int i = 0; i < d.imagePixels.size(); i++)
        imagePixels.push_back(d.imagePixels[i]);
    for(int i = 0; i < d.f.size(); i++)
        f.push_back(d.f[i]);
}
Image::~Image(){

}

void Image::Initialize(Image &object){
    idLength = object.idLength;
    colorMapType = object.colorMapType;
    dataTypeCode = object.dataTypeCode;
    colorMapOrigin = object.colorMapOrigin;
    colorMapLength = object.colorMapLength;
    colorMapDepth = object.colorMapDepth;
    xOrigin = object.xOrigin;
    yOrigin = object.yOrigin;
    width = object.width;
    height = object.height;
    bitsPerPixel = object.bitsPerPixel;
    imageDescriptor = object.imageDescriptor;

    imagePixels.resize(0);
    f.resize(0);
    this->CalcPixels();
    for(int i = 0; i < object.f.size(); i++)
        f.push_back(object.f[i]);
}