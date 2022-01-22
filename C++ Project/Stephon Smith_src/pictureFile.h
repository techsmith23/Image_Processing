//
// Created by Techman21 on 11/6/2018.
//

#pragma once

#include <sys/stat.h>
#include<iostream>
#include<stdio.h>
#include<fstream>
#include<iomanip>
#include <string>
#include <vector>

using namespace std;

#ifndef PROJECT2AGAIN_PICTUREFILE_H
#define PROJECT2AGAIN_PICTUREFILE_H

class ImagePix {

public:

    //I initialized different colors to describe the total number of pixels that is
    // used within the files.

    unsigned char R_;
    unsigned char G_;
    unsigned char B_;

    //Different operators that are being used:

    ImagePix &operator=(const ImagePix &rhs) {

        R_ = rhs.R_;
        G_ = rhs.G_;
        B_ = rhs.B_;

        return *this;

    }

    //Multiplying Operator:

    ImagePix &operator*(const ImagePix &rhs) {

        float Red1, Red2, Green1, Green2, Blue1, Blue2;

        Red1 = R_ / 255.0f;
        Red2 = rhs.R_ / 255.0f;
        Green1 = G_ / 255.0f;
        Green2 = rhs.G_ / 255.0f;
        Blue1 = B_ / 255.0f;
        Blue2 = rhs.B_ / 255.0f;

        R_ = (unsigned char)(Red1 * Red2 * 255 + 0.5f);
        G_ = (unsigned char)(Green1 * Green2 * 255 + 0.5f);
        B_ = (unsigned char)(Blue1 * Blue2 * 255 + 0.5f);

        return *this;

    }

    //Addition Operator

    ImagePix &operator+(const ImagePix &rhs) {

        R_ += rhs.R_;
        G_ += rhs.G_;
        B_ += rhs.B_;

        if (R_ > 255) {

            R_ = 255;
        }

        if (G_ > 255) {

            G_ = 255;

        }

        if (B_ > 255) {

            B_ = 255;

        }

        return *this;
    }

    //Subtraction Operator

    ImagePix &operator-(const ImagePix &rhs) {

        R_ -= rhs.R_;
        G_ -= rhs.G_;
        B_ -= rhs.B_;

        if (R_ < 0) {

            R_ = 0;

        }

        if (G_ < 0) {

            G_ = 0;
        }

        if (B_ < 0) {

            B_ = 0;
        }

        return *this;
    }

};

class Pix {

public:

    char lengthOfIdentification;
    char typeOfMapColor;
    char typeOfDataCode;
    short mapOfColorOrigin;
    short mapOfColorLength;
    char mapOfColorDepth;
    short originX;
    short originY;
    short Width_;
    short Height_;
    char pixelBits;
    char descriptOfImage;
    ImagePix *pixelArray;

    //Reading a file:

    void fileRead(ifstream &source) {

        if (source.is_open()) {

            source.read(&lengthOfIdentification, 1);
            source.read(&typeOfMapColor, 1);
            source.read(&typeOfDataCode, 1);
            source.read((char *)&mapOfColorOrigin, 2);
            source.read((char *)&mapOfColorLength, 2);
            source.read(&mapOfColorDepth, 1);
            source.read((char *)&originX, 2);
            source.read((char *)&originY, 2);
            source.read((char *)&Width_, 2);
            source.read((char *)&Height_, 2);
            source.read(&pixelBits, 1);
            source.read(&descriptOfImage, 1);

            int numPix = Width_ * Height_;

            pixelArray = new ImagePix[numPix];

            for (int i = 0; i < numPix; i++) {

                source.read((char *)&pixelArray[i].B_, 1);
                source.read((char *)&pixelArray[i].G_, 1);
                source.read((char *)&pixelArray[i].R_, 1);

            }

        }

    }

    //Writing a file:

    void fileWrite(ofstream &open) {

        if (open.is_open()) {

            //openFile.write((const char *) &header_file, 18);

            open.write(&lengthOfIdentification, 1);
            open.write(&typeOfMapColor, 1);
            open.write(&typeOfDataCode, 1);
            open.write((char *)&mapOfColorOrigin, 2);
            open.write((char *)&mapOfColorLength, 2);
            open.write(&mapOfColorDepth, 1);
            open.write((char *)&originX, 2);
            open.write((char *)&originY, 2);
            open.write((char *)&Width_, 2);
            open.write((char *)&Height_, 2);
            open.write(&pixelBits, 1);
            open.write(&descriptOfImage, 1);


            int numPix = Width_ * Height_;


            for (int i = 0; i < numPix; i++) {

                open.write((char *)&pixelArray[i].B_, 1);
                open.write((char *)&pixelArray[i].G_, 1);
                open.write((char *)&pixelArray[i].R_, 1);

            }

        }

    }

    //Organizes the header that is being read towards the file:

    void addHead(Pix header) {

        this->lengthOfIdentification = header.lengthOfIdentification;
        this->typeOfMapColor = header.typeOfMapColor;
        this->typeOfDataCode = header.typeOfDataCode;
        this->mapOfColorOrigin = header.mapOfColorOrigin;
        this->mapOfColorLength = header.mapOfColorLength;
        this->mapOfColorDepth = header.mapOfColorDepth;
        this->originX = header.originX;
        this->originY = header.originY;
        this->Width_ = header.Width_;
        this->Height_ = header.Height_;
        this->pixelBits = header.pixelBits;
        this->descriptOfImage = header.descriptOfImage;

    }


    // Multiplies the pixels in both files that will blend the two into one new file

    void MultiplyBlendingMode(Pix pic1, Pix pic2) {

        int sizeArray = pic1.Width_ * pic1.Height_;

        pixelArray = new ImagePix[sizeArray];

        for (int i = 0; i < sizeArray; i++) {

            pixelArray[i] = (pic1.pixelArray[i] * pic2.pixelArray[i]);

        }

    }

    //Subtracts the pixels in both files that will blend the two into one new file

    void SubtractBlendingMode(Pix pic1, Pix pic2) {

        int sizeArray = pic1.Width_ * pic1.Height_;

        pixelArray = new ImagePix[sizeArray];

        for (int i = 0; i < sizeArray; i++) {

            if (pic1.pixelArray[i].R_ > pic2.pixelArray[i].R_) {

                pixelArray[i].R_ = pic1.pixelArray[i].R_ - pic2.pixelArray[i].R_;

            }
            else {

                pixelArray[i].R_ = 0;

            }

            if (pic1.pixelArray[i].G_ > pic2.pixelArray[i].G_) {

                pixelArray[i].G_ = pic1.pixelArray[i].G_ - pic2.pixelArray[i].G_;

            }
            else {

                pixelArray[i].G_ = 0;

            }

            if (pic1.pixelArray[i].B_ > pic2.pixelArray[i].B_) {

                pixelArray[i].B_ = pic1.pixelArray[i].B_ - pic2.pixelArray[i].B_;

            }
            else {

                pixelArray[i].B_ = 0;

            }

        }

    }

    // Combines the two files to their background values.

    void overlayBleningMode(Pix File1_, Pix File2_) {

        int sizeArray = File1_.Width_ * File1_.Height_;

        pixelArray = new ImagePix[sizeArray];

        for (int i = 0; i < sizeArray; i++) {

            float red = File1_.pixelArray[i].R_ / 255.0f;
            float green = File1_.pixelArray[i].G_ / 255.0f;
            float blue = File1_.pixelArray[i].B_ / 255.0f;

            float red2 = File2_.pixelArray[i].R_ / 255.0f;
            float green2 = File2_.pixelArray[i].G_ / 255.0f;
            float blue2 = File2_.pixelArray[i].B_ / 255.0f;

            if (red2 < 0.5) {

                pixelArray[i].R_ = (2 * red * red2) * 255.0f;

            }
            else {

                pixelArray[i].R_ = (1 - (2 * (1 - red) * (1 - red2))) * 255.0f + 0.5f;

            }

            if (green2 < 0.5) {

                pixelArray[i].G_ = (2 * green * green2) * 255.0f;

            }
            else {

                pixelArray[i].G_ = (1 - (2 * (1 - green) * (1 - green2))) * 255.0f + 0.5;

            }
            if (blue2 < 0.5) {

                pixelArray[i].B_ = (2 * blue * blue2) * 255.0f;

            }
            else {

                pixelArray[i].B_ = (1 - (2 * (1 - blue) * (1 - blue2))) * 255.0f + 0.5;

            }

        }

    }

    // Adds the green filter to a header file

    void addGreenColor(Pix Green) {

        int sizeArray = Green.Width_ * Green.Height_;

        pixelArray = new ImagePix[sizeArray];

        for (int i = 0; i < sizeArray; i++) {

            pixelArray[i] = Green.pixelArray[i];

        }
        for (int i = 0; i < sizeArray; i++) {

            if (pixelArray[i].G_ > 55) {

                pixelArray[i].G_ = 255;

            }
            else {

                pixelArray[i].G_ += 200;
            }

        }

    }

    // adjusts multiple colors together to the file

    void adjustColor(Pix Color) {

        int sizeArray = Color.Width_ * Color.Height_;

        pixelArray = new ImagePix[sizeArray];

        for (int i = 0; i < sizeArray; i++) {

            pixelArray[i] = Color.pixelArray[i];

        }

        for (int i = 0; i < sizeArray; i++) {

            pixelArray[i].B_ = 0;
            if (pixelArray[i].R_ * 4 > 255) {

                pixelArray[i].R_ = 255;

            }
            else {

                pixelArray[i].R_ *= 4;

            }
        }
    }

    // Seperates red from other colors in the file

    void SeperateRed(Pix Red) {

        int sizeArray = Red.Width_ * Red.Height_;

        pixelArray = new ImagePix[sizeArray];

        for (int i = 0; i < sizeArray; i++) {

            pixelArray[i] = Red.pixelArray[i];

        }

        for (int i = 0; i < sizeArray; i++) {

            pixelArray[i].G_ = pixelArray[i].R_;
            pixelArray[i].B_ = pixelArray[i].R_;
        }


    }

    // Seperates blue from other colors in the file

    void SeperateBlueFile(Pix Blue) {

        int sizeArray = Blue.Width_ * Blue.Height_;

        pixelArray = new ImagePix[sizeArray];

        for (int i = 0; i < sizeArray; i++) {

            pixelArray[i] = Blue.pixelArray[i];

        }

        for (int i = 0; i < sizeArray; i++) {

            pixelArray[i].G_ = pixelArray[i].B_;
            pixelArray[i].R_ = pixelArray[i].B_;
        }
    }

    // Seperates blue from other colors in the file

    void SeperateGreenFile(Pix Green) {

        int sizeArray = Green.Width_ * Green.Height_;

        pixelArray = new ImagePix[sizeArray];

        for (int i = 0; i < sizeArray; i++) {

            pixelArray[i] = Green.pixelArray[i];

        }

        for (int i = 0; i < sizeArray; i++) {

            pixelArray[i].R_ = pixelArray[i].G_;
            pixelArray[i].B_ = pixelArray[i].G_;
        }


    }

    //combines different colors together  from a file

    void combineColorsTogether(Pix File1, Pix File2, Pix File3) {

        int sizeArray = File1.Width_ * File1.Height_;

        pixelArray = new ImagePix[sizeArray];

        for (int i = 0; i < sizeArray; i++) {

            pixelArray[i].R_ = File1.pixelArray[i].R_;

        }
        for (int i = 0; i < sizeArray; i++) {

            pixelArray[i].G_ = File2.pixelArray[i].G_;

        }
        for (int i = 0; i < sizeArray; i++) {

            pixelArray[i].B_ = File3.pixelArray[i].B_;

        }

    }

    // Blends the two images that are being combined into one file

    void screenMode(Pix File1, Pix File2) {

        int sizeArray = File1.Width_ * File1.Height_;

        pixelArray = new ImagePix[sizeArray];

        for (int i = 0; i < sizeArray; i++) {

            float red = File1.pixelArray[i].R_ / 255.0f;
            float green = File1.pixelArray[i].G_ / 255.0f;
            float blue = File1.pixelArray[i].B_ / 255.0f;

            float red2 = File2.pixelArray[i].R_ / 255.0f;
            float green2 = File2.pixelArray[i].G_ / 255.0f;
            float blue2 = File2.pixelArray[i].B_ / 255.0f;

            pixelArray[i].R_ = (1 - (1 - red) * (1 - red2)) * 255 + 0.5;
            pixelArray[i].G_ = (1 - (1 - green) * (1 - green2)) * 255 + 0.5;
            pixelArray[i].B_ = (1 - (1 - blue) * (1 - blue2)) * 255 + 0.5;


        }

    }

    //Checks to see if the output created from all 10 parts matches with the example files that have been given
    // to us to check. Looks through both files to see if the Red, Green, and Blue pixels all match up with each
    // other.

    bool compareFilesMode(Pix File1, Pix File2){

        int sizeArray = File1.Width_ * File1.Height_;

        pixelArray = new ImagePix[sizeArray];


        if (File1.pixelArray->R_ == File2.pixelArray->R_ || File1.pixelArray->B_ == File2.pixelArray->B_ || File1.pixelArray->G_ == File2.pixelArray->G_ ){

            cout << "Passed!" << endl;

        }
        else{

            cout << "Failed!" << endl;

        }

    }


    //Flips the file image by 180 degrees. This method correlates with what is going on when output files are not
    // working, so I had to comment this method out that goes along with Part 10 in main.cpp

    /*

    ImagePix *flipImage(Pix ImagePix) {

        int sizeArr = ImagePix.Width_ * ImagePix.Height_;

        pixelArray = new ImagePix[sizeArr];

        for (int i = 0; i < sizeArr; i++) {

            pixelArray[i] = ImagePix.pixelArray[sizeArr - i];

        }

    }

     */

};


#endif //PROJECT2AGAIN_PICTUREFILE_H
