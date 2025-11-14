#include "media.h"
#include <string>
#include <vector>

class Song : public Media{

    public:
        Song(std::string name, long duration, Rating rating, std::vector<std::string> genres){
            this->name = name;
            this->duration = duration;
            this->rating = rating;
            this->genres = genres;
        }
        
        std::string getName(){
            return name;
        }

        long getDuration(){
            return duration;
        }

        Rating getRating(){
            return rating;
        }

        std::vector<std::string> getGenres(){
            return genres;
        }
        

}