// main.cpp
// Malinen, Leo
// ldmalinen

#include <iostream>
using namespace std;
#include "video.h"
#include "vlist.h"

int main() {
  string title = "", url = "", comment = ""; // Variables for getline and cin
  int rating = 0, video_count = 0, listcounter = 0;
  double length = 0;
  Vlist list; // linkedlist variable
  const int MAX = 100;
  Video *videos[MAX] = {NULL};
  string inputType; // sorting input
  while (getline(cin, inputType)) {
    for (int i = video_count - 1; i >= 0; i--) {
      for (int j = 0; j <= i; j++) {
        if ((videos[j] != NULL && videos[j + 1] != NULL &&
             videos[j]->titles() > videos[j + 1]->titles()) ||
            (videos[j + 1] != NULL && videos[j] == NULL)) {
          swap(videos[j], videos[j + 1]);
        }
      }
    }
    if (inputType == "insert") {    //insert function to insert in
      getline(cin, title);
      getline(cin, url);
      getline(cin, comment);
      cin >> length;
      cin >> rating;
      cin.ignore();
      videos[video_count] = new Video(title, url, comment, length, rating);
      list.insert(listcounter);
      if (video_count > 99) {
        cerr << "Too many videos, giving up." << endl;
        return 1;
        break;
      } else {
        video_count++;
        listcounter++;
      }
      if (video_count >= 2) {
        for (int i = video_count - 1; i > 0; i--) {
          if (videos[i] != NULL && videos[i - 1] != NULL &&
              videos[i]->titles() == videos[i - 1]->titles()) {
            cerr << "Title already in list." << endl;
            delete videos[i];
            video_count--;
          }
        }
      }
    } else if (inputType == "print") { //print function to print the list
      for (int i = 0; i < video_count; i++) {
        if (videos[i] != NULL) {
          (**(videos + i)).print();
        }
      }
    } else if (inputType == "length") { //length function to display the length
      cout << video_count << endl;
    } else if (inputType == "lookup") { //lookup by inputting titles
      string lookupTitle;
      getline(cin, lookupTitle);
      for (int i = video_count - 1; i >= 0; i--) {
        if (videos[i] != NULL && lookupTitle == videos[i]->titles()) {
          (**(videos + i)).print();
          i = 0;
        } else if (videos[i] != NULL && lookupTitle != videos[i]->titles() &&
                   i == 0) {
          cerr << "Title "
               << "<" << lookupTitle << ">"
               << " not in list." << endl;
        }
      }
    }
    else if (inputType == "remove") {    // remove function to remove items
      string removeTitle;
      getline(cin, removeTitle);
      if (video_count == 0) {
        cerr << "Title "
             << "<" << removeTitle << ">"
             << " not in list, could not delete." << endl;
      } else {
        for (int i = video_count - 1; i >= 0; i--) {
          if (videos[i] != NULL && removeTitle == videos[i]->titles()) {
            delete videos[i];
            videos[i] = NULL;
            video_count--;
            i = 0;
          } else if (videos[i] != NULL && removeTitle != videos[i]->titles() &&
                     i == 0) {
            cerr << "Title "
                 << "<" << removeTitle << ">"
                 << " not in list, could not delete." << endl;
          }
        }
      }
    }
    else {
      cerr << "<" << inputType << ">"
           << " is not a legal command, giving up." << endl;
      return 1;
    }
  }
  // delete everything in videos after function has ended
  for (int i = 0; i < video_count; i++) {
    delete videos[i];
  }
  return 0;
}
