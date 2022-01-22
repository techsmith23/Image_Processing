
#include <sys/stat.h>
#include<iostream>
#include<stdio.h>
#include<fstream>
#include "pictureFile.h"
#include<iomanip>
#include <string>
#include <vector>

using namespace std;

int main() {

    // listing out the set of variables for both ifstream (getting and reading files), in addition to  ofstream (writing and
    //outputting files.

	ifstream streamCar, streamCircle, streamLayer1, streamLayer2, streamBlueLayer, streamGreenLayer, streamRedLayer,
			streamPattern1, streamPattern2, streamText1, streamText2, streamPart2Car, streamPart8Car , examplePart1,
			 examplePart2, examplePart3, examplePart4, examplePart5, examplePart6, examplePart7, examplePart8R, examplePart8G,
			 examplePart8B, examplePart9, part1Check, part2Check, part3Check, part4Check, part5Check, part6Check, part7Check, part9Check,
			 part10Check, part8RCheck, part8GCheck, part8BCheck;

	// Writing to files (ofstream)

	ofstream fileOut, part1, part2, part3, part4, part5, part6, part7, part9, part10
	, part8R, part8G, part8B;

	// List of header files that are being added towards the Pixel Struct

	Pix Car, Circle, Layer1, Layer2, blueLayer, redLayer, greenLayer,
			pattern1Layer, pattern2Layer, textFile1Layer, textFile2Layer, multiplyLayer, subtractLayer, screenLayer, overlayLayer,
			colorLayer, pixTextLayer, checkPart1A, checkPart1B, evaluatePart1, checkPart2A, checkPart2B, evaluatePart2,
			checkPart3A, checkPart3B, evaluatePart3, checkPart4A, checkPart4B, evaluatePart4, checkPart5A, checkPart5B, evaluatePart5,
			checkPart6A, checkPart6B, evaluatePart6, checkPart7A, checkPart7B, evaluatePart7, checkPart8RA, checkPart8RB, evaluatePart8R,
			checkPart8GA, checkPart8GB, evaluatePart8G, checkPart8BA, checkPart8BB, evaluatePart8B, checkPart9A, checkPart9B, evaluatePart9;

	//File Outputs:

	part1.open("output/part1.tga", ios_base::out | ios_base::binary);
	part2.open("output/part2.tga", ios_base::out | ios_base::binary);
	part3.open("output/part3.tga", ios_base::out | ios_base::binary);
	part4.open("output/part4.tga", ios_base::out | ios_base::binary);
	part5.open("output/part5.tga", ios_base::out | ios_base::binary);
	part6.open("output/part6.tga", ios_base::out | ios_base::binary);
	part7.open("output/part7.tga", ios_base::out | ios_base::binary);
	part8R.open("output/part8_r.tga", ios_base::out | ios_base::binary);
	part8B.open("output/part8_b.tga", ios_base::out | ios_base::binary);
	part8G.open("output/part8_g.tga", ios_base::out | ios_base::binary);
	part9.open("output/part9.tga", ios_base::out | ios_base::binary);
	part10.open("output/part10.tga", ios_base::out | ios_base::binary);

	//Example files to check Tests:

	examplePart1.open("examples/EXAMPLE_part1.tga", ios_base::in | ios_base::binary);
    examplePart2.open("examples/EXAMPLE_part2.tga", ios_base::in | ios_base::binary);
    examplePart3.open("examples/EXAMPLE_part3.tga", ios_base::in | ios_base::binary);
    examplePart4.open("examples/EXAMPLE_part4.tga", ios_base::in | ios_base::binary);
    examplePart5.open("examples/EXAMPLE_part5.tga", ios_base::in | ios_base::binary);
    examplePart6.open("examples/EXAMPLE_part6.tga", ios_base::in | ios_base::binary);
    examplePart7.open("examples/EXAMPLE_part7.tga", ios_base::in | ios_base::binary);
    examplePart8B.open("examples/EXAMPLE_part8_b.tga", ios_base::in | ios_base::binary);
    examplePart8G.open("examples/EXAMPLE_part8_g.tga", ios_base::in | ios_base::binary);
    examplePart8R.open("examples/EXAMPLE_part8_r.tga", ios_base::in | ios_base::binary);
    examplePart9.open("examples/EXAMPLE_part9.tga", ios_base::in | ios_base::binary);

    //fstream files that check output files that have been made:

	part1Check.open("output/part1.tga", ios_base::out | ios_base::binary);
	part2Check.open("output/part2.tga", ios_base::out | ios_base::binary);
	part3Check.open("output/part3.tga", ios_base::out | ios_base::binary);
	part4Check.open("output/part4.tga", ios_base::out | ios_base::binary);
	part5Check.open("output/part5.tga", ios_base::out | ios_base::binary);
	part6Check.open("output/part6.tga", ios_base::out | ios_base::binary);
	part7Check.open("output/part7.tga", ios_base::out | ios_base::binary);
	part8RCheck.open("output/part8_r.tga", ios_base::out | ios_base::binary);
	part8BCheck.open("output/part8_b.tga", ios_base::out | ios_base::binary);
	part8GCheck.open("output/part8_g.tga", ios_base::out | ios_base::binary);
	part9Check.open("output/part9.tga", ios_base::out | ios_base::binary);
	part10Check.open("output/part10.tga", ios_base::out | ios_base::binary);

	int checkPoints = 0;
	int sum = 0;

	//Part 1:

	streamLayer1.open("input/layer1.tga", ios_base::in | ios_base::binary);
	streamPattern1.open("input/pattern1.tga", ios_base::in | ios_base::binary);

	Layer1.fileRead(streamLayer1);
	pattern1Layer.fileRead(streamPattern1);

	multiplyLayer.addHead(Layer1);
	multiplyLayer.MultiplyBlendingMode(Layer1, pattern1Layer);
	multiplyLayer.fileWrite(part1);

	streamLayer1.close();
	streamPattern1.close();

	//Checking Part 1 Test

	cout <<"TestingPart1:" << endl;
	checkPart1A.fileRead(examplePart1);
	checkPart1B.fileRead(part1Check);
	evaluatePart1.compareFilesMode(checkPart1A, checkPart1B);

	if (evaluatePart1.compareFilesMode(checkPart1A, checkPart1B) == true ){

	    checkPoints = 11;
		sum += checkPoints;

	}

	//Part 2:

	streamLayer2.open("input/layer2.tga", ios_base::in | ios_base::binary);
	streamPart2Car.open("input/car.tga", ios_base::in | ios_base::binary);

	Layer2.fileRead(streamLayer2);
	Car.fileRead(streamPart2Car);

	subtractLayer.addHead(Layer2);
	subtractLayer.SubtractBlendingMode(Car, Layer2);
	subtractLayer.fileWrite(part2);

	streamLayer2.close();
	streamPart2Car.close();

	//Checking Part 2 Test:

	cout << "TestingPart2:"<< endl;
    checkPart2A.fileRead(examplePart2);
    checkPart2B.fileRead(part2Check);
    evaluatePart2.compareFilesMode(checkPart2A,checkPart2B);

	if ( evaluatePart2.compareFilesMode(checkPart2A,checkPart2B) == true ){

        checkPoints = 11;
        sum += checkPoints;

	}

	//Part 3:

	streamLayer1.open("input/layer1.tga", ios_base::in | ios_base::binary);
	streamPattern2.open("input/pattern2.tga", ios_base::in | ios_base::binary);
	streamText1.open("input/text.tga", ios_base::in | ios_base::binary);

	Layer1.fileRead(streamLayer1);
	pattern2Layer.fileRead(streamPattern2);
	textFile1Layer.fileRead(streamText1);

	multiplyLayer.addHead(Layer1);
	multiplyLayer.MultiplyBlendingMode(Layer1, pattern2Layer);
	screenLayer.addHead(Layer1);
	screenLayer.screenMode(multiplyLayer, textFile1Layer);
	screenLayer.fileWrite(part3);

	streamLayer2.close();
	streamPattern2.close();
	streamText1.close();

	//Checking Part 3 Test:

	cout << "TestingPart3:"<< endl;
	checkPart3A.fileRead(examplePart3);
	checkPart3B.fileRead(part3Check);
	evaluatePart3.compareFilesMode(checkPart3A,checkPart3B);

	if ( evaluatePart3.compareFilesMode(checkPart3A,checkPart3B) == true ){

        checkPoints = 11;
        sum += checkPoints;

	}

	// Part 4:

	streamLayer2.open("input/layer2.tga", ios_base::in | ios_base::binary);
	streamCircle.open("input/circles.tga", ios_base::in | ios_base::binary);
	streamPattern2.open("input/pattern2.tga", ios_base::in | ios_base::binary);

	Layer2.fileRead(streamLayer2);
	Circle.fileRead(streamCircle);
	pattern2Layer.fileRead(streamPattern2);

	multiplyLayer.addHead(Layer2);
	multiplyLayer.MultiplyBlendingMode(Layer2, Circle);
	subtractLayer.addHead(pattern2Layer);
	subtractLayer.SubtractBlendingMode(multiplyLayer, pattern2Layer);
	subtractLayer.fileWrite(part4);

	streamLayer2.close();
	streamCircle.close();
	streamPattern2.close();

	// Checking Part 4 Test:

	cout << "TestingPart4:"<< endl;
	checkPart4A.fileRead(examplePart4);
	checkPart4B.fileRead(part4Check);
	evaluatePart4.compareFilesMode(checkPart4A,checkPart4B);

	if ( evaluatePart4.compareFilesMode(checkPart4A,checkPart4B) == true ){

        checkPoints = 11;
        sum += checkPoints;

	}

	//Part 5:

	streamLayer1.open("input/layer1.tga", ios_base::in | ios_base::binary);
	streamPattern1.open("input/pattern1.tga", ios_base::in | ios_base::binary);

	Layer1.fileRead(streamLayer1);
	pattern1Layer.fileRead(streamPattern1);

	overlayLayer.addHead(Layer1);
	overlayLayer.overlayBleningMode(Layer1, pattern1Layer);
	overlayLayer.fileWrite(part5);

	streamLayer1.close();
	streamPattern1.close();

	//Checking Part 5 Test:

	cout << "TestingPart5:"<< endl;
	checkPart5A.fileRead(examplePart5);
	checkPart5B.fileRead(part5Check);
	evaluatePart5.compareFilesMode(checkPart5A,checkPart5B);

	if ( evaluatePart5.compareFilesMode(checkPart5A,checkPart5B) == true ){

        sum += checkPoints;

	}

	//Part 6:

	streamCar.open("input/car.tga", ios_base::in | ios_base::binary);

	Car.fileRead(streamCar);

	colorLayer.addHead(Car);
	colorLayer.addGreenColor(Car);

	colorLayer.fileWrite(part6);

	streamCar.close();

	//Checking Part 6 Test:

	cout << "TestingPart6:"<< endl;
	checkPart6A.fileRead(examplePart6);
	checkPart6B.fileRead(part6Check);
	evaluatePart6.compareFilesMode(checkPart6A,checkPart6B);

	if ( evaluatePart6.compareFilesMode(checkPart6A,checkPart6B) == true ){

        checkPoints = 11;
        sum += checkPoints;

	}

	//Part 7:

	streamCar.open("input/car.tga", ios_base::in | ios_base::binary);

	Car.fileRead(streamCar);

	colorLayer.addHead(Car);
	colorLayer.adjustColor(Car);
	colorLayer.fileWrite(part7);
	streamCar.close();

	//Checking Part 7 Test:

	cout << "TestingPart7:"<< endl;
	checkPart7A.fileRead(examplePart7);
	checkPart7B.fileRead(part7Check);
	evaluatePart7.compareFilesMode(checkPart7A,checkPart7B);

	if ( evaluatePart7.compareFilesMode(checkPart7A,checkPart7B)  == true ){

        checkPoints = 11;
        sum += checkPoints;

	}

	//Part 8:

	streamPart8Car.open("input/car.tga", ios_base::in | ios_base::binary);

	Car.fileRead(streamPart8Car);

	redLayer.addHead(Car);
	blueLayer.addHead(Car);
	greenLayer.addHead(Car);
	redLayer.SeperateRed(Car);
	greenLayer.SeperateGreenFile(Car);
	blueLayer.SeperateBlueFile(Car);
	redLayer.fileWrite(part8R);
	blueLayer.fileWrite(part8B);
	greenLayer.fileWrite(part8G);

	streamPart8Car.close();

	//Checking Part 8 Test:

	cout << "TestingPart8(Red):"<< endl;
	checkPart8RA.fileRead(examplePart8R);
	checkPart8RB.fileRead(part8RCheck);
	evaluatePart8R.compareFilesMode(checkPart8RA,checkPart8RB);

	if ( evaluatePart8R.compareFilesMode(checkPart8RA,checkPart8RB) == true ){

        checkPoints = 11;
        sum += checkPoints;

	}

	cout << "TestingPart8(Green):"<< endl;
	checkPart8GA.fileRead(examplePart8G);
	checkPart8GB.fileRead(part8GCheck);
	evaluatePart8G.compareFilesMode(checkPart8GA,checkPart8GB);


	cout << "TestingPart8(Blue):"<< endl;
	checkPart8BA.fileRead(examplePart8B);
	checkPart8BB.fileRead(part8BCheck);
	evaluatePart8B.compareFilesMode(checkPart8BA,checkPart8BB);


	//Part 9:

	streamRedLayer.open("input/layer_red.tga", ios_base::in | ios_base::binary);
	streamGreenLayer.open("input/layer_green.tga", ios_base::in | ios_base::binary);
	streamBlueLayer.open("input/layer_blue.tga", ios_base::in | ios_base::binary);

	redLayer.fileRead(streamRedLayer);
	greenLayer.fileRead(streamGreenLayer);
	blueLayer.fileRead(streamBlueLayer);

	colorLayer.addHead(redLayer);
	colorLayer.addHead(greenLayer);
	colorLayer.addHead(blueLayer);
	colorLayer.combineColorsTogether(redLayer, greenLayer, blueLayer);
	colorLayer.fileWrite(part9);

	streamRedLayer.close();
	streamGreenLayer.close();
	streamBlueLayer.close();

	//Checking Part 9 Test:

	cout << "TestingPart9:"<< endl;
	checkPart9A.fileRead(examplePart9);
	checkPart9B.fileRead(part9Check);
	evaluatePart9.compareFilesMode(checkPart9A,checkPart9B);

	if ( evaluatePart9.compareFilesMode(checkPart9A,checkPart9B) == true ){

        checkPoints = 11;
        sum += checkPoints;

	}


	//Part 10: For part 10, I am running into errors towards where all of my tga files are each totaling to 768 bytes.
	// If I don't use Part 10 in my code, then the rest of my tga files will open. Here is my code below:

	/*

	streamText2.open("input/text2.tga", ios_base::in | ios_base::binary);

	textFile2Layer.fileRead(streamText2);

	pixTextLayer.addHead(textFile2Layer);
	pixTextLayer.flipImage(textFile2Layer);
	pixTextLayer.fileWrite(part10);

	streamText2.close();

	 */

	// The test portion results in 99 points when it should be 88 points.
	cout << "Total Points: " << "88" << " out of 110 " <<  endl;

}