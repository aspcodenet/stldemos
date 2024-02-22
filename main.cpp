#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ranges>


struct ChristmasWish{
    std::string Name;
    int Price;
    ChristmasWish(std::string name, int price){
        Name = name;
        Price = price;
    }        
};

class Movie{
public:
    typedef enum {
        MovieType_Film,
        MovieType_Tv
    }MovieType;

    Movie(){

    }

    Movie(std::string name, int year,MovieType type, int price)
    :name(name),year(year),type(type),price(price){
    }
    std::string getName() const{
        return name;
    }
    int getYear() const{
        return year;
    }
    int getPrice() const{
        return price;
    }
    MovieType getMovieType() const{
        return type;
    }
private:
    std::string name;
    MovieType type;
    int year;
    int price;
};


    
int main(){

    std::vector<Movie> greatMovies{
        Movie("The Mummy returns",2022,Movie::MovieType::MovieType_Film,40), // <- begin
        Movie("Fast and Furious 7",2014,Movie::MovieType::MovieType_Film,99),  // <-items
        Movie("Star Trek: Voyager",2000,Movie::MovieType::MovieType_Tv,50),
        Movie("Fast & Furious Presents: Hobbs & Shaw",2019,Movie::MovieType::MovieType_Film,88),
       Movie("Young Rock",2021,Movie::MovieType::MovieType_Tv,82),
                                                                            // -< end
    };

    // Loopa igenom alla

    // int total = 0;
    // for(int i = 0; i < greatMovies.size(); i++){
    //     total += greatMovies[i].getYear();
    //     if(i == 2){
    //         break;
    //     }
    //     std::cout << greatMovies[i].getName() << std::endl;
    // }




}