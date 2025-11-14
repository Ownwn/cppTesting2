#include "media.h"
#include <string>
#include <vector>

class Game : public Media{

    public:
        Game(std::string name, long duration, std::vector<std::string> genres){
            this->name = name;
            this->duration = duration;
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
        

};