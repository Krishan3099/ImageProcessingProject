#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include "Image.h"

using namespace std;

Image ReadFile(string fileName);
void WriteFile(string outFile, Image imageObject);
void ChannelToFile(string outFile, Image imageObject, int color);
void WriteRotated(string outFile, Image imageObject);

Image MultiplyLayers(Image topLayer, Image bottomLayer);
Image ScreenLayers(Image topLayer, Image bottomLayer);
Image SubtractLayers(Image topLayer, Image bottomLayer);
Image OverlayLayers(Image topLayer, Image bottomLayer);
Image Composite(Image layerR, Image layerG, Image layerB);


Image MultiplyChannel(Image imageObject, int color, int scale);
Image AddChannel(Image imageObject, int color, int add);

bool TestImages(Image testImage, Image givenImage);


int main() {
    string inFile = "";
    string outFile = "";
    string inFile2 = "";
    string inFile3 = "";
    string givenFile = "";
    Image imageA;
    Image imageB;
    Image imageC;

    cout << "Task 1: " << endl;
    inFile = "input\\layer1.tga";
    inFile2 = "input\\pattern1.tga";
    outFile = "output\\part1.tga";
    givenFile = "examples\\EXAMPLE_part1.tga";
    imageA = MultiplyLayers(ReadFile(inFile),  ReadFile(inFile2));
    WriteFile(outFile, imageA);
    if(TestImages(imageA, ReadFile(givenFile)))
        cout << "Gucci" << endl;
    cout << "COMPLETE" << endl << endl;



    cout << "Task 2: " << endl;
    inFile = "input\\layer2.tga";
    inFile2 = "input\\car.tga";
    outFile = "output\\part2.tga";
    givenFile = "examples\\EXAMPLE_part2.tga";
    imageC = SubtractLayers(ReadFile(inFile), ReadFile(inFile2));
    WriteFile(outFile, imageC);
    if(TestImages(imageC, ReadFile(givenFile)))
        cout << "Gucci" << endl;
    cout << "COMPLETE" << endl << endl;



    cout << "Task 3: " << endl;
    inFile = "input\\layer1.tga";
    inFile2 = "input\\pattern2.tga";
    outFile = "output\\part3.tga";
    givenFile = "examples\\EXAMPLE_part3.tga";
    imageB = MultiplyLayers(ReadFile(inFile), ReadFile(inFile2));
    inFile = "input\\text.tga";
    imageC = ScreenLayers(ReadFile(inFile), imageB);
    WriteFile(outFile, imageC);
    if(TestImages(imageC, ReadFile(givenFile)))
        cout << "Gucci" << endl;
    cout << "COMPLETE" << endl << endl;



    cout << "Task 4: " << endl;
    inFile = "input\\layer2.tga";
    inFile2 = "input\\circles.tga";
    outFile = "output\\part4.tga";
    givenFile = "examples\\EXAMPLE_part4.tga";
    imageB = MultiplyLayers(ReadFile(inFile), ReadFile(inFile2));
    inFile = "input\\pattern2.tga";
    imageC = SubtractLayers(ReadFile(inFile), imageB);
    WriteFile(outFile, imageC);
    if(TestImages(imageC, ReadFile(givenFile)))
        cout << "Gucci" << endl;
    cout << "COMPLETE" << endl << endl;



    cout << "Task 5: " << endl;
    inFile = "input\\layer1.tga";
    inFile2 = "input\\pattern1.tga";
    outFile = "output\\part1.tga";
    givenFile = "examples\\EXAMPLE_part5.tga";
    imageA = OverlayLayers(ReadFile(inFile),  ReadFile(inFile2));
    WriteFile(outFile, imageA);
    if(TestImages(imageA, ReadFile(givenFile)))
        cout << "Gucci" << endl;
    cout << "COMPLETE" << endl << endl;



    cout << "Task 6: " << endl;
    inFile = "input\\car.tga";
    outFile = "output\\part6.tga";
    givenFile = "examples\\EXAMPLE_part6.tga";
    imageB = AddChannel(ReadFile(inFile), 1, 200);
    WriteFile(outFile, imageB);
    if(TestImages(imageB, ReadFile(givenFile)))
        cout << "Gucci" << endl;
    cout << "COMPLETE" << endl << endl;



    cout << "Task 7: " << endl;
    inFile = "input\\car.tga";
    outFile = "output\\part7.tga";
    givenFile = "examples\\EXAMPLE_part7.tga";
    imageC = MultiplyChannel(MultiplyChannel(ReadFile(inFile), 0, 4), 2, 0);
    WriteFile(outFile, imageC);
    if(TestImages(imageC, ReadFile(givenFile)))
        cout << "Gucci" << endl;
    cout << "COMPLETE" << endl << endl;



    cout << "Task 8: " << endl;
    inFile = "input\\car.tga";
    outFile = "output\\part8_r.tga";
    givenFile = "examples\\EXAMPLE_part8_r.tga";
    ChannelToFile(outFile, ReadFile(inFile), 0);
    if(TestImages(ReadFile(outFile), ReadFile(givenFile)))
        cout << "Gucci r" << endl;
    outFile = "output\\part8_g.tga";
    givenFile = "examples\\EXAMPLE_part8_g.tga";
    ChannelToFile(outFile, ReadFile(inFile), 1);
    if(TestImages(ReadFile(outFile), ReadFile(givenFile)))
        cout << "Gucci g" << endl;
    outFile = "output\\part8_b.tga";
    givenFile = "examples\\EXAMPLE_part8_b.tga";
    ChannelToFile(outFile, ReadFile(inFile), 2);
    if(TestImages(ReadFile(outFile), ReadFile(givenFile)))
        cout << "Gucci b" << endl;
    cout << "COMPLETE" << endl << endl;



    cout << "Task 9: " << endl;
    inFile = "input\\layer_red.tga";
    inFile2 = "input\\layer_green.tga";
    inFile3 = "input\\layer_blue.tga";
    outFile = "output\\part9.tga";
    givenFile = "examples\\EXAMPLE_part9.tga";
    WriteFile(outFile, Composite(ReadFile(inFile), ReadFile(inFile2), ReadFile(inFile3)));
    if(TestImages(ReadFile(outFile), ReadFile(givenFile)))
        cout << "Gucci" << endl;
    cout << "COMPLETE" << endl << endl;



    cout << "Task 10: " << endl;
    inFile = "input\\text2.tga";
    outFile = "output\\part10.tga";
    WriteRotated(outFile, ReadFile(inFile));
    if(TestImages(ReadFile(outFile), ReadFile(givenFile)))
        cout << "Gucci" << endl;
    cout << "COMPLETE" << endl << endl;

    return 0;
}

Image ReadFile(string fileName) {
    Image imageObject;
    ifstream file(fileName, ios_base::in | ios_base::binary);
    if(!file.is_open()){
        cout << "nope" << endl;
    }
    file.read(&imageObject.idLength, sizeof(imageObject.idLength));
    file.read(&imageObject.colorMapType, sizeof(imageObject.colorMapType));
    file.read(&imageObject.dataTypeCode, sizeof(imageObject.dataTypeCode));
    file.read((char *)&imageObject.colorMapOrigin, sizeof(imageObject.colorMapOrigin));
    file.read((char *)&imageObject.colorMapLength, sizeof(imageObject.colorMapLength));
    file.read(&imageObject.colorMapDepth, sizeof(imageObject.colorMapDepth));
    file.read((char *)&imageObject.xOrigin, sizeof(imageObject.xOrigin));
    file.read((char *)&imageObject.yOrigin, sizeof(imageObject.yOrigin));
    file.read((char *)&imageObject.width, sizeof(imageObject.width));
    file.read((char *)&imageObject.height, sizeof(imageObject.height));
    file.read(&imageObject.bitsPerPixel, sizeof(imageObject.bitsPerPixel));
    file.read(&imageObject.imageDescriptor, sizeof(imageObject.imageDescriptor));

    imageObject.CalcPixels();

    for (int i = 0; i < imageObject.imagePixels.size(); i++) {
        file.read((char *) &imageObject.imagePixels[i].RGB[2], sizeof(imageObject.imagePixels[i].RGB[2]));
        file.read((char *) &imageObject.imagePixels[i].RGB[1], sizeof(imageObject.imagePixels[i].RGB[1]));
        file.read((char *) &imageObject.imagePixels[i].RGB[0], sizeof(imageObject.imagePixels[i].RGB[0]));
    }

    while(!file.eof()){
        char i = 0;
        file.read(&i, sizeof(i));
        imageObject.f.push_back(i);
    }
    file.close();
    return imageObject;
}

void WriteFile(string outFile,Image imageObject){
    ofstream ofile(outFile, ios_base::binary);
    ofile.write(&imageObject.idLength, sizeof(imageObject.idLength));
    ofile.write(&imageObject.colorMapType, sizeof(imageObject.colorMapType));
    ofile.write(&imageObject.dataTypeCode, sizeof(imageObject.dataTypeCode));
    ofile.write((char *)&imageObject.colorMapOrigin, sizeof(imageObject.colorMapOrigin));
    ofile.write((char *)&imageObject.colorMapLength, sizeof(imageObject.colorMapLength));
    ofile.write(&imageObject.colorMapDepth, sizeof(imageObject.colorMapDepth));
    ofile.write((char *)&imageObject.xOrigin, sizeof(imageObject.xOrigin));
    ofile.write((char *)&imageObject.yOrigin, sizeof(imageObject.yOrigin));
    ofile.write((char *)&imageObject.width, sizeof(imageObject.width));
    ofile.write((char *)&imageObject.height, sizeof(imageObject.height));
    ofile.write(&imageObject.bitsPerPixel, sizeof(imageObject.bitsPerPixel));
    ofile.write(&imageObject.imageDescriptor, sizeof(imageObject.imageDescriptor));
    for (int i = 0; i < imageObject.imagePixels.size(); i++) {
        ofile.write((char *) &imageObject.imagePixels[i].RGB[2], sizeof(imageObject.imagePixels[i].RGB[2]));
        ofile.write((char *) &imageObject.imagePixels[i].RGB[1], sizeof(imageObject.imagePixels[i].RGB[1]));
        ofile.write((char *) &imageObject.imagePixels[i].RGB[0], sizeof(imageObject.imagePixels[i].RGB[0]));
    }
    for (int j = 0; j < imageObject.f.size(); j++){
        ofile.write(&imageObject.f[j], sizeof(imageObject.f[j]));
    }
    ofile.close();
}

Image MultiplyLayers(Image topLayer, Image bottomLayer){
    Image outputImage;
    float pixelA = 0;
    float pixelB = 0;
    float pixelC = 0;

    outputImage.Initialize(topLayer);
    for(int i = 0; i < outputImage.imagePixels.size(); i++){
        for(int f = 2; f >= 0; f--) {
            pixelA = topLayer.imagePixels[i].RGB[f];
            pixelB = bottomLayer.imagePixels[i].RGB[f];
            pixelC = (pixelA * pixelB)/255;
            if (pixelC > 255) {
                outputImage.imagePixels[i].RGB[f] = 255;
            }else if(pixelC < 0){
                outputImage.imagePixels[i].RGB[f] = 0;
            }else {
                outputImage.imagePixels[i].RGB[f] = (unsigned char)(pixelC + 0.5f);
            }
        }
    }

    return outputImage;
}

Image SubtractLayers(Image topLayer, Image bottomLayer){                //bottom - top
    Image outputImage;
    int pixelA = 0;
    int pixelB = 0;
    int pixelC = 0;

    outputImage.Initialize(topLayer);
    for(int i = 0; i < topLayer.imagePixels.size(); i++){
        for(int f = 2; f >= 0; f--) {
            pixelA = topLayer.imagePixels[i].RGB[f];
            pixelB = bottomLayer.imagePixels[i].RGB[f];
            pixelC = pixelB - pixelA;
            if (pixelC < 0) {
                outputImage.imagePixels[i].RGB[f] = 0;
            } else {
                outputImage.imagePixels[i].RGB[f] = (unsigned char)pixelC;
            }
        }
    }

    return outputImage;
}

Image ScreenLayers(Image topLayer, Image bottomLayer){
    Image outputImage;

    outputImage.Initialize(topLayer);

    float pixelA = 0;
    float pixelB = 0;
    float pixelC = 0;

    for(int i = 0; i < topLayer.imagePixels.size(); i++){
        for(int f = 2; f >= 0; f--) {
            pixelA = topLayer.imagePixels[i].RGB[f];
            pixelB = bottomLayer.imagePixels[i].RGB[f];
            pixelC = (255 - ((255 - pixelA)*(255 - pixelB))/255);
            if (pixelC > 255) {
                outputImage.imagePixels[i].RGB[f] = 255;
            }else if(pixelC < 0){
                outputImage.imagePixels[i].RGB[f] = 0;
            }else {
                outputImage.imagePixels[i].RGB[f] = (unsigned char)(pixelC + 0.5f);
            }
        }
    }

    return outputImage;
}

Image OverlayLayers(Image topLayer, Image bottomLayer){
    Image outputImage;

    outputImage.Initialize(topLayer);

    float pixelA = 0;
    float pixelB = 0;
    float pixelC = 0;

    for(int i = 0; i < topLayer.imagePixels.size(); i++){
        for(int f = 2; f >= 0; f--) {
            pixelA = topLayer.imagePixels[i].RGB[f];
            pixelB = bottomLayer.imagePixels[i].RGB[f];
            if(pixelB <= 127.5){
                pixelC = 2 * (pixelA * pixelB)/255;
            }else if (pixelB > 127.5){
                pixelC = 255 - (2 * ((255 - pixelA) * (255 - pixelB))/255);
            }

            if (pixelC > 255) {
                outputImage.imagePixels[i].RGB[f] = 255;
            }else if(pixelC < 0){
                outputImage.imagePixels[i].RGB[f] = 0;
            }else {
                outputImage.imagePixels[i].RGB[f] = (unsigned char)(pixelC + 0.5f);
            }
        }
    }

    return outputImage;
}

Image MultiplyChannel(Image imageObject, int color, int scale){
    Image outputImage;
    int pixel = 0;

    outputImage.Initialize(imageObject);
    for(int i = 0; i < imageObject.imagePixels.size(); i++){

        pixel = imageObject.imagePixels[i].RGB[color] * scale;

        if (pixel < 0) {
            outputImage.imagePixels[i].RGB[color] = 0;
        }else if(pixel > 255){
            outputImage.imagePixels[i].RGB[color] = 255;
        }else{
            outputImage.imagePixels[i].RGB[color] = (unsigned char)pixel;
        }
        if(color == 0){
            outputImage.imagePixels[i].RGB[1] = imageObject.imagePixels[i].RGB[1];
            outputImage.imagePixels[i].RGB[2] = imageObject.imagePixels[i].RGB[2];
        }else if(color == 1){
            outputImage.imagePixels[i].RGB[0] = imageObject.imagePixels[i].RGB[0];
            outputImage.imagePixels[i].RGB[2] = imageObject.imagePixels[i].RGB[2];
        }else{
            outputImage.imagePixels[i].RGB[0] = imageObject.imagePixels[i].RGB[0];
            outputImage.imagePixels[i].RGB[1] = imageObject.imagePixels[i].RGB[1];
        }
    }

    return outputImage;
}

Image AddChannel(Image imageObject, int color, int add){
    Image outputImage;
    int pixel = 0;

    outputImage.Initialize(imageObject);
    for(int i = 0; i < imageObject.imagePixels.size(); i++){

        pixel = imageObject.imagePixels[i].RGB[color] + add;

        if (pixel < 0) {
            outputImage.imagePixels[i].RGB[color] = 0;
        }else if(pixel > 255){
            outputImage.imagePixels[i].RGB[color] = 255;
        }else{
            outputImage.imagePixels[i].RGB[color] = (unsigned char)pixel;
        }
        if(color == 0){
            outputImage.imagePixels[i].RGB[1] = imageObject.imagePixels[i].RGB[1];
            outputImage.imagePixels[i].RGB[2] = imageObject.imagePixels[i].RGB[2];
        }else if(color == 1){
            outputImage.imagePixels[i].RGB[0] = imageObject.imagePixels[i].RGB[0];
            outputImage.imagePixels[i].RGB[2] = imageObject.imagePixels[i].RGB[2];
        }else{
            outputImage.imagePixels[i].RGB[0] = imageObject.imagePixels[i].RGB[0];
            outputImage.imagePixels[i].RGB[1] = imageObject.imagePixels[i].RGB[1];
        }
    }

    return outputImage;
}

void ChannelToFile(string outFile, Image imageObject, int color){

    ofstream ofile(outFile, ios_base::binary);
    ofile.write(&imageObject.idLength, sizeof(imageObject.idLength));
    ofile.write(&imageObject.colorMapType, sizeof(imageObject.colorMapType));
    ofile.write(&imageObject.dataTypeCode, sizeof(imageObject.dataTypeCode));
    ofile.write((char *)&imageObject.colorMapOrigin, sizeof(imageObject.colorMapOrigin));
    ofile.write((char *)&imageObject.colorMapLength, sizeof(imageObject.colorMapLength));
    ofile.write(&imageObject.colorMapDepth, sizeof(imageObject.colorMapDepth));
    ofile.write((char *)&imageObject.xOrigin, sizeof(imageObject.xOrigin));
    ofile.write((char *)&imageObject.yOrigin, sizeof(imageObject.yOrigin));
    ofile.write((char *)&imageObject.width, sizeof(imageObject.width));
    ofile.write((char *)&imageObject.height, sizeof(imageObject.height));
    ofile.write(&imageObject.bitsPerPixel, sizeof(imageObject.bitsPerPixel));
    ofile.write(&imageObject.imageDescriptor, sizeof(imageObject.imageDescriptor));
    if(color == 0){
        for (int i = 0; i < imageObject.imagePixels.size(); i++) {
            ofile.write((char *) &imageObject.imagePixels[i].RGB[0], sizeof(imageObject.imagePixels[i].RGB[0]));
            ofile.write((char *) &imageObject.imagePixels[i].RGB[0], sizeof(imageObject.imagePixels[i].RGB[0]));
            ofile.write((char *) &imageObject.imagePixels[i].RGB[0], sizeof(imageObject.imagePixels[i].RGB[0]));
        }
    }else if(color == 1){
        for (int i = 0; i < imageObject.imagePixels.size(); i++) {
            ofile.write((char *) &imageObject.imagePixels[i].RGB[1], sizeof(imageObject.imagePixels[i].RGB[1]));
            ofile.write((char *) &imageObject.imagePixels[i].RGB[1], sizeof(imageObject.imagePixels[i].RGB[1]));
            ofile.write((char *) &imageObject.imagePixels[i].RGB[1], sizeof(imageObject.imagePixels[i].RGB[1]));
        }
    }else{
        for (int i = 0; i < imageObject.imagePixels.size(); i++) {
            ofile.write((char *) &imageObject.imagePixels[i].RGB[2], sizeof(imageObject.imagePixels[i].RGB[2]));
            ofile.write((char *) &imageObject.imagePixels[i].RGB[2], sizeof(imageObject.imagePixels[i].RGB[2]));
            ofile.write((char *) &imageObject.imagePixels[i].RGB[2], sizeof(imageObject.imagePixels[i].RGB[2]));
        }
    }
    ofile.close();
}

Image Composite(Image layerR, Image layerG, Image layerB){
    Image outputImage;

    outputImage.Initialize(layerR);

    for(int i = 0; i < outputImage.imagePixels.size(); i++){
        outputImage.imagePixels[i].RGB[0] = layerR.imagePixels[i].RGB[0];
        outputImage.imagePixels[i].RGB[1] = layerG.imagePixels[i].RGB[1];
        outputImage.imagePixels[i].RGB[2] = layerB.imagePixels[i].RGB[2];
    }

    return outputImage;
}

void WriteRotated(string outFile, Image imageObject){
    ofstream ofile(outFile, ios_base::binary);
    ofile.write(&imageObject.idLength, sizeof(imageObject.idLength));
    ofile.write(&imageObject.colorMapType, sizeof(imageObject.colorMapType));
    ofile.write(&imageObject.dataTypeCode, sizeof(imageObject.dataTypeCode));
    ofile.write((char *)&imageObject.colorMapOrigin, sizeof(imageObject.colorMapOrigin));
    ofile.write((char *)&imageObject.colorMapLength, sizeof(imageObject.colorMapLength));
    ofile.write(&imageObject.colorMapDepth, sizeof(imageObject.colorMapDepth));
    ofile.write((char *)&imageObject.xOrigin, sizeof(imageObject.xOrigin));
    ofile.write((char *)&imageObject.yOrigin, sizeof(imageObject.yOrigin));
    ofile.write((char *)&imageObject.width, sizeof(imageObject.width));
    ofile.write((char *)&imageObject.height, sizeof(imageObject.height));
    ofile.write(&imageObject.bitsPerPixel, sizeof(imageObject.bitsPerPixel));
    ofile.write(&imageObject.imageDescriptor, sizeof(imageObject.imageDescriptor));
    for (int i = (imageObject.imagePixels.size() - 1); i >= 0; i--) {
        ofile.write((char *) &imageObject.imagePixels[i].RGB[0], sizeof(imageObject.imagePixels[i].RGB[0]));
        ofile.write((char *) &imageObject.imagePixels[i].RGB[1], sizeof(imageObject.imagePixels[i].RGB[1]));
        ofile.write((char *) &imageObject.imagePixels[i].RGB[2], sizeof(imageObject.imagePixels[i].RGB[2]));
    }
    ofile.write(&imageObject.f[0], sizeof(imageObject.f[0]));
    ofile.close();
}

bool TestImages(Image testImage, Image givenImage){
    if(testImage.idLength != givenImage.idLength){
        cout << "wrong idLength"  << endl;
        return false;
    }else if(testImage.colorMapType != givenImage.colorMapType){
        cout << "wrong colorMapType"  << endl;
        return false;
    }else if(testImage.dataTypeCode != givenImage.dataTypeCode){
        cout << "wrong dataTypeCode"  << endl;
        return false;
    }else if(testImage.colorMapOrigin != givenImage.colorMapOrigin){
        cout << "wrong colorMapOrigin"  << endl;
        return false;
    }else if(testImage.colorMapLength != givenImage.colorMapLength){
        cout << "wrong colorMapLength"  << endl;
        return false;
    }else if(testImage.colorMapDepth != givenImage.colorMapDepth){
        cout << "wrong colorMapDepth"  << endl;
        return false;
    }else if(testImage.xOrigin != givenImage.xOrigin){
        cout << "wrong xOrigin"  << endl;
        return false;
    }else if(testImage.yOrigin != givenImage.yOrigin){
        cout << "wrong yOrigin"  << endl;
        return false;
    }else if(testImage.width != givenImage.width){
        cout << "wrong width apparently"  << endl;
        return false;
    }else if(testImage.height != givenImage.height){
        cout << "wrong height"  << endl;
        return false;
    }else if(testImage.bitsPerPixel != givenImage.bitsPerPixel){
        cout << "wrong bitsPerPixel"  << endl;
        return false;
    }else if(testImage.imageDescriptor != givenImage.imageDescriptor){
        cout << "wrong imageDescriptor"  << endl;
        return false;
    }else if(testImage.imagePixels.size() != givenImage.imagePixels.size()){
        cout << "wrong imagePixels size"  << endl;
        return false;
    }
    for(int i = 0; i < testImage.imagePixels.size(); i++){
        for(int f = 2; f >= 0; f--) {
            if (testImage.imagePixels[i].RGB[f] != givenImage.imagePixels[i].RGB[f]) {
                cout << "PIXELS DON'T MATCH NOOOOOOOO"  << endl;
                return false;
            }
        }
    }
    return true;
}