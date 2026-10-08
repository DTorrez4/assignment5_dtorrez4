#include <iostream>
#include <fstream>
#include<vector>
#include<string>
#include "pixel.h" //this is the header file that i made.

//made sure to include the name space to not put std:: alot
using namespace std;

//prototyping my functions to put under main.
void average_colors(vector<Pixel> &pixel_list);
void flip_Vertical(vector<Pixel> &pixel_list);


int main(int argc,char *argv[]){

    if (argc < 2) {
        cerr <<"useage :" << argv[0] << "<filename>" << endl;
        return 1;
    }

    //this is how i get the file name from the user.
    string filename = argv[1];
    ifstream input_file(filename);

    //checks if the file cannot be open.
    if (!input_file.is_open()) {
        cerr << "Error opening file " << filename << endl;
        return 1;
    }

    //this is creating the vector to hold the .dat data.
    vector<Pixel> pixel_list;
    string line;

    //this is a while loop for reading the dat file , and assigning values to them.

    /*  i chosed this way for parsing the information because i thought it was easy going value
     *  by value from the text from the dat file. since im using stoi and stof it ignores the white
     *  space.also it helps with finding out if there is anything wrong with the program.
     *  lastly it uses the strings like .find() and .Substring which is useful parsing through
     *  a document that is text.
     *  */

    while (getline(input_file, line)) {
        //checks if its empty.
        if (line.empty()) {
            continue;
        }

        //this just helps with the sizes and indexing for the string functions so i can use it
        //while parsing through the data.
        size_t start = 0;
        size_t end = line.find(",");

        //gets the x val.
        int x = stoi(line.substr(start, end - start));

        //gets the y val
        start = end + 1;
        end = line.find(",", start);
        int y = stoi(line.substr(start, end - start));

        //gets the r val
        start = end + 1;
        end = line.find(",", start);
        float r = stof(line.substr(start, end - start));

        //gets the g val
        start = end + 1;
        end = line.find(",", start);
        float g = stof(line.substr(start, end - start));

        //gets the b val
        start = end + 1;
        float b = stof(line.substr(start, end - start));

        Pixel pixel;

        //putting values into the pixel.h struct.
        pixel.x = x;
        pixel.y = y;
        pixel.r = r;
        pixel.g = g;
        pixel.b = b;

        //helps with allocating more space just in case.
        pixel_list.push_back(pixel);
    }

    input_file.close();

    cout <<"read is Succsesfull " << pixel_list.size() << "pixels " << endl;

    //this prints out the average colors by calling on the function.
    cout << "AVERAGE COLORS" << endl;
    average_colors(pixel_list);

    //this calls on the function to flip it.
    flip_Vertical(pixel_list);

    //this makes the file that stores the flipped data.
    ofstream output_file("flipped.dat");

    //checks if the file did not make or open.
    if (!output_file.is_open()) {
        cerr << "Error making flipped.dat file :( " << filename << endl;
        return 1;
    }

    // this puts the flipped information on the flipped.dat file
    for (Pixel &p: pixel_list) {
        output_file << p.x << " " << p.y << " " << p.r << " " << p.g << p.b << endl;
    }

    //Closes the file.
    output_file.close();
    cout << "the flipped pixel data has been success for the filpped.dat file" << endl;

    return 0;
}

//this function takes the average of the three seperate color r,g,b
void average_colors(vector<Pixel> &pixel_list) {
    //checks incase the pixel list is empty.
    if (pixel_list.empty()) {
        cout << "Pixel list is empty" << endl;
        return;
    }
    //initalizing values.
    double sum_r = 0;
    double sum_g = 0;
    double sum_b = 0;

    // thie ":" means in range of the list so it loops through the list of values.
    for ( Pixel &p : pixel_list) {

        //this adds the values to the Pixel.
        sum_r += p.r;
        sum_g += p.g;
        sum_b += p.b;
    }

    //this is where i print out the averages for the R,G,B
    size_t count = pixel_list.size();
    cout << "avg of RED: " << (sum_r / count) << endl;
    cout << "avg of GREEN: " << (sum_g / count) << endl;
    cout << "avg of BLUE: " << (sum_b / count) << endl;
    //testing stuff
    cout<<"this is the sum of it for testing"<< endl;
    cout << count << endl;
    cout << sum_r << " " << sum_g << " " << sum_b << endl;
}

//this is the function that flips the file verticaly.
void flip_Vertical(vector<Pixel> &pixel_list) {

    //this is the max height. made it a const because you dont need to change it
    const int Max_Y = 255;

    for (Pixel &p : pixel_list) {
        //this is how i flip it.

        p.y = Max_Y - p.y;

    }
}