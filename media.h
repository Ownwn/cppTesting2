#include <string>
#include <vector>

class Media{

    protected:
        std::string name;
        long duration;
        Rating rating;
        std::vector<std::string> genres;
    
    public:
        virtual std::string getName() = 0;
        virtual long getDuration() = 0;
        virtual Rating getRating() = 0;
        virtual std::vector<std::string> getGenres() = 0;

        void setRating(int i){
            //if(rating >10 || rating <0){return;}
            rating = i;
        }
};