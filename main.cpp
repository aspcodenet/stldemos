#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>

class Movie{
public:
    typedef enum {
        MovieType_Film,
        MovieType_Tv
    }MovieType;

    Movie(std::string name, int year,MovieType type)
    :name(name),year(year),type(type){
    }
    std::string getName() const{
        return name;
    }
    int getYear() const{
        return year;
    }
    MovieType getMovieType() const{
        return type;
    }
private:
    std::string name;
    MovieType type;
    int year;
};



int main(){
    std::vector<Movie> greatMovies{
        Movie("The Mummy returns",2001,Movie::MovieType::MovieType_Film),
        Movie("Fast and Furious 7",2014,Movie::MovieType::MovieType_Film),
        Movie("Fast & Furious Presents: Hobbs & Shaw",2019,Movie::MovieType::MovieType_Film),
        Movie("Star Trek: Voyager",2000,Movie::MovieType::MovieType_Tv),
        Movie("Young Rock",2021,Movie::MovieType::MovieType_Tv),
    };


}