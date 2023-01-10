// Section 19
// Write File
#include <iostream>
#include <fstream>
#include <string>

// TIP: we can use fstream (and not ofstream) when we need to read and write
// a file in the same program flow.

/*
 * Types of file accesses
 * - ios::out - open the file in output mode (we can only write, but not read from it)
 * - ios::trunc - truncate (discard contents) when opening
 * - ios::app - append on each write
 * - iso::ate - seek to end of file when opening, but we are free to move around the cursor
 */

/*
 * To open a file in binary mode we have to use std::ios::binary
 * Ex: std::ofstream out_file { std::ios::out | std::ios::binary }
 * '|' is the bitwise or operator
 */

int main()  {
    // by default the file will be created if it not exists
    // and if the file already exists, it will be overwritten (if not open it
    // in append mode)
    std::ofstream out_file {"../output.txt", std::ios::app};

    // check if the file was created correctly
    if (!out_file) {
        std::cerr << "Error creating file!" << std::endl;
        return 1;
    }

    // write a line in the file
    std::string line;
    std::cout << "Enter something to write to the file: ";
    std::getline(std::cin, line);
    out_file << line << std::endl;  // write a file using insertion operator
                                    // NOTE that std::endl flushes out any unwritten buffers

    // close the file to flush out any buffers
    out_file.close();
   
    return 0;
}

