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
    };


    //int j=12;

    //  Loopa igenom alla - C/C++
    // jag behöver i:et
    // PLUS - vana
    // MINUS - lätt att göra fel
    // MINUS - "sämre semantik"  - while(true)
    for(int i = 0; i < greatMovies.size(); i++){
        Movie m = greatMovies[i];
        std::cout << m.getName() << std::endl;
    }
    // vs for each BARA C++
    // Alla algoritmer tar 
    //         1. en start
    //         2. en slut
    //         3. en lambda - en funktion att applicera på alla element mellan start och slut
    
    // BÄTTRE SEMANTIK - for varje
    // MÖJLIGT MED BÄTTRE PRESTANDA! - parallellism
    // MÖJLIGT MED BÄTTRE PRESTANDA! - EXPERTER -> Assembler-kod

    // openssl - hash uis743289jkwfe342dfkslö890
    // färdig källkod cpp
    // openssl.h  -> 20% snabbare   ASM
    std::for_each( std::begin(greatMovies),std::end(greatMovies),[](const Movie &m){
        std::cout << m.getName() << std::endl;
    } );
    // vs auto : 
    // BÄTTRE SEMANTIK - for varje - möjligt att breaka
    for(Movie m : greatMovies){
        std::cout << m.getName() << std::endl;
    }

    // hur många filmer kostar mer än 70 kr
    // count 
    //  std::count( std::begin(greatMovies),std::end(greatMovies),3 )
    // any of
    // std::any_of( std::begin(greatMovies),std::end(greatMovies),3 )
    // sort
    // find_if
    // filter - ta fram alla som kostar minst X kr.. NÄSTA TORSDAG = ranges

    // int total = 0;
    // for(int i = 0; i < greatMovies.size(); i++){
    //     total += greatMovies[i].getYear();
    //     if(i == 2){
    //         break;
    //     }
    //     std::cout << greatMovies[i].getName() << std::endl;
    // }




}