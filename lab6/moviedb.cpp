//moviedb.cpp
// Alyssa Rose

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Movie{
  string title;
  int year;
  int gross;
  string director;
  string actors[5];

};
void fill_movie_array(Movie movies[]);
void movie_list(Movie movies[]);
void get_act(Movie movies[]);
int big_year(Movie movies[]);
int main()
{
  Movie movies[450];
  fill_movie_array(movies);
  movie_list(movies);
  
  int low = movies[0].gross;
  int high = movies[0].gross;
  double avg = 0.0;
  for(int i = 0; i < 450; i++){
    if(movies[i].gross < low)
      low = movies[i].gross;
    if(movies[i].gross > high)
      high = movies[i].gross;
    avg = avg + movies[i].gross;
	
  }
  avg = avg / 450;
  cout << "Average: "<< avg << endl;
  cout << "Lowest Grossing: " << low << endl;
  cout << "Highest Grossing: " << high << endl;

  get_act(movies);
  big_year(movies);
  return 0;
}
  


void fill_movie_array(Movie movies[]){
  ifstream in;
  string temp;
  in.open("moviedata.txt");
  for (int i = 0; i < 450; i++){
    getline(in, movies[i].title);
    cout << movies[i].title << endl;
    in >> movies[i].year;
    in >> movies[i].gross;
    getline(in, temp);
    getline(in, movies[i].director);
    for (int j = 0; j < 5; j++){
      getline(in, movies[i].actors[j]);
    }
  }
  in.close();
}

void movie_list(Movie movies[]){
  int yr;
  cout << "What year? ";
  cin >> yr;
  for (int i = 0; i < 450; i++){
    if(movies[i].year == yr)
      cout << movies[i].title << endl;
  }
}


void get_act(Movie movies[]){
  string name, temp;
  cout << "Enter name of actor/actress ";
  getline(cin, temp);
  getline(cin, name);
  for(int i = 0; i < 450 ; i++){
    for(int j = 0; j < 5; j++){
      if(name == movies[i].actors[j])
        cout << movies[i].title << endl;
    }
  }
}

int big_year(Movie movies[]){
  double gross_yr[119];
  int i = 0;
  while (i < 119){
    for (int j = 0; j < 450; j++){
      if (movies[j].year == (i + 1900)){
        gross_yr[i] += movies[j].gross;
      }
    }
    i++;
  }
  double gross_max = gross_yr[0];
  int max_yr = 0;
  for (int i = 0; i < 119; i++){
    if (gross_yr[i] > gross_max){
      gross_max = gross_yr[i];
      max_yr = i + 1900;
    }

  }
  cout << max_yr << endl;
  return max_yr;
}



