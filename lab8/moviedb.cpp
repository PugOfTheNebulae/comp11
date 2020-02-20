#include <iostream>
#include <fstream>

using namespace std;

// -- Introduce the Actor struct, just so we can use it in the Movie struct
struct Actor;

// -- Struct to hold data for one movie. Initially, the actors will be stored as
//    an array of names, but then we'll look up the names and point to Actor
//    structs.
struct Movie
{
  string title;
  int year;
  double gross;
  string director;
  string actor_names[5];
  Actor * actors[5];
};

// -- Struct to hold data about one actor. Since we don't know how many movies
//    an actor has been in, we will leave room for 100, but keep a count of the
//    actual number.
struct Actor
{
  string name;
  int num_movies;
  Movie * movies[100];
};

/** Read a line
 *
 *  This is a version that actually works as you would expect (arg!)
 *  DON'T WORRY about how this function works.
 */
string read_line(istream& in)
{
  // -- Consume any extraneous white-space (including newline) at the end
  //    of the previous line
  char t;
  t = in.peek();
  while (isspace(t) && ! in.eof()) {
    in.ignore();
    t = in.peek();
  }
  
  // -- Now read the line
  string result;
  getline(in, result);
  return result;
}

/** Read one movie
 *
 *  Read in all the data about a single movie, store in a newly created Movie struct.
 */
Movie * read_movie(istream& file)
{
  // -- Create a new movie struct
  Movie * m = new Movie;
  
  // -- Read in the title, year, gross, and director
  m->title = read_line(file);
  file >> m->year;
  file >> m->gross;
  m->director = read_line(file);

  // -- Read in the five top-billed actors
  for (int i = 0; i < 5; i++) {
    m->actor_names[i] = read_line(file);
  }

  // -- For debugging: print out some info
  // cout << m->title << " starring " << m->actor_names[0] << endl;

  return m;
}

// Problem 1: Actor lookup

Actor *lookup_actor(string name, Actor * all_actors[], int num_actors){ 
  for(int i = 0; i < num_actors; i++){
    if(name == (all_actors[i] -> name))
      return all_actors[i];
  }
  return NULL;

}

// Problem 2: Make actor

Actor * make_actor(string name){
  Actor * act_ptr = new Actor;
  act_ptr -> name = name;
  act_ptr -> num_movies = 0;
  for(int i = 0; i < 100; i++)
    act_ptr -> movies[i] = NULL;
  return act_ptr;

}

// Problem 3: Add movie

void add_movie(Actor * actor, Movie * movie){
  actor -> movies[(actor -> num_movies) + 1] = movie;
  (actor -> num_movies)++; 

}


int main()
{
  // -- Read in the movie data
  ifstream file;
  Movie * movies[450];

  file.open("moviedata.txt");
  if ( ! file.fail()) {
    for (int i = 0; i < 450; i++) {
      movies[i] = read_movie(file);
    }
    file.close();
  } else {
    cout << "Could not open moviedata.txt" << endl;
    return -1;
  }

  // -- Problem 4: Build the database...
  Actor * all_actors[2000];
  int num_actors = 0;
  Actor * actor_ptr = NULL;
  for(int i = 0; i < 450; i++){
    for(int j = 0; j < 5; j++){
      if (lookup_actor(movies[i] -> actor_names[j] , all_actors, num_actors) == NULL){
       actor_ptr = make_actor(movies[i] -> actor_names[j]);
       all_actors[num_actors] = actor_ptr;
       num_actors++;
       add_movie(actor_ptr, movies[i]);
       (movies[i] -> actors[j]) = actor_ptr;
     }
   }
 }

 

  // -- Problem 5: Actor filmography
  //string act = read_line(cin);

  // ...PUT YOUR CODE HERE...

  // -- Problem 6: Films in common
  //string act1 = read_line(cin);
  //string act2 = read_line(cin);
  
  // ...PUT YOUR CODE HERE...

  return 0;
}
