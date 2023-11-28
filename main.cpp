#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ranges>

class Movie{
public:
    typedef enum {
        MovieType_Film,
        MovieType_Tv
    }MovieType;

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
        Movie("The Mummy returns",2001,Movie::MovieType::MovieType_Film,109),
        Movie("Fast and Furious 7",2014,Movie::MovieType::MovieType_Film,99),
        Movie("Fast & Furious Presents: Hobbs & Shaw",2019,Movie::MovieType::MovieType_Film,88),
        Movie("Star Trek: Voyager",2000,Movie::MovieType::MovieType_Tv,200),
       Movie("Young Rock",2021,Movie::MovieType::MovieType_Tv,82),
    };

    // PS WHAT DOES []() mean! We will look into that later ! we can capture variables from outer scope

    //any_of

    // SORT

    //Filter all costing less than a certain price - iterating many

    // FUNCTOR!

    //Templates

    //Ranges



    int total = std::accumulate(std::begin(greatMovies),std::end(greatMovies),0,[](int sum, const Movie &m){
        return sum + m.getPrice();
    });


    int countMoviesLaterThan2015  = std::count_if(std::begin(greatMovies),std::end(greatMovies),[](const Movie &m){
        return m.getYear() > 2015;
    });

    

    // // total all years 2001+2014+2019+2000+2021
    // int total  = 0;
    // for (auto v: greatMovies) {
    //     total += v.getYear();
    // }        

    
    // int countMoviesLaterThan2015  = 0;
    // for (auto v: greatMovies) {
    //     if(v.getYear() > 2015){
    //         countMoviesLaterThan2015++;
    //     }
    // }        




    std::for_each(std::begin(greatMovies),std::end(greatMovies),[](auto const &m){
        std::cout << m.getName() << std::endl;
    });

    // std::for_each(std::rbegin(greatMovies),std::rend(greatMovies),[](auto const &m){
    //     std::cout << m.getName() << std::endl;
    // });

     for (auto v: greatMovies) {
        std::cout << v.getName() << " ";
     }    
    // int total = 0;
    // for(int i = 0; i < greatMovies.size(); i++){
    //     total += greatMovies[i].getYear();
    //     if(i == 2){
    //         break;
    //     }
    //     std::cout << greatMovies[i].getName() << std::endl;
    // }




}