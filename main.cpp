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


    // FUNCTOR!
//class/structs SAME default access modifers
// structs DTO
struct YearFilter{
    YearFilter(int year):year(year){

    }
    bool operator()(Movie const &m){
        return m.getYear() > year;
    }

    
private:    
    int year;    
};

// DRY
//template<class T>
template<typename T>
T findBiggest(T i, T j, T k){
    if(i > j && i > k){
        return i;
    }
    if(j > i && j > k){
        return j;
    }
    return k;
}

// can I put the template declaration in a header file

template<typename T,int size>
class MyArray{
public:
    // T &getAt(int index){
    //     return things[index] ;
    // }
    // T &operator [](int index){
    //    return things[index] ;
    // }
    //void sor();
private:
    T things[size]; //
};




int main(){
    MyArray<int,15> array; // array stack allocated - 15 of those
    //int i = array.getAt(1);
    //int i = array[1];
    MyArray<Movie,100> array2; // I would need 100 of those
    MyArray<Movie,50> array21; // I would need 100 of those
    MyArray<float,3> array3; // I would need 3
    //List<T>
    //std::vector<int> a = {1,2,3};
    int a= 19;
    int b = 20;
    int c = 21;
    int biggest = findBiggest(a,b,c);

    std::string bname = findBiggest<std::string>("Stefan","Holmberg","Test");


    int biggest2 = findBiggest(a,b,c);

    std::vector<Movie> greatMovies{
        Movie("The Mummy returns",2022,Movie::MovieType::MovieType_Film,40), // <- begin
        Movie("Fast and Furious 7",2014,Movie::MovieType::MovieType_Film,99),  // <-items
        Movie("Star Trek: Voyager",2000,Movie::MovieType::MovieType_Tv,50),
        Movie("Fast & Furious Presents: Hobbs & Shaw",2019,Movie::MovieType::MovieType_Film,88),
       Movie("Young Rock",2021,Movie::MovieType::MovieType_Tv,82),
                                                                            // -< end
    };

    // result "promise" NOT EXECUTED
    auto result = greatMovies | std::views::filter([](const Movie &m){
        std::cout << "In filter" << std::endl;
        return m.getPrice() > 80;
    });

    for(auto i :result){ // until we start iterating
        std::cout << "In print" << std::endl;
        std::cout << i.getName() << std::endl;
    }





    int year;
    std::cin >> year;

    YearFilter yearFilter(year);
                                                                            // something that is callable
                                                                             // call it name ()
    bool anyLater22 = std::any_of(std::begin(greatMovies),std::end(greatMovies),yearFilter);


    //Filter all costing less than a certain price - iterating many
    // list all items costing less than 100
    //                         pointer to       

    auto i = std::begin(greatMovies),end = std::end(greatMovies);
    while(i != end){
        i = std::find_if(i,end,[](auto const &m){
            return m.getPrice() < 90;
        });
        // hello
        if(i != end){
            std::cout << i->getName() << std::endl;
            //i = std::next(i);
            i++;
        }
    }

    // strtok
    


    // PS WHAT DOES []() mean! We will look into that later ! we can capture variables from outer scope

    //any_of - is there ANY 
    //int minYear = 2021;
    bool anyLater = std::any_of(std::begin(greatMovies),std::end(greatMovies),[](const Movie &m){
         return m.getYear() > 2021;
     });
    // bool anyLater  = false;
    // for (auto v: greatMovies) {
    //     if(v.getYear() > 2021){
    //         anyLater = true;
    //         break;
    //     }
    // }        
    // int countMoviesLaterThan2021  = std::count_if(std::begin(greatMovies),std::end(greatMovies),[](const Movie &m){
    //     return m.getYear() > 2021;
    // });
    // if(countMoviesLaterThan2021>0){

    // }



    // SORT
    std::sort(std::begin(greatMovies),std::end(greatMovies),[](const Movie &item1, const Movie &item2){
        return item1.getName() < item2.getName();                
    });
    std::for_each(std::begin(greatMovies),std::end(greatMovies),[](auto const &m){
        std::cout << m.getName() << std::endl;
    });
    int t;
    t=12;
    


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