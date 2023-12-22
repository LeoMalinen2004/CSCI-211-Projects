// video.h
// Malinen, Leo
// ldmalinen

#ifndef VIDEO_h
#define VIDEO_h
#include <string>
using namespace std;

//class Video and all variables with functions below
class Video {

//public functions and constructor declaration
public:
  Video(string title, string url, string comment, double length, int rating);
  void insertStrings(string title, string url, string comment, double length, int rating);
  void print();
  void rating_sorter();
  void title_sorter();
  void length_sorter();
  string titles();
  double lengths();
  int rating();
  bool compare(Video *otherVideo);
//private variables
private:
  string m_title;
  string m_url;
  string m_comment;
  double m_length;
  int m_rating;
  string m_asterisks;
};
#endif
