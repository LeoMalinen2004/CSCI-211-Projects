// video.cpp
// Malinen, Leo
// ldmalinen

#include "video.h"
#include <iostream>
using namespace std;

//Class constructor
Video::Video(string title, string url, string comment, double length, int rating) {
  m_title = title;
  m_url = url;
  m_comment = comment;
  m_length = length;
  m_rating = rating;
}


//Print function that prints the array of pointers in order
//Rating turns into asterisks via the if statements below
void Video::print() {
  string asterisks = " ";
  if (m_rating == 1) {
    asterisks = "*";
  } else if (m_rating == 2) {
    asterisks = "**";
  } else if (m_rating == 3) {
    asterisks = "***";
  } else if (m_rating == 4) {
    asterisks = "****";
  } else if (m_rating == 5) {
    asterisks = "*****";
  }
  cout << m_title << ", "<< m_url << ", " << m_comment << ", " << m_length << ", " << asterisks << endl;
}

//All three functions below return the private variable to be public use
string Video::titles(){
  return m_title;
}
double Video::lengths(){
  return m_length;
}
int Video::rating(){
  return m_rating;
}
